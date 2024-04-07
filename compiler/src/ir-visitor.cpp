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
#include "ir/instr/test.h"
#include "ir/ir-errors.h"
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
    cerr << "visit return" << endl;
    //detection of return inside a return-void function
    if (cfg->get_no_return()) {
        ErrorReporter::ErrorReporter::getInstance()->reportError(
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

    cerr << "end return" << endl;
    return 0;
}

////////////////////////////////////////////
// DECLARATION/AFFECTATION
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitSimpleAff(ifccParser::SimpleAffContext *ctx)
{
    cerr << "visit affectation" << endl;
    IR::Symbol * symbol = cfg->get_current_bb()->get_symbol(ctx->VAR()->getText(), ctx);
    
    if (symbol->const_var) {
        ErrorReporter::ErrorReporter::getInstance()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "'const' value cannot be used as left-value", ctx)
        );
    }

    this->visit(ctx->rvalue());

    if (ctx->op_aff->getText() == "=") {
        //base affectation : simply affect value
        cerr << "aff =" << endl;

        cfg->add_instr(
            (new IR::IRInstrAssign)
                ->set_symbol(symbol)
                ->set_ctx(ctx)
        );
    } else if (ctx->op_aff->getText() == "+=") {
        cerr << "aff +" << endl;
        cfg->add_instr(
            (new IR::IRInstrExprPlus)
                ->set_src(new IR::IRRegA)
                ->set_dest(symbol)
                ->set_ctx(ctx)
        );

    } else if (ctx->op_aff->getText() == "*=") {
        cerr << "aff *" << endl;

        cfg->add_instr(
                (new IR::IRInstrExprMult)
                    ->set_src(symbol)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
        );

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(symbol)
                ->set_ctx(ctx)
        );

    } else if (ctx->op_aff->getText() == "-=") {
        cerr << "aff -" << endl;
        cfg->add_instr(
                (new IR::IRInstrExprMinus)
                    ->set_src(new IR::IRRegA)
                    ->set_dest(symbol)
                    ->set_ctx(ctx)
        );

    } else if (ctx->op_aff->getText() == "/=") {
        cerr << "aff /" << endl;
        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(new IR::IRRegB)
                ->set_ctx(ctx)
        );

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(symbol)
                ->set_dest(new IR::IRRegA)
                ->set_ctx(ctx)
        );

        cfg->add_instr(
            (new IR::IRInstrExprDiv)
                ->set_ctx(ctx)
        );

        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(symbol)
                ->set_ctx(ctx)
        );
    }

    //move value of result into %eax
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(symbol)
            ->set_dest(new IR::IRRegA)
            ->set_ctx(ctx)
    );

    //update flags : not the value, we need to propagate it
    vf.type_size = IR::Int.size;
    vf.f_const = false;

    cerr << "end affectation" << endl;

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
        ErrorReporter::ErrorReporter::getInstance()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Unrecognized type", ctx)
        );
    }

    cfg->get_current_bb()->declare_symbol(cfg, ctx->VAR()->getText(), type, ctx);

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
        ErrorReporter::ErrorReporter::getInstance()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Unrecognized type", ctx)
        );
    }

    IR::Symbol * symbol = cfg->get_current_bb()->declare_symbol(cfg, ctx->VAR()->getText(), type, ctx, const_var);
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
    IR::Type type;

    if (ctx->CHAR())
    {
        type = IR::Char;
    }
    else if (ctx->INT())
    {
        type = IR::Int;
    }
    else
    {
        ErrorReporter::ErrorReporter::getInstance()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Unrecognized type", ctx)
        );
    }

    cfg->get_current_bb()->declare_symbol(cfg, ctx->VAR()->getText(), type, ctx, false, stoi(ctx->NUM()->getText()));

    return 0;
}

