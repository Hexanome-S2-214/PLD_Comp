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
#include "ir/instr/comp.h"
#include "ir/instr/movzbl.h"
#include "ir/instr/set_flag_comp.h"
#include "ir/instr/expression_bit_a_bit.h"

////////////////////////////////////////////
// DECLARATION/AFFECTATION
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitDeclStdRule(ifccParser::DeclStdRuleContext *ctx)
{
    cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Int, ctx);
    return 0;
}

antlrcpp::Any IRVisitor::visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx)
{
    this->visit(ctx->rvalue());

    cfg->get_symbol_table()->declare_symbol(cfg, ctx->VAR()->getText(), IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(ctx->VAR()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitAffectationRule(ifccParser::AffectationRuleContext *ctx)
{
    this->visit(ctx->rvalue());
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(ctx->VAR()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}

////////////////////////////////////////////
// EXPRESSIONS TERMINALES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprNum(ifccParser::ExprNumContext *ctx){
    cfg->add_instr(
        (new IR::IRInstrExprCst)
            ->set_value(ctx->NUM()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprVar(ifccParser::ExprVarContext *ctx)
{
    cfg->add_instr(
        (new IR::IRInstrExprVar)
            ->set_id(ctx->VAR()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}

////////////////////////////////////////////
// OPERATIONS ARITHMETIQUES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprSomme(ifccParser::ExprSommeContext *ctx) {
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );

    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprPlus)
            ->set_src(varTemp->get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprSoustr(ifccParser::ExprSoustrContext *ctx) {
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );

    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(IR::IRRegA(cfg).get_asm_str())
            ->set_dest(IR::IRRegB(cfg).get_asm_str())
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(varTemp->get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_ctx(ctx)
    );
    cfg->add_instr(
        (new IR::IRInstrExprMinus)
            ->set_src(IR::IRRegB(cfg).get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprMultDiv(ifccParser::ExprMultDivContext *ctx)
{
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    if (ctx->OP_MULT()->getText() == "*")
        cfg->add_instr(
            (new IR::IRInstrExprMult)
                ->set_src(varTemp->get_asm_str())
                ->set_dest(IR::IRRegA(cfg).get_asm_str())
                ->set_ctx(ctx)
        );
    else
        cfg->add_instr(
            (new IR::IRInstrExprDiv)
                ->set_src(varTemp->get_asm_str())
                ->set_ctx(ctx)
        );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprModulo(ifccParser::ExprModuloContext *ctx) {
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprDiv)
            ->set_src(varTemp->get_asm_str())
            ->set_ctx(ctx)
    );
    //il faut mettre EDX dans EAX -> c'est ce registre qui contient le reste après idivl
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(IR::IRRegD(cfg).get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    return 0;
}

////////////////////////////////////////////
// OPERATEURS UNAIRES
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprUnaryMinus(ifccParser::ExprUnaryMinusContext *ctx)
{
    this->visit(ctx->expr());

    cfg->add_instr(
        (new IR::IRInstrExprUnaryMinus)
            ->set_ctx(ctx)
    );

    return 0;
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
            ->set_src(IR::IRRegA(cfg).get_asm_str())
            ->set_dest(IR::IRRegC(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    //évaluation à droite
    this->visit(ctx->expr(1));

    //comparaison EAX (droite) et ECX (gauche)
    cfg->add_instr(
        (new IR::IRInstrComp)
            ->set_src(IR::IRRegA(cfg).get_asm_str())
            ->set_dest(IR::IRRegC(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    //résultat de la comparaison dans EAX
    cfg->add_instr(
        (new IR::IRInstrSetFlagComp)
            ->set_symbol(ctx->EQ_COMPARAISON()->getText())
            ->set_dest(IR::IRRegAL(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    cfg->add_instr(
        (new IR::IRInstrMovzbl)
            ->set_src(IR::IRRegAL(cfg).get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprComparaison(ifccParser::ExprComparaisonContext *ctx) {
    
    //évaluation à gauche
    this->visit(ctx->expr(0));

    //on stocke dans ECX
    cfg->add_instr(
        (new IR::IRInstrMov)
            ->set_src(IR::IRRegA(cfg).get_asm_str())
            ->set_dest(IR::IRRegC(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    //évaluation à droite
    this->visit(ctx->expr(1));

    //comparaison EAX (droite) et ECX (gauche)
    cfg->add_instr(
        (new IR::IRInstrComp)
            ->set_src(IR::IRRegA(cfg).get_asm_str())
            ->set_dest(IR::IRRegC(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    //résultat de la comparaison dans EAX
    cfg->add_instr(
        (new IR::IRInstrSetFlagComp)
            ->set_symbol(ctx->COMPARAISON()->getText())
            ->set_dest(IR::IRRegAL(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    cfg->add_instr(
        (new IR::IRInstrMovzbl)
            ->set_src(IR::IRRegAL(cfg).get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_ctx(ctx)
    );

    return 0;
}

////////////////////////////////////////////
// OPERATEURS BIT-A-BIT
////////////////////////////////////////////

antlrcpp::Any IRVisitor::visitExprAndBAB(ifccParser::ExprAndBABContext *ctx) {

    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp->get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_symbol(ctx->B_AND()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprXorBAB(ifccParser::ExprXorBABContext *ctx) {
    
    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp->get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_symbol(ctx->B_XOR()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}

antlrcpp::Any IRVisitor::visitExprOrBAB(ifccParser::ExprOrBABContext *ctx) {

    this->visit(ctx->expr(0));

    IR::Symbol *varTemp = this->cfg->get_symbol_table()->declare_tmp(cfg, IR::Int, ctx);
    cfg->add_instr(
        (new IR::IRInstrAssign)
            ->set_id(varTemp->id)
            ->set_ctx(ctx)
    );
    
    this->visit(ctx->expr(1));

    cfg->add_instr(
        (new IR::IRInstrExprBitABit)
            ->set_src(varTemp->get_asm_str())
            ->set_dest(IR::IRRegA(cfg).get_asm_str())
            ->set_symbol(ctx->B_OR()->getText())
            ->set_ctx(ctx)
    );

    return 0;
}