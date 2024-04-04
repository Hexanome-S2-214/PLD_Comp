#include "ir-visitor.h"
#include "ir/ir-type.h"
#include "ir/ir-cfg.h"
#include "ir/ir-type.h"
#include "ir/ir-basic-block.h"
#include "ir/params/ir-reg.h"
#include "ir/params/ir-symbol.h"                
#include "ir/params/ir-const.h"
#include "ir/params/ir-param.h"
#include "ir/instr/assign.h"
#include "ir/instr/expression_unary_minus.h"
#include "ir/instr/expression_cst.h"
#include "ir/instr/expression_var.h"
#include "ir/instr/expression_mult.h"
#include "ir/instr/expression_div.h"
#include "ir/instr/expression_plus.h"
#include "ir/instr/expression_minus.h"
#include "ir/instr/mov.h"
#include "ir/instr/assignTable.h"
#include "ir/instr/comp.h"
#include "ir/instr/set_flag_comp.h"
#include "ir/instr/expression_bit_a_bit.h"
#include "ir/instr/intr-cheat.h"
#include "ir/instr/jump.h"
#include "ir/instr/call.h"
#include "ir/instr/push.h"
#include "error-reporter/compiler-error-token.h"
#include "./error-reporter/error-reporter.h"

//detects the presence of constants in expressions
#define CONST_FLAG 1

//global to retrieve informations when expressions are evaluated
VisitorFlags vf;

////////////////////////////////////////////
// RETURN
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitReturnStmtRule(ifccParser::ReturnStmtRuleContext *ctx) {

    //detection of return inside a return-void function
    if (cfg->get_no_return()) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::WARNING, "‘return’ with a value, in function returning void", ctx)
        );
    }

    this->visit(ctx->rvalue());

    //Jump to epilogue block in any case
    string epilogue_label_cfg = cfg->get_epilogue_label();
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::Jump)
            ->set_label(epilogue_label_cfg)
            ->set_ctx(ctx)
    );

    //Disable writing in the block AFTER adding jmp instruction
    this->cfg->get_current_bb()->set_write_mode(false);

    return 0;
}

////////////////////////////////////////////
// DECLARATION/AFFECTATION
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitSimpleAff(ifccParser::SimpleAffContext *ctx)
{
    IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);
    
    if (symbol->const_var) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "'const’ value cannot be used as left-value", ctx)
        );
    }

    this->visit(ctx->rvalue());

    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(symbol)
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitSimpleDecl(ifccParser::SimpleDeclContext *ctx)
{
    IR::Type type;

    if (ctx->getTokens(ifccParser::INT).size() >= 1)
    {
        type = IR::Int;
    }
    else if (ctx->getTokens(ifccParser::CHAR).size() >= 1)
    {
        type = IR::Char;
    }
    else
    {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Unrecognized type", ctx)
        );
    }

    cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), type, ctx);

    //update flags
    vf.type_size = type.size;
    vf.f_const = false;

    return 0;
}

antlrcpp::Any IRVisitor::visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx)
{
    IR::Type type;
    bool const_var = ctx->CONST() ? true : false;

    this->visit(ctx->rvalue());

    if (ctx->getTokens(ifccParser::INT).size() >= 1)
    {
        type = IR::Int;
    }
    else if (ctx->getTokens(ifccParser::CHAR).size() >= 1)
    {
        type = IR::Char;
    }
    else
    {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Unrecognized type", ctx)
        );
    }

    IR::Symbol * symbol = cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), type, ctx, const_var);
    if (const_var) {
        symbol->set_value(vf.value);
    }

    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(symbol)
            ->set_ctx(ctx)
    );

    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = false;

    return 0;
}

antlrcpp::Any IRVisitor::visitTableDecl(ifccParser::TableDeclContext *ctx)
{
    if(ctx->CHAR()){
        cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Char, ctx, false, stoi(ctx->NUM()->getText()));
    } else if (ctx->INT()) {
        cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Int, ctx, false, stoi(ctx->NUM()->getText()));
    }
    return 0;
}