antlrcpp::Any IRVisitor::visitExprTable(ifccParser::ExprTableContext *ctx)
{
    IR::Symbol * symbol = cfg->get_current_bb()->get_symbol(ctx->VAR()->getText(), ctx);
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
    IR::Symbol * symbol = cfg->get_current_bb()->get_symbol(ctx->VAR()->getText(), ctx);
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
    IR::Symbol *var = cfg->get_current_bb()->get_symbol(ctx->VAR()->getText(), ctx);
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

    IR::Symbol *varTemp = this->cfg->get_current_bb()->declare_tmp(cfg, IR::Int, ctx);
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
            ErrorReporter::ErrorReporter::getInstance()->reportError(
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

    IR::Symbol *varTemp = this->cfg->get_current_bb()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));
    const_right = vf.f_const;
    val_right = vf.value;

    if (val_right == 0 && (ctx->OP_MULT()->getText() == "/" || ctx->OP_MULT()->getText() == "%")) {
        ErrorReporter::ErrorReporter::getInstance()->reportError(
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
        } else if (ctx->op_unary->getText() == "!"){
            final_value = !val;
        } else if (ctx->op_unary->getText() == "+"){
            final_value = val;
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
        else if (ctx->op_unary->getText() == "!") {
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

    IR::Symbol *varTemp = this->cfg->get_current_bb()->declare_tmp(cfg, IR::Int, ctx);
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

    IR::Symbol *varTemp = this->cfg->get_current_bb()->declare_tmp(cfg, IR::Int, ctx);
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

    IR::Symbol *varTemp = this->cfg->declare_tmp(cfg, IR::Int, ctx);
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
    string left_expr_label = cfg->get_next_bb_label();
    string left_eval_label = cfg->get_next_bb_label();
    string right_expr_label = cfg->get_next_bb_label();
    string true_label = cfg->get_next_bb_label();
    string exit_label = cfg->get_next_bb_label();

    IR::BasicBlock * left_expr_bb = new IR::BasicBlock(cfg, left_expr_label, nullptr, nullptr);
    cfg->add_bb(left_expr_bb);
    this->visit(ctx->expr(0));
    cfg->get_current_bb()->set_exit(left_eval_label);

    IR::BasicBlock * left_eval_bb = new IR::BasicBlock(cfg, left_eval_label, nullptr, nullptr);
    cfg->add_bb(left_eval_bb);

    cfg->add_instr(
        (new IR::IRInstrTest)
            ->set_src(new IR::IRRegA)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfTrue)
            ->set_label(right_expr_label)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfFalse)
            ->set_label(exit_label)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * right_expr_bb = new IR::BasicBlock(cfg, right_expr_label, nullptr, nullptr);
    cfg->add_bb(right_expr_bb);
    this->visit(ctx->expr(1));
    cfg->get_current_bb()->set_exit(exit_label);

    cfg->add_instr(
        (new IR::IRInstrTest)
            ->set_src(new IR::IRRegA)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfTrue)
            ->set_label(true_label)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfFalse)
            ->set_label(exit_label)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * true_bb = new IR::BasicBlock(cfg, true_label, nullptr, nullptr);
    cfg->add_bb(true_bb);

    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(
                (new IR::IRConst)
                    ->set_literal("1")
                    ->set_size(IR::Int.size)
            )
            ->set_dest(new IR::IRRegA)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * exit_bb = new IR::BasicBlock(cfg, exit_label, nullptr, nullptr);
    cfg->add_bb(exit_bb);

    return 0;
}

