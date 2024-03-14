#pragma once

#include "antlr4-runtime.h"
#include "../generated/ifccBaseVisitor.h"

#include "ir/ir-cfg.h"

class IRVisitor : public ifccBaseVisitor
{
public:
    IRVisitor(IR::CFG * cfg) : cfg(cfg) {}

    virtual antlrcpp::Any visitDeclStdRule(ifccParser::DeclStdRuleContext *ctx) override;
    virtual antlrcpp::Any visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx) override;
    virtual antlrcpp::Any visitAffectationRule(ifccParser::AffectationRuleContext *ctx) override;
    // virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *ctx) override;
    // virtual antlrcpp::Any visitExprPar(ifccParser::ExprParContext *ctx) override;
    virtual antlrcpp::Any visitExprConst(ifccParser::ExprConstContext *ctx) override;
    virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override;
    virtual antlrcpp::Any visitExprSousSomme(ifccParser::ExprSousSommeContext *ctx) override;
    virtual antlrcpp::Any visitExprMultDiv(ifccParser::ExprMultDivContext *ctx) override;
    virtual antlrcpp::Any visitExprNeg(ifccParser::ExprNegContext *ctx) override;
private:
    IR::CFG * cfg;
};