// antlrcpp::Any IRVisitor::visitSimpleAff(ifccParser::SimpleAffContext *ctx)
// {
//     this->visit(ctx->rvalue());

//     IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);

    

antlrcpp::Any IRVisitor::visitAffectationRule2(ifccParser::AffectationRule2Context *ctx)
{

    IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);

    if (symbol->const_var) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "const’ value cannot be used as left-value", ctx)
        );
    }

    this->visit(ctx->rvalue());

    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(symbol)
            ->set_ctx(ctx)
    );

    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = false;

    return 0;
}

antlrcpp::Any IRVisitor::visitExprTable(ifccParser::ExprTableContext *ctx)
{
    IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);
    int offset = stoi(ctx->NUM()->getText());

    cfg->add_instr(
    (new IR::IRInstrMov)
        ->set_src(new IR::SymbolT(offset, symbol))
        ->set_dest(new IR::IRRegA)
        ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitTableAff(ifccParser::TableAffContext *ctx)
{
    this->visit(ctx->rvalue());
    IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);
    int index = stoi(ctx->NUM()->getText());
    //TODO: Do we really need to allocate memory here ?
    IR::SymbolT* symbolT = new IR::SymbolT(index, symbol);
    cfg->add_instr(
        (new IR::IRInstrAssignTable(stoi(ctx->NUM()->getText())))
            ->set_symbol(symbolT)
            ->set_ctx(ctx)
    );

    return 0;
}

////////////////////////////////////////////
// EXPRESSIONS TERMINALES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprCharacter(ifccParser::ExprCharacterContext *ctx){
    std::string text = ctx->CHARACTER()->getText();
    if (!text.empty())
    {
        int ascii_value = static_cast<int>(text[1]);
        cfg->add_instr(
            (new IR::IRInstrExprCst)
                ->set_value(
                    (new IR::IRConst)
                        ->set_literal(to_string(ascii_value))
                        ->set_size(IR::Char.size)
                    )
                ->set_ctx(ctx)
        );

        //update flags
        vf.type_size = IR::Char.size;
        vf.f_const = true;
        vf.value = ascii_value;
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitExprNum(ifccParser::ExprNumContext *ctx){
    cfg->add_instr(
        (new IR::IRInstrExprCst)
            ->set_value(
                (new IR::IRConst)
                    ->set_literal(ctx->NUM()->getText())
                    ->set_size(IR::Int.size)
            )
            ->set_ctx(ctx)
    );

    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = true;
    vf.value = stoi(ctx->NUM()->getText());

    return 0;
}

antlrcpp::Any IRVisitor::visitExprVar(ifccParser::ExprVarContext *ctx)
{
    IR::Symbol *var = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);
    cfg->add_instr(
        (new IR::IRInstrExprVar)
            ->set_symbol(
                var)
            ->set_ctx(ctx)
    );

    //update flags
    vf.type_size = var->type.size;
    vf.f_const = var->const_var;
    if (var->const_var) {
        vf.value = var->value;
    }

    return 0;
}