antlrcpp::Any IRVisitor::visitExprOr(ifccParser::ExprOrContext *ctx) {
    string left_expr_label = cfg->get_next_bb_label();
    string left_eval_label = cfg->get_next_bb_label();
    string right_expr_label = cfg->get_next_bb_label();
    string true_label = cfg->get_next_bb_label();
    string exit_label = cfg->get_next_bb_label();

    IR::BasicBlock * left_expr_bb = new IR::BasicBlock(cfg, left_expr_label, nullptr, nullptr);
    cfg->add_bb(left_expr_bb);
    this->visit(ctx->expr(0));
    cfg->get_current_bb()->set_exit(left_eval_label);

    IR::BasicBlock * left_eval_bb = new IR::BasicBlock(cfg, left_eval_label, nullptr, nullptr);
    cfg->add_bb(left_eval_bb);

    cfg->add_instr(
        (new IR::IRInstrTest)
            ->set_src(new IR::IRRegA)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfTrue)
            ->set_label(true_label)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfFalse)
            ->set_label(right_expr_label)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * right_expr_bb = new IR::BasicBlock(cfg, right_expr_label, nullptr, nullptr);
    cfg->add_bb(right_expr_bb);
    this->visit(ctx->expr(1));
    cfg->get_current_bb()->set_exit(exit_label);

    cfg->add_instr(
        (new IR::IRInstrTest)
            ->set_src(new IR::IRRegA)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfTrue)
            ->set_label(true_label)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfFalse)
            ->set_label(exit_label)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * true_bb = new IR::BasicBlock(cfg, true_label, nullptr, nullptr);
    cfg->add_bb(true_bb);

    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(
                (new IR::IRConst)
                    ->set_literal("1")
                    ->set_size(IR::Int.size)
            )
            ->set_dest(new IR::IRRegA)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * exit_bb = new IR::BasicBlock(cfg, exit_label, nullptr, nullptr);
    cfg->add_bb(exit_bb);

    return 0;
}

////////////////////////////////////////////
// STRUCTURES DE CONTROLE
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitStruct_if_else(ifccParser::Struct_if_elseContext *ctx) {
    string expr_label = cfg->get_next_bb_label();
    string eval_label = cfg->get_next_bb_label();
    string if_true_label = cfg->get_next_bb_label();
    string if_false_label = cfg->get_next_bb_label();
    string exit_label = cfg->get_next_bb_label();

    bool has_else_stmt = ctx->struct_bloc().size() > 1;

    if (!has_else_stmt)
    {
        if_false_label = exit_label;
    }
    
    IR::BasicBlock * expr_bb = new IR::BasicBlock(cfg, expr_label, nullptr, nullptr);
    cfg->add_bb(expr_bb);
    this->visit(ctx->expr());
    cfg->get_current_bb()->set_exit(eval_label);

    IR::BasicBlock * eval_bb = new IR::BasicBlock(cfg, eval_label, nullptr, nullptr);
    cfg->add_bb(eval_bb);

    cfg->add_instr(
        (new IR::IRInstrTest)
            ->set_src(new IR::IRRegA)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfTrue)
            ->set_label(if_true_label)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfFalse)
            ->set_label(if_false_label)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * if_true_bb = new IR::BasicBlock(cfg, if_true_label, nullptr, nullptr);
    cfg->add_bb(if_true_bb);
    this->visit(ctx->struct_bloc(0));
    cfg->get_current_bb()->set_exit(exit_label);

    if (has_else_stmt)
    {
        IR::BasicBlock * if_false_bb = new IR::BasicBlock(cfg, if_false_label, nullptr, nullptr);
        cfg->add_bb(if_false_bb);
        this->visit(ctx->struct_bloc(1));
        cfg->get_current_bb()->set_exit(exit_label);
    }
    
    IR::BasicBlock * exit_bb = new IR::BasicBlock(cfg, exit_label, nullptr, nullptr);
    cfg->add_bb(exit_bb);

    return 0;
}

antlrcpp::Any IRVisitor::visitStruct_while(ifccParser::Struct_whileContext *ctx) {
    string expr_label = cfg->get_next_bb_label();
    string eval_label = cfg->get_next_bb_label();
    string if_true_label = cfg->get_next_bb_label();
    string exit_label = cfg->get_next_bb_label();

    IR::BasicBlock * expr_bb = new IR::BasicBlock(cfg, expr_label, nullptr, nullptr);
    cfg->add_bb(expr_bb);
    this->visit(ctx->expr());
    cfg->get_current_bb()->set_exit(eval_label);

    IR::BasicBlock * eval_bb = new IR::BasicBlock(cfg, eval_label, nullptr, nullptr);
    cfg->add_bb(eval_bb);

    cfg->add_instr(
        (new IR::IRInstrTest)
            ->set_src(new IR::IRRegA)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfTrue)
            ->set_label(if_true_label)
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_jump(IR::JumpType::IfFalse)
            ->set_label(exit_label)
            ->set_ctx(ctx)
    );

    IR::BasicBlock * if_true_bb = new IR::BasicBlock(cfg, if_true_label, nullptr, nullptr);
    cfg->add_bb(if_true_bb);
    cfg->push_break(exit_label);         // Add exit label to break stack
    this->visit(ctx->struct_bloc());
    cfg->pop_break();                    // Remove exit label from break stack
    cfg->get_current_bb()->set_exit(expr_label);
    
    IR::BasicBlock * exit_bb = new IR::BasicBlock(cfg, exit_label, nullptr, nullptr);
    cfg->add_bb(exit_bb);

    return 0;
}

