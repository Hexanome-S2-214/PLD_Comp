#include "ir-visitor.h"
#include "ir/ir-cfg.h"
#include "ir/ir-type.h"
#include "ir/ir-basic-block.h"
#include "ir/instr/assign.h"
#include "ir/instr/expression_neg.h"
#include "ir/instr/expression_cst.h"
#include "ir/instr/expression_var.h"
#include "ir/instr/expression_mult.h"
#include "ir/instr/expression_div.h"

antlrcpp::Any IRVisitor::visitAffectationRule(ifccParser::AffectationRuleContext *ctx)
{
    this->visit(ctx->expr());
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), ctx->VAR()->getText()));
    
    return 0;
}

antlrcpp::Any IRVisitor::visitExprConst(ifccParser::ExprConstContext *ctx){
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprCst(cfg->get_current_bb(), ctx->CONST()->getText()));
    return 0;
}

antlrcpp::Any IRVisitor::visitExprVar(ifccParser::ExprVarContext *ctx){
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprVar(cfg->get_current_bb(), ctx->VAR()->getText()));
    return 0;
}

antlrcpp::Any IRVisitor::visitExprMultDiv(ifccParser::ExprMultDivContext *ctx){
    this->visit(ctx->expr(0));
    IR::Symbol* varTemp = this->cfg->get_symbol_table()->declare_tmp(IR::Int,ctx);
    cfg->get_current_bb()->add_instr(new IR::IRInstrAssign(cfg->get_current_bb(), varTemp->id));  
    this->visit(ctx->expr(1));
    if(ctx->getTokens(ifccParser::MULT).size() > 0)
        cfg->get_current_bb()->add_instr(new IR::IRInstrExprMult(cfg->get_current_bb(), varTemp->id));
    else
        cfg->get_current_bb()->add_instr(new IR::IRInstrExprDiv(cfg->get_current_bb(), varTemp->id));
    return 0;
}

antlrcpp::Any IRVisitor::visitExprNeg(ifccParser::ExprNegContext *ctx)
{
    this->visit(ctx->expr());
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprNeg(cfg->get_current_bb()));
    return 0;
}