////////////////////////////////////////////
// OPERATIONS ARITHMETIQUES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprSumSous(ifccParser::ExprSumSousContext *ctx) {

    bool const_left; bool const_right;
    int val_left; int val_right;

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );

    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    int final_value;

    if (const_left && const_right) {
        //If both values are identified as const values, we remove the last instructions and replace with a mov to %eax
        cfg->get_current_bb()->remove_last_instructions(3);

        if (ctx->op_add->getText() == "+")
        {
            final_value = val_left + val_right;
        } else {
            final_value = val_left - val_right;
        }

        cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(
                (new IR::IRConst)
                    ->set_literal(to_string(final_value))
                    ->set_size(IR::Int.size)
            )
            ->set_dest(new IR::IRRegA)
            ->set_ctx(ctx)
        );

    } else {
        if (ctx->op_add->getText() == "+")
        {
            cfg->add_instr(
                (new IR::IRInstrExprPlus)
                    ->set_src(varTemp)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        else if (ctx->op_add->getText() == "-")
        {
            cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(new IR::IRRegB)
                ->set_ctx(ctx)
            );
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(varTemp)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
            cfg->add_instr(
                (new IR::IRInstrExprMinus)
                    ->set_src(new IR::IRRegB)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        else
        {
            this->cfg->get_error_reporter()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Unrecognized operator", ctx)
            );
        }
    }

    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitExprMultDivMod(ifccParser::ExprMultDivModContext *ctx)
{
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (val_right == 0 && (ctx->OP_MULT()->getText() == "/" || ctx->OP_MULT()->getText() == "%")) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::WARNING, "division by 0", ctx)
        );
    }

    if (const_left && const_right) {

        cfg->get_current_bb()->remove_last_instructions(3);

        if (ctx->OP_MULT()->getText() == "*")
        {
            final_value = val_left * val_right;

        }
        else if (ctx->OP_MULT()->getText() == "/")
        {
            final_value = val_left / val_right;
        }
        else if (ctx->OP_MULT()->getText() == "%") {
            final_value = val_left % val_right;
        }

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );
        
    } else {

        if (ctx->OP_MULT()->getText() == "*")
        {
            cfg->add_instr(
                (new IR::IRInstrExprMult)
                    ->set_src(varTemp)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        else if (ctx->OP_MULT()->getText() == "/" || ctx->OP_MULT()->getText() == "%")
        {
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(new IR::IRRegA)
                    ->set_dest(new IR::IRRegB)
                    ->set_ctx(ctx)
            );

            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(varTemp)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );

            cfg->add_instr(
                (new IR::IRInstrExprDiv)
                    ->set_ctx(ctx)
            );

            if (ctx->OP_MULT()->getText() == "%")
            {
                //Modulo : il faut mettre EDX dans EAX -> c'est ce registre qui contient le reste après idivl
                cfg->add_instr(
                    (new IR::IRInstrMov)
                        ->set_src(new IR::IRRegD)
                        ->set_dest(new IR::IRRegA)
                        ->set_ctx(ctx)
                );
            }
        }
    }

    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

