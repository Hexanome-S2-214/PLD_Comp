#include "ir-visitor.h"
#include "ir/ir-cfg.h"
#include "ir/ir-basic-block.h"
#include "ir/instr/assign.h"

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
