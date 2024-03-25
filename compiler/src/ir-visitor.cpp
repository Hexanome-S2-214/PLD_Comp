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
#include "ir/instr/comp.h"
#include "ir/instr/set_flag_comp.h"
#include "ir/instr/expression_bit_a_bit.h"
#include "ir/instr/intr-cheat.h"
#include "ir/instr/jump.h"
#include "ir/instr/call.h"
#include "ir/instr/pushq.h"
#include "error-reporter/compiler-error-token.h"
#include "./error-reporter/error-reporter.h"

////////////////////////////////////////////
// DECLARATION/AFFECTATION
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitDeclStdRule(ifccParser::DeclStdRuleContext *ctx)
{
    if(ctx->getTokens(ifccParser::INT).size() >= 1)
    {
        cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Int, ctx);
    }else if(ctx->getTokens(ifccParser::CHAR).size() >= 1)
    {
        cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Char, ctx);
    }

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx)
{
    this->visit(ctx->rvalue());

    IR::Symbol *symbol;
    if (ctx->getTokens(ifccParser::INT).size() >= 1)
    {
        symbol = cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Int, ctx);
    }else if(ctx->getTokens(ifccParser::CHAR).size() >= 1)
    {
        symbol = cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Char, ctx);
    }

    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(symbol)
            ->set_ctx(ctx)
    );

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitAffectationRule(ifccParser::AffectationRuleContext *ctx)
{
    this->visit(ctx->rvalue());

    IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);

    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(symbol)
            ->set_ctx(ctx)
    );

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitAffectationRule2(ifccParser::AffectationRule2Context *ctx)
{
    this->visit(ctx->rvalue());

    IR::Symbol * symbol = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);

    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(symbol)
            ->set_ctx(ctx)
    );

    return IR::Int.size;
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
    }

    return IR::Char.size;
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

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitExprVar(ifccParser::ExprVarContext *ctx)
{
    IR::Symbol *var = cfg->get_symbol_table()->get_symbol(ctx->VAR()->getText(), ctx);
    cfg->add_instr(
        (new IR::IRInstrExprVar)
            ->set_symbol(
                var)
            ->set_ctx(ctx));

    return var->type.size;
}

////////////////////////////////////////////
// OPERATIONS ARITHMETIQUES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprSumSous(ifccParser::ExprSumSousContext *ctx) {
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );

    this->visit(ctx->expr(1));

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

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitExprMultDivMod(ifccParser::ExprMultDivModContext *ctx)
{
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

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

    return IR::Int.size;
}

////////////////////////////////////////////
// OPERATEURS UNAIRES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprUnary(ifccParser::ExprUnaryContext *ctx)
{
    this->visit(ctx->expr());

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

    return IR::Int.size;
}

////////////////////////////////////////////
// COMPARAISONS
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprEqComparaison(ifccParser::ExprEqComparaisonContext *ctx) {
    
    //évaluation à gauche
    this->visit(ctx->expr(0));

    //on stocke dans ECX
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(new IR::IRRegA)
            ->set_dest(new IR::IRRegC)
            ->set_ctx(ctx)
    );

    //évaluation à droite
    this->visit(ctx->expr(1));

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

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitExprComparaison(ifccParser::ExprComparaisonContext *ctx) {
    IR::Size res = IR::Int.size;
    // évaluation à gauche
    IR::Size leftSize = this->visit(ctx->expr(0)).as<IR::Size>();

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
    IR::Size rightSize = this->visit(ctx->expr(1)).as<IR::Size>();
    res = min(leftSize, rightSize);

    cfg->add_instr(
        (new IR::IRInstrComp)
            ->set_src(
                (new IR::IRRegA)
                    ->set_size(res)
            )
            ->set_dest(
                (new IR::IRRegC)
                    ->set_size(res)
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

    return res;
}

////////////////////////////////////////////
// OPERATEURS BIT-A-BIT
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprAndBAB(ifccParser::ExprAndBABContext *ctx) {

    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp)
            ->set_dest(new IR::IRRegA)
            ->set_op(ctx->B_AND()->getText())
            ->set_ctx(ctx)
    );

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitExprXorBAB(ifccParser::ExprXorBABContext *ctx) {
    
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp)
            ->set_dest(new IR::IRRegA)
            ->set_op(ctx->B_XOR()->getText())
            ->set_ctx(ctx)
    );

    return IR::Int.size;
}

antlrcpp::Any IRVisitor::visitExprOrBAB(ifccParser::ExprOrBABContext *ctx) {

    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_symbol(varTemp)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp)
            ->set_dest(new IR::IRRegA)
            ->set_op(ctx->B_OR()->getText())
            ->set_ctx(ctx)
    );

    return IR::Int.size;
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
            ->set_op("jne")
            ->set_label(jump_after_eval_cond)
            ->set_ctx(ctx)
    );

    // Visit if true : always
    this->visit(ctx->struct_bloc(0)); // Add if true

    // Jump to endif block when if complete
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_op("jmp")
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

    IR::BasicBlock * expr_bb = cfg->get_current_bb();

    //Labels for new blocks
    string end_while_label = cfg->get_next_bb_label();
    string body_label = cfg->get_next_bb_label();

    //Jump to condition/end-while block
    cfg->add_instr(
        (new IR::IRInstrJump)
            ->set_op("jmp")
            ->set_label(end_while_label)
            ->set_ctx(ctx)
    );

    //Parsing of body block
    IR::BasicBlock * body_bb = new IR::BasicBlock(cfg, body_label, nullptr, nullptr);
    cfg->add_bb(body_bb);
    this->visit(ctx->struct_bloc());
    body_bb->set_exit(end_while_label);

    //Parsing of condition/end-while block
    IR::BasicBlock * end_while_bb = new IR::BasicBlock(cfg, end_while_label, nullptr, nullptr);
    cfg->add_bb(end_while_bb);
    this->visit(ctx->expr());

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
            ->set_op("je")
            ->set_label(body_label)
            ->set_ctx(ctx)
    );

    return IR::Int.size;
}