////////////////////////////////////////////
// OPERATEURS UNAIRES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprUnary(ifccParser::ExprUnaryContext *ctx)
{
    bool const_flag;
    int val;

    this->visit(ctx->expr());
    const_flag = vf.f_const;
    val = vf.value;

    int final_value;

    if (const_flag){

        cfg->get_current_bb()->remove_last_instructions(1);

        if (ctx->op_unary->getText() == "-") {
            final_value = -val;
        } else {
            final_value = !val;
        }

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        if (ctx->op_unary->getText() == "-") {
            cfg->add_instr(
                (new IR::IRInstrExprUnaryMinus)
                    ->set_ctx(ctx)
            );
        }
        else {
            //comparaison EAX (droite) et ECX (gauche)
            cfg->add_instr(
                (new IR::IRInstrComp)
                    ->set_src(
                        (new IR::IRConst)->set_literal("0")
                    )
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
            //résultat de la comparaison dans EAX
            cfg->add_instr(
                (new IR::IRInstrSetFlagComp)
                    ->set_op(ctx->op_unary->getText())
                    ->set_dest(
                        (new IR::IRRegA)->set_size(IR::Byte)
                    )
                    ->set_ctx(ctx)
            );
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(
                        (new IR::IRRegA)
                            ->set_size(IR::Byte)
                    )
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = const_flag;
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

////////////////////////////////////////////
// COMPARAISONS
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprEqComparaison(ifccParser::ExprEqComparaisonContext *ctx)
{
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    //évaluation à gauche
    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    //on stocke dans ECX
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(new IR::IRRegA)
            ->set_dest(new IR::IRRegC)
            ->set_ctx(ctx)
    );

    //évaluation à droite
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (const_left && const_right) {

        cfg->get_current_bb()->remove_last_instructions(3);

        if (ctx->EQ_COMPARAISON()->getText() == "==") {
            final_value = (val_left == val_right);
        } else if (ctx->EQ_COMPARAISON()->getText() == "!=") {
            final_value = (val_left != val_right);
        }

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        //comparaison EAX (droite) et ECX (gauche)
        cfg->add_instr(
            (new IR::IRInstrComp)
                ->set_src(new IR::IRRegA)
                ->set_dest(new IR::IRRegC)
                ->set_ctx(ctx)
        );

        //résultat de la comparaison dans EAX
        cfg->add_instr(
            (new IR::IRInstrSetFlagComp)
                ->set_op(ctx->EQ_COMPARAISON()->getText())
                ->set_dest(
                    (new IR::IRRegA)->set_size(IR::Byte)
                )
                ->set_ctx(ctx)
        );

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRRegA)
                        ->set_size(IR::Byte)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );
    }

    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitExprComparaison(ifccParser::ExprComparaisonContext *ctx) {

    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;
    IR::Size res_size = IR::Int.size;

    // évaluation à gauche
    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;
    IR::Size leftSize = vf.type_size;

    //on stocke dans ECX
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(
                (new IR::IRRegA)
                    ->set_size(leftSize)
            )
            ->set_dest(
                (new IR::IRRegC)
                    ->set_size(leftSize)
            )
            ->set_ctx(ctx)
    );

    //évaluation à droite
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;
    IR::Size rightSize = vf.type_size;
    res_size = min(leftSize, rightSize);

    if (const_left && const_right) {

        cfg->get_current_bb()->remove_last_instructions(3);

        if (ctx->COMPARAISON()->getText() == "<") {
            final_value = (val_left < val_right);
        } else if (ctx->COMPARAISON()->getText() == ">") {
            final_value = (val_left > val_right);
        } else if (ctx->COMPARAISON()->getText() == "<=") {
            final_value = (val_left <= val_right);
        } else if (ctx->COMPARAISON()->getText() == ">=") {
            final_value = (val_left >= val_right);
        }

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        cfg->add_instr(
            (new IR::IRInstrComp)
                ->set_src(
                    (new IR::IRRegA)
                        ->set_size(res_size)
                )
                ->set_dest(
                    (new IR::IRRegC)
                        ->set_size(res_size)
                )
                ->set_ctx(ctx)
        );

        //résultat de la comparaison dans EAX
        cfg->add_instr(
            (new IR::IRInstrSetFlagComp)
                ->set_op(ctx->COMPARAISON()->getText())
                ->set_dest(
                    (new IR::IRRegA)
                        ->set_size(IR::Byte)
                )
                ->set_ctx(ctx)
        );

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRRegA)
                        ->set_size(IR::Byte)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );
    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

////////////////////////////////////////////
// OPERATEURS BIT-A-BIT
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprAndBAB(ifccParser::ExprAndBABContext *ctx)
{
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (const_left && const_right) {
        
        cfg->get_current_bb()->remove_last_instructions(3);

        final_value = val_left & val_right;

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        cfg->add_instr(
            (new IR::IRInstrExprBitABit)
                ->set_src(varTemp)
                ->set_dest(new IR::IRRegA)
                ->set_op(ctx->B_AND()->getText())
                ->set_ctx(ctx)
        );

    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitExprXorBAB(ifccParser::ExprXorBABContext *ctx)
{
    
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (const_left && const_right) {
        
        cfg->get_current_bb()->remove_last_instructions(3);

        final_value = val_left ^ val_right;

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {


    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp)
            ->set_dest(new IR::IRRegA)
            ->set_op(ctx->B_XOR()->getText())
            ->set_ctx(ctx)
    );

    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitExprOrBAB(ifccParser::ExprOrBABContext *ctx)
{
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (const_left && const_right) {
        
        cfg->get_current_bb()->remove_last_instructions(3);

        final_value = val_left | val_right;

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        cfg->add_instr(
            (new IR::IRInstrExprBitABit)
                ->set_src(varTemp)
                ->set_dest(new IR::IRRegA)
                ->set_op(ctx->B_OR()->getText())
                ->set_ctx(ctx)
        );

    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

////////////////////////////////////////////
// OPERATEURS PARESSEUX
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprAnd(ifccParser::ExprAndContext *ctx) {

    //equivalent to : if first expr is false then return false, else return value of second expr
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    string first_expr_false_label = cfg->get_next_bb_label();
    string end_label = cfg->get_next_bb_label();

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    //if false -> jump to the block which moves $0 into %eax
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfNotEqual)
            ->set_label(first_expr_false_label)
            ->set_ctx(ctx)
    );

    //if true -> visit second expression
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (const_left && const_right) {
        
        cfg->get_current_bb()->remove_last_instructions(3);

        final_value = val_left && val_right;

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        //setup of block to reach if first expr is false
        IR::BasicBlock * first_expr_false_bb = new IR::BasicBlock(cfg, first_expr_false_label, nullptr, nullptr);
        first_expr_false_bb->set_exit(end_label);
        first_expr_false_bb->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal("0")
                )
                ->set_dest(
                    (new IR::IRRegA)
                        ->set_size(IR::DWord))
                ->set_ctx(ctx)
        );

        //in the end, jump to block which continues the program
        cfg->get_current_bb()->set_exit(end_label);

        IR::BasicBlock * end_bb = new IR::BasicBlock(cfg, end_label, nullptr, nullptr);

        cfg->add_bb(first_expr_false_bb);
        cfg->add_bb(end_bb);
    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

antlrcpp::Any IRVisitor::visitExprOr(ifccParser::ExprOrContext *ctx) {

    //equivalent to : if first expr is true then return true, else return value of second expr
    bool const_left; bool const_right;
    int val_left; int val_right;
    int final_value;

    string first_expr_true_label = cfg->get_next_bb_label();
    string end_label = cfg->get_next_bb_label();

    this->visit(ctx->expr(0));
    const_left = vf.f_const;
    val_left = vf.value;

    //if true -> jump to the block which moves $1 into %eax
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfEqual)
            ->set_label(first_expr_true_label)
            ->set_ctx(ctx)
    );

    //if true -> visit second expression
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (const_left && const_right) {
        
        cfg->get_current_bb()->remove_last_instructions(3);

        final_value = val_left || val_right;

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal(to_string(final_value))
                        ->set_size(IR::Int.size)
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

    } else {

        //setup of block to reach if first expr is false
        IR::BasicBlock * first_expr_true_bb = new IR::BasicBlock(cfg, first_expr_true_label, nullptr, nullptr);
        first_expr_true_bb->set_exit(end_label);
        first_expr_true_bb->add_instr(
            (new IR::IRInstrMov)
                ->set_src(
                    (new IR::IRConst)
                        ->set_literal("1")
                )
                ->set_dest(
                    (new IR::IRRegA)
                        ->set_size(IR::DWord))
                ->set_ctx(ctx)
        );

        //in the end, jump to block which continues the program
        cfg->get_current_bb()->set_exit(end_label);

        IR::BasicBlock * end_bb = new IR::BasicBlock(cfg, end_label, nullptr, nullptr);

        cfg->add_bb(first_expr_true_bb);
        cfg->add_bb(end_bb);
    }
    
    //update flags
    vf.type_size = IR::Int.size;
    vf.f_const = (const_left && const_right);
    if (vf.f_const) {
        vf.value = final_value;
    }

    return 0;
}

////////////////////////////////////////////
// STRUCTURES DE CONTROLE
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitStruct_if_else(ifccParser::Struct_if_elseContext *ctx) {
    IR::BasicBlock * expr_bb = cfg->get_current_bb();
    
    //determine if it's if-then-else or only if-then
    bool if_then_else = (ctx->struct_bloc().size() > 1) ? true : false;
    
    // Evaluate IF expression
    this->visit(ctx->expr());

    // Create labels for jumps -> now because the child needs to jump to the parent when finished
    string exit_label = cfg->get_next_bb_label();
    string if_false_label;

    // Push end jump label to stack for children
    cfg->stack.push_back(exit_label); // Push own exit

    cfg->set_current_bb(expr_bb);
    // Compare IF result
    cfg->add_instr(
        (new IR::IRInstrComp)
            ->set_src(
                (new IR::IRConst)->set_literal("1")
            )
            ->set_dest(new IR::IRRegA)
            ->set_ctx(ctx)
    );

    //if-then else -> jump to false bloc
    string jump_after_eval_cond;
    switch (if_then_else) {
        case true:
            if_false_label = cfg->get_next_bb_label();
            jump_after_eval_cond = if_false_label;
            break;
        case false:
            jump_after_eval_cond = exit_label;
    }

    //Jump after condition evaluation
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfNotEqual)
            ->set_label(jump_after_eval_cond)
            ->set_ctx(ctx)
    );

    // Visit if true : always
    this->visit(ctx->struct_bloc(0)); // Add if true

    // Jump to endif block when if complete
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::Jump)
            ->set_label(exit_label)
            ->set_ctx(ctx)
    );

    // Add if false
    if (if_then_else) {
        IR::BasicBlock * if_false = new IR::BasicBlock(cfg, if_false_label, nullptr, nullptr);
        cfg->add_bb(if_false);
        this->visit(ctx->struct_bloc(1));
        if_false->set_exit(exit_label);
    }

    // Pop exit from stack
    cfg->stack.pop_back();

    // Add exit
    IR::BasicBlock * exit_bb = new IR::BasicBlock(cfg, exit_label, nullptr, nullptr);
    cfg->add_bb(exit_bb);

    // Set exit from parent
    if (cfg->stack.size() > 0)
    {
        string parent_exit = cfg->stack.back();
        if (parent_exit != "")
        {
            exit_bb->set_exit(parent_exit);
        }
    }

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitStruct_while(ifccParser::Struct_whileContext *ctx) {

    //Labels for new blocks
    string condition_label = cfg->get_next_bb_label();
    string body_label = cfg->get_next_bb_label();
    string end_while_label = cfg->get_next_bb_label();

    // Push condition (!!!!) jump label to stack for children
    cfg->stack.push_back(condition_label); // Push own exit

    //Jump to condition block
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::Jump)
            ->set_label(condition_label)
            ->set_ctx(ctx)
    );

    //Parsing of condition block
    IR::BasicBlock * condition_bb = new IR::BasicBlock(cfg, condition_label, nullptr, nullptr);
    condition_bb->set_bb_id(BB_WHILE); //for break/continue
    cfg->add_bb(condition_bb);
    this->visit(ctx->expr());
    condition_bb->set_exit(end_while_label); //jumps to end if condition false
    
    //test result
    cfg->add_instr(
        (new IR::IRInstrComp)
            ->set_src(
                (new IR::IRConst)->set_literal("1")
            )
            ->set_dest(new IR::IRRegA)
            ->set_ctx(ctx)
    );
    //if condition is evaluated to "true" -> jump to body of the while
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfEqual)
            ->set_label(body_label)
            ->set_ctx(ctx)
    );

    //Parsing of body block
    IR::BasicBlock * body_bb = new IR::BasicBlock(cfg, body_label, nullptr, nullptr);
    cfg->add_bb(body_bb);
    this->visit(ctx->struct_bloc());
    body_bb->set_exit(condition_label);

    //Adding the end-while block
    IR::BasicBlock * end_while_bb = new IR::BasicBlock(cfg, end_while_label, nullptr, nullptr);
    body_bb->set_bb_id(BB_END_WHILE);
    cfg->add_bb(end_while_bb);

    // Pop exit from stack
    cfg->stack.pop_back();

    // Set exit from parent
    if (cfg->stack.size() > 0)
    {
        string parent_exit = cfg->stack.back();
        if (parent_exit != "")
        {
            end_while_bb->set_exit(parent_exit);
        }
    }

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitStruct_switch_case(ifccParser::Struct_switch_caseContext *ctx) {
    
    int nb_case = ctx->case_opt().size();
    bool default_opt = ctx->default_opt() ? true : false;

    vector<IR::BasicBlock *> cases;

    //Works because while_bb are identified via the condition block (a switch will be in the body block)
    cfg->get_current_bb()->set_bb_id(BB_SWITCH);

    //Labels
    string end_switch_label = cfg->get_next_bb_label();

    cfg->get_current_bb()->set_exit(end_switch_label);    

    //evaluate expression
    this->visit(ctx->expr());

    //evaluate all conditions and prepare corresponding blocks
    for (int i=0; i < nb_case ; ++i) {
        //create bb
        string case_bb_label = cfg->get_next_bb_label();
        IR::BasicBlock * case_bb = new IR::BasicBlock(cfg, case_bb_label, nullptr, nullptr);
        cases.push_back(case_bb);

        //evaluate case condition
        cfg->add_instr(
            (new IR::IRInstrComp)
                ->set_src(
                    (new IR::IRConst)->set_literal(ctx->case_opt(i)->case_val()->getText())
                )
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );
        cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfEqual)
            ->set_label(case_bb_label)
            ->set_ctx(ctx)
        );
    }

    //first : visit default (reached if no previous condition is matched)
    if (default_opt) {
        this->visit(ctx->default_opt()->case_block());
    }

    for(int i=0 ; i < nb_case ; ++i) {
        cfg->add_bb(cases.at(i));
        this->visit(ctx->case_opt(i)->case_block());
    }

    IR::BasicBlock * end_switch_bb = new IR::BasicBlock(cfg, end_switch_label, nullptr, nullptr);
    cfg->add_bb(end_switch_bb);

    return 0;
}