antlrcpp::Any IRVisitor::visitStruct_switch_case(ifccParser::Struct_switch_caseContext *ctx) {
    string expr_label = cfg->get_next_bb_label();
    string eval_label = cfg->get_next_bb_label();

    vector<string> case_eval_labels;    // Compare case value with expr
    vector<string> case_block_labels;   // Execute case block
    vector<string> case_exit_labels;    // Exit case block

    int nb_case = ctx->case_opt().size();

    for (int i=0; i < nb_case ; ++i) {
        case_eval_labels.push_back(cfg->get_next_bb_label("SWITCH_EVAL_" + to_string(i)));
        case_block_labels.push_back(cfg->get_next_bb_label("SWITCH_BLOCK_" + to_string(i)));
        case_exit_labels.push_back(cfg->get_next_bb_label("SWITCH_EXIT_" + to_string(i)));
    }

    string default_label = cfg->get_next_bb_label();
    string exit_label = cfg->get_next_bb_label();

    bool has_default = ctx->default_opt() ? true : false;

    // Define where to redirect a case eval if no block available
    string case_default_label = has_default ? default_label : exit_label;

    IR::BasicBlock * expr_bb = new IR::BasicBlock(cfg, expr_label, nullptr, nullptr);
    cfg->add_bb(expr_bb);
    this->visit(ctx->expr());
    cfg->get_current_bb()->set_exit(eval_label);

    IR::BasicBlock * eval_bb = new IR::BasicBlock(cfg, eval_label, nullptr, nullptr);
    cfg->add_bb(eval_bb);

    IR::Symbol *eval_res = this->cfg->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(eval_res)
            ->set_ctx(ctx)
    );

    for (int i=0; i < nb_case ; ++i) {
        IR::BasicBlock * case_eval_bb = new IR::BasicBlock(cfg, case_eval_labels.at(i), nullptr, nullptr);
        cfg->add_bb(case_eval_bb);

        cfg->add_instr(
            (new IR::IRInstrComp)
                ->set_src(
                    (new IR::IRConst)->set_literal(ctx->case_opt(i)->case_val()->getText())
                )
                ->set_dest(eval_res)
                ->set_ctx(ctx)
        );

        string next_eval_label = i == nb_case - 1 ? (has_default ? default_label : exit_label) : case_eval_labels.at(i+1);

        // If true, go to case block
        cfg->add_instr(
            (new IR::IRInstrJump)
                ->set_jump(IR::JumpType::IfEqual)
                ->set_label(case_block_labels.at(i))
                ->set_ctx(ctx)
        );
        // If false, go to next case eval
        cfg->add_instr(
            (new IR::IRInstrJump)
                ->set_jump(IR::JumpType::IfNotEqual)
                ->set_label(next_eval_label)
                ->set_ctx(ctx)
        );

        IR::BasicBlock * case_block_bb = new IR::BasicBlock(cfg, case_block_labels.at(i), nullptr, nullptr);
        cfg->add_bb(case_block_bb);
        cfg->push_break(exit_label);         // Add exit label to break stack
        this->visit(ctx->case_opt(i)->case_block());
        cfg->pop_break();                    // Remove exit label from break stack
        cfg->get_current_bb()->set_exit(case_exit_labels.at(i));

        IR::BasicBlock * case_exit_bb = new IR::BasicBlock(cfg, case_exit_labels.at(i), nullptr, nullptr);
        cfg->add_bb(case_exit_bb);

        // If block has no break, execute next block without eval
        string next_block_label = i == nb_case - 1 ? (has_default ? default_label : exit_label) : case_block_labels.at(i+1);
        cfg->add_instr(
            (new IR::IRInstrJump)
                ->set_jump(IR::JumpType::Jump)
                ->set_label(next_block_label)
                ->set_ctx(ctx)
        );
    }

    if (has_default) {
        IR::BasicBlock * default_bb = new IR::BasicBlock(cfg, default_label, nullptr, nullptr);
        cfg->add_bb(default_bb);
        cfg->push_break(exit_label);         // Add exit label to break stack
        this->visit(ctx->default_opt()->case_block());
        cfg->pop_break();                    // Remove exit label from break stack
        cfg->get_current_bb()->set_exit(exit_label);
    }

    IR::BasicBlock * exit_bb = new IR::BasicBlock(cfg, exit_label, nullptr, nullptr);
    cfg->add_bb(exit_bb);

    return 0;
}

