#include "ir-visitor.h"
#include "ir/ir-cfg.h"
#include "ir/ir-basic-block.h"
#include "ir/instr/assign.h"
#include "ir/instr/expression_neg.h"
#include "ir/instr/expression_cst.h"
#include "ir/instr/expression_var.h"

antlrcpp::Any IRVisitor::visitProg(ifccParser::ProgContext *ctx)
{
    visit(ctx->statements());
    return 0;
}

antlrcpp::Any IRVisitor::visitAffectation(ifccParser::AffectationContext *ctx)
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
antlrcpp::Any IRVisitor::visitExprNeg(ifccParser::ExprNegContext *ctx)
{
    this->visit(ctx->expr());
    cfg->get_current_bb()->add_instr(new IR::IRInstrExprNeg(cfg->get_current_bb()));
    return 0;
}