////////////////////////////////////////////
// FONCTIONS
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitDecla_function(ifccParser::Decla_functionContext *ctx) {
   
    //One CFG and one Symbol Table per fonction (careful : CFG contains the ST in our model)
    IR::CFG * cfg = static_cast<IR::CFG *>(
        (new IR::CFG(ctx->fname->getText()))
        ->set_parent(cfg_set)
    );

    //Update both cfg_set AND current cfg kept as attribute
    cfg_set->add_cfg(cfg);
    this->cfg = cfg;

    int nb_params = ctx->fparam_decla()->fparam_decla2().size();
    cfg->set_nb_param(nb_params);
    cfg->set_no_return(ctx->return_type->getText() == "void");

    //Get parameters from registers into temporary variables
    int stop = nb_params > 6 ? 6 : nb_params;
    int i=0;
    while(i < stop) {
        IR::Symbol *symbol = this->cfg->get_symbol_table()->declare_symbol(cfg, ctx->fparam_decla()->fparam_decla2(i)->VAR()->getText(), IR::Int, ctx);
        cfg->add_instr(
            (new IR::IRInstrAssign)
                ->set_src(reg_function_params[i])
                ->set_symbol(symbol)
                ->set_ctx(ctx)
        );
        i++;
    }

    //If more than 6 parameters -> we need to get parameters from the stack
    //Careful : we declare variables with personnalized offset
    int offset = 16;
    for (int i=6 ; i < nb_params ; i++) {
        IR::Symbol *symbol = this->cfg->get_symbol_table()->declare_symbol(cfg, ctx->fparam_decla()->fparam_decla2(i)->VAR()->getText(), IR::Int, ctx);
        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src((new IR::IRRegStack)->set_offset(offset))
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );
        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(symbol)
                ->set_ctx(ctx)
        );
        offset += 8;
    }

    //Then only, visit block
    this->visit(ctx->struct_bloc());

    return 0;
}