////////////////////////////////////////////
// FONCTIONS
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitDecla_function(ifccParser::Decla_functionContext *ctx) {
    cfg_set->declare_function(ctx->fname->getText(), ctx);

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
        IR::Symbol *symbol = this->cfg->get_current_bb()->declare_symbol(
            cfg,
            ctx->fparam_decla()->fparam_decla2(i)->VAR()->getText(),
            IR::Int,
            ctx->fparam_decla()->fparam_decla2(i)
        );
        cfg->add_instr(
            (new IR::IRInstrAssign)
                ->set_src(reg_function_params[i])
                ->set_symbol(symbol)
                ->set_ctx(ctx->fparam_decla()->fparam_decla2(i))
        );
        i++;
    }

    //If more than 6 parameters -> we need to get parameters from the stack
    //Careful : we declare variables with personnalized offset
    int offset = 16;
    for (int i=6 ; i < nb_params ; i++) {
        IR::Symbol *symbol = this->cfg->get_current_bb()->declare_symbol(
            cfg,
            ctx->fparam_decla()->fparam_decla2(i)->VAR()->getText(),
            IR::Int,
            ctx->fparam_decla()->fparam_decla2(i)
        );
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
    if (ctx->fname->getText() != "getchar" && ctx->fname->getText() != "putchar") {
        try {
            int correct_nb_param = cfg_set->get_cfg_by_fname(ctx->fname->getText())->get_nb_param();
            if (correct_nb_param != nb_params) {
                ErrorReporter::ErrorReporter::getInstance()->reportError(
                    new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "function called with wrong number of parameters", ctx)
                );
            }
        } catch (exception &e) {
            ErrorReporter::ErrorReporter::getInstance()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "this function is called but not declared", ctx)
            );
        }
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
            IR::Symbol* src = cfg->get_current_bb()->get_symbol(ctx->fparam_call()->fparam_call2(i)->VAR()->getText(), ctx);
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
    try {
        cfg->add_instr(
            (new IR::IRInstrJump)
                ->set_jump(IR::JumpType::Jump)
                ->set_label(cfg->get_break())
                ->set_ctx(ctx)
        );
    } catch (IR::IRLoopError &e) {
        ErrorReporter::ErrorReporter::getInstance()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, e.what(), ctx)
        );
    }

    

    return 0;
}

antlrcpp::Any IRVisitor::visitContinueStmt(ifccParser::ContinueStmtContext *ctx) {
    //check if continue can be used
    IR::BasicBlock * bb_loop;
    try {
        bb_loop = cfg->get_continue_parent(cfg->get_current_bb()->get_label());
    } catch (exception &e) {
        cerr << e.what() << endl;
        ErrorReporter::ErrorReporter::getInstance()->reportError(
            new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "'continue' can only be used in loop", ctx)
        );
        return 0;
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