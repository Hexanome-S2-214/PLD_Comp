#include "ir-visitor.h"
#include "ir/ir-cfg.h"
#include "ir/ir-basic-block.h"
#include "ir/instr/assign.h"
#include "ir/instr/expression_cst.h"

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