antlrcpp::Any IRVisitor::visitFunctionCallRule(ifccParser::FunctionCallRuleContext *ctx) {

    int nb_params = ctx->fparam_call()->fparam_call2().size();
    bool more_6_params = false;
    int cpt_bytes;

    //first : check if correct number of parameters
    try {
        int correct_nb_param = cfg_set->get_cfg_by_fname(ctx->fname->getText())->get_nb_param();
        if (correct_nb_param != nb_params) {
            this->cfg->get_error_reporter()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "function called with wrong number of parameters", ctx)
            );
        }
    } catch (exception &e) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "this function is called but not declared", ctx)
        );
    }

    //If there is more than 6 parameters, we place the remaining parameters on top of the stack
    if (nb_params > 6) {
        more_6_params = true;
        cpt_bytes=0;  //bytes to substract from %rsp after the call
        for(int i = (nb_params-1); i > 5; i--) {
            cfg->add_instr(
                (new IR::IRInstrPush)
                    ->set_src(
                        (new IR::IRConst)
                            ->set_literal(ctx->fparam_call()->fparam_call2(i)->NUM()->getText())
                            ->set_size(IR::Size::QWord)
                    )
                    ->set_ctx(ctx)
            );
            cpt_bytes += size_to_bytes(IR::Size::QWord);
        }
    }

    //Put parameters in the dedicated registers -> for 7th parameters and beyond, the method is different
    int i = more_6_params ? 5 : (nb_params-1);
    while(i >= 0) {
        //If param is a cst
        if (ctx->fparam_call()->fparam_call2(i)->NUM()) {
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(
                        (new IR::IRConst)
                            ->set_literal(ctx->fparam_call()->fparam_call2(i)->NUM()->getText())
                    )
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        //If it's a variable
        else if (ctx->fparam_call()->fparam_call2(i)->VAR()) {
            IR::Symbol* src = cfg->get_symbol_table()->get_symbol(ctx->fparam_call()->fparam_call2(i)->VAR()->getText());
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(src)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        //If it's an expression
        else {
            this->visit(ctx->fparam_call()->fparam_call2(i));
        }
        //%eax to available register
        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(reg_function_params[i])
                ->set_ctx(ctx)
        );
        i--;
    }

    //call instruction
    cfg->add_instr(
        (new IR::IRInstrCall)
            ->set_literal(ctx->fname->getText())
            ->set_ctx(ctx)
    );

    //if more than 6 parameters -> move up %rsp
    if (more_6_params) {
        cfg->add_instr(
            (new IR::IRInstrExprPlus)
                ->set_src((new IR::IRConst)
                        ->set_literal(to_string(cpt_bytes))
                        ->set_size(IR::Size::QWord)
                )
                ->set_dest((new IR::IRRegStackPointer)
                            ->set_size(IR::Size::QWord)
                )
                ->set_ctx(ctx)
        );
    }

    return 0;
}

////////////////////////////////////////////
// BREAK/CONTINUE
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitBreakStmt(ifccParser::BreakStmtContext *ctx) {
    //check if break can be used
    IR::BasicBlock * bb_loop;
    try {
        bb_loop = cfg->get_break_parent(cfg->get_current_bb()->get_label());
    } catch (exception &e) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "'break' can only be used in loop or 'switch'", ctx)
        );
    }

    //we need to jump to end_while block
    string end_loop_label = bb_loop->get_exit_label();

    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::Jump)
            ->set_label(end_loop_label)
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitContinueStmt(ifccParser::ContinueStmtContext *ctx) {
    //check if continue can be used
    IR::BasicBlock * bb_loop;
    try {
        bb_loop = cfg->get_continue_parent(cfg->get_current_bb()->get_label());
    } catch (exception &e) {
        this->cfg->get_error_reporter()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "'continue' can only be used in loop", ctx)
        );
    }

    //we need to jump to condition
    string condition_loop_label = bb_loop->get_label();

    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::Jump)
            ->set_label(condition_loop_label)
            ->set_ctx(ctx)
    );

    return 0;
}