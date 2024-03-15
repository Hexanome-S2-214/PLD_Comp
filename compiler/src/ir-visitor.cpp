#include "ir-visitor.h"
#include "ir/ir-type.h"
#include "ir/ir-cfg.h"
#include "ir/ir-type.h"
#include "ir/ir-basic-block.h"
#include "ir/ir-reg.h"
#include "ir/instr/assign.h"
#include "ir/instr/expression_unary_minus.h"
#include "ir/instr/expression_cst.h"
#include "ir/instr/expression_var.h"
#include "ir/instr/expression_mult.h"
#include "ir/instr/expression_div.h"
#include "ir/instr/expression_plus.h"
#include "ir/instr/expression_minus.h"
#include "ir/instr/mov.h"

////////////////////////////////////////////
// DECLARATION/AFFECTATION
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitDeclStdRule(ifccParser::DeclStdRuleContext *ctx)
{
    cfg->get_symbol_table()->declare_symbol(ctx->VAR()->getText(), IR::Int, ctx);
    return 0;
}

antlrcpp::Any IRVisitor::visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx)
{
    this->visit(ctx->rvalue());
    cfg->get_symbol_table()->declare_symbol(ctx->VAR()->getText(), IR::Int, ctx);
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), ctx->VAR()->getText()));
    return 0;
}

antlrcpp::Any IRVisitor::visitAffectationRule(ifccParser::AffectationRuleContext *ctx)
{
    this->visit(ctx->rvalue());
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), ctx->VAR()->getText()));
    
    return 0;
}

////////////////////////////////////////////
// EXPRESSIONS TERMINALES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprNum(ifccParser::ExprNumContext *ctx){
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprCst(cfg->get_current_bb(), ctx->NUM()->getText()));
    return 0;
}

antlrcpp::Any IRVisitor::visitExprVar(ifccParser::ExprVarContext *ctx){
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprVar(cfg->get_current_bb(), ctx->VAR()->getText()));
    return 0;
}

////////////////////////////////////////////
// OPERATIONS ARITHMETIQUES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprSomme(ifccParser::ExprSommeContext *ctx){
    this->visit(ctx->expr(0));
    IR::Symbol* varTemp = this->cfg->get_symbol_table()->declare_tmp(IR::Int,ctx);
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), varTemp->id));  
    this->visit(ctx->expr(1));
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprPlus(cfg->get_current_bb(), varTemp->get_asm_str(), IR::IRRegA().get_asm_str()));
    
    return 0;
}

antlrcpp::Any IRVisitor::visitExprSoustr(ifccParser::ExprSoustrContext *ctx) {
    this->visit(ctx->expr(0));
    IR::Symbol* varTemp = this->cfg->get_symbol_table()->declare_tmp(IR::Int,ctx);
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), varTemp->id));  
    this->visit(ctx->expr(1));

    cfg->get_current_bb()->add_instr(new IR::IRInstrMov(cfg->get_current_bb(), IR::IRRegA().get_asm_str(), IR::IRRegB().get_asm_str()));
    cfg->get_current_bb()->add_instr(new IR::IRInstrMov(cfg->get_current_bb(), varTemp->get_asm_str(), IR::IRRegA().get_asm_str()));
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprMinus(cfg->get_current_bb(), IR::IRRegB().get_asm_str(), IR::IRRegA().get_asm_str()));

    return 0;
}

antlrcpp::Any IRVisitor::visitExprMultDiv(ifccParser::ExprMultDivContext *ctx){
    this->visit(ctx->expr(0));
    IR::Symbol* varTemp = this->cfg->get_symbol_table()->declare_tmp(IR::Int,ctx);
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), varTemp->id));  
    this->visit(ctx->expr(1));

    if(ctx->OP_MULT()->getText() == "*")
        cfg->get_current_bb()->add_instr(new IR::IRInstrExprMult(cfg->get_current_bb(), varTemp->get_asm_str(), IR::IRRegA().get_asm_str()));
    else
        cfg->get_current_bb()->add_instr(new IR::IRInstrExprDiv(cfg->get_current_bb(), varTemp->get_asm_str()));
        
    return 0;
}

antlrcpp::Any IRVisitor::visitExprModulo(ifccParser::ExprModuloContext *ctx) {
    this->visit(ctx->expr(0));
    IR::Symbol* varTemp = this->cfg->get_symbol_table()->declare_tmp(IR::Int,ctx);
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), varTemp->id));
    this->visit(ctx->expr(1));

    cfg->get_current_bb()->add_instr(new IR::IRInstrExprDiv(cfg->get_current_bb(), varTemp->get_asm_str()));

    //il faut mettre EDX dans EAX -> c'est ce registre qui contient le reste après idivl
    cfg->get_current_bb()->add_instr(new IR::IRInstrMov(cfg->get_current_bb(), IR::IRRegD().get_asm_str(), IR::IRRegA().get_asm_str()));

    return 0;
}

////////////////////////////////////////////
// OPERATEURS UNAIRES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprUnaryMinus(ifccParser::ExprUnaryMinusContext *ctx)
{
    this->visit(ctx->expr());
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprUnaryMinus(cfg->get_current_bb()));
    return 0;
}