////////////////////////////////////////////
// FONCTIONS
//
// WARNING : ONLY INT SUPPORTED FOR NOW / MAX 6 PARAMETERS
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitDecla_function(ifccParser::Decla_functionContext *ctx) {

    cerr << "decla function" << endl;
   
    //One CFG and one Symbol Table per fonction (careful : CFG contains the ST in our model)
    IR::CFG * cfg = static_cast<IR::CFG *>(
        (new IR::CFG(ctx->fname->getText()))
        ->set_parent(cfg_set)
    );

    //Update both cfg_set AND current cfg kept as attribute
    cfg_set->add_cfg(cfg);
    this->cfg = cfg;

    int nb_params = ctx->decla_fparam().size();

    cerr << "21" << endl;
    
    //Get parameters from registers into temporary variables
    int stop = nb_params > 6 ? 6 : nb_params;
    int i=0;
    while(i < stop) {
        cerr << "22" << endl;
        IR::Symbol *symbol = this->cfg->get_symbol_table()->declare_symbol(cfg, ctx->decla_fparam(i)->VAR()->getText(), IR::Int, ctx);
        cfg->add_instr(
            (new IR::IRInstrAssign)
                ->set_src(reg_function_params[i])
                ->set_symbol(symbol)
                ->set_ctx(ctx)
        );
        i++;
    }

    cerr << "23" << endl;

    //If more than 6 parameters -> we need to get parameters from the stack
    //Careful : we declare variables with personnalized offset
    int offset = 16;
    for (int i=6 ; i < nb_params ; i++) {
        IR::Symbol *symbol = this->cfg->get_symbol_table()->declare_symbol(cfg, ctx->decla_fparam(i)->VAR()->getText(), IR::Int, ctx);
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
    cerr << "25" << endl;

    //Then only, visit block
    this->visit(ctx->struct_bloc());

    return 0;
}

antlrcpp::Any IRVisitor::visitFunctionCallRule(ifccParser::FunctionCallRuleContext *ctx) {

    cerr << "call function" << endl;

    int nb_params = ctx->fparam().size();
    bool more_6_params = false;
    int cpt_bytes;

    cerr<< "1" << endl;
    cerr<< "nb params : " << nb_params << endl;
    //If there is more than 6 parameters, we place the remaining parameters on top of the stack
    if (nb_params > 6) {
        more_6_params = true;
        cpt_bytes=0;  //bytes to substract from %rsp after the call
        cerr<< "01" << endl;
        for(int i = (nb_params-1); i > 5; i--) {
            cerr<< ctx->fparam(i)->NUM()->getText() << endl;
            cfg->add_instr(
                (new IR::IRInstrPushq)
                    ->set_src((new IR::IRConst)
                            ->set_value(ctx->fparam(i)->NUM()->getText())
                    )
                    ->set_ctx(ctx)
            );
            //TODO : check if always 8 -> btw, why 8 ?
            cpt_bytes += 8;
        }
        cerr << "2" << endl;
    }

    //Put parameters in the dedicated registers -> for 7th parameters and beyond, the method is different
    int i = more_6_params ? 5 : (nb_params-1);
    cerr << i << endl;
    while(i >= 0) {
        cerr << "02" << endl;
        cerr << "02" << endl;
        //If param is a cst
        if (ctx->fparam(i)->NUM()) {
            cerr << "param=cst" << endl;
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(
                        (new IR::IRConst)
                            ->set_value(ctx->fparam(i)->NUM()->getText())
                    )
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        //If it's a variable
        else if (ctx->fparam(i)->VAR()) {
            cerr << "param=var" << endl;
            IR::Symbol* src = cfg->get_symbol_table()->get_symbol(ctx->fparam(i)->VAR()->getText());
            cerr << src->get_asm_str() << endl;
            cfg->add_instr(
                (new IR::IRInstrMov)
                    ->set_src(src)
                    ->set_dest(new IR::IRRegA)
                    ->set_ctx(ctx)
            );
        }
        //If it's an expression
        else {
            cerr << "param=expr" << endl;
            this->visit(ctx->fparam(i));
        }
        cerr << "03" << endl;
        //%eax to available register
        cfg->add_instr(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(reg_function_params[i])
                ->set_ctx(ctx)
        );
        i--;
    }

    cerr << "3" << endl;

    //call instruction
    cfg->add_instr(
        (new IR::IRInstrCall)
            ->set_call(ctx->fname->getText())
            ->set_ctx(ctx)
    );

    cerr << "4" << endl;
    //if more than 6 parameters -> move up %rsp
    if (more_6_params) {
        cfg->add_instr(
            (new IR::IRInstrPushq)
                ->set_src((new IR::IRConst)
                        ->set_value(to_string(cpt_bytes))
                )
                ->set_ctx(ctx)
        );
    }

    cerr << "5" << endl;

    return 0;
}
