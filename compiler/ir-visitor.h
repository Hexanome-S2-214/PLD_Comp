#pragma once

#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

#include "ir/ir-cfg.h"

class IRVisitor : public ifccBaseVisitor
{
public:
    IRVisitor(IR::CFG * cfg) : cfg(cfg) {}

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override;
    virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override;
    // virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *ctx) override;
    // virtual antlrcpp::Any visitExprPar(ifccParser::ExprParContext *ctx) override;
    // virtual antlrcpp::Any visitExprConst(ifccParser::ExprConstContext *ctx) override;
    // virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override;
    // virtual antlrcpp::Any visitExprSousSomme(ifccParser::ExprSousSommeContext *ctx) override;
    virtual antlrcpp::Any visitExprNeg(ifccParser::ExprNegContext *ctx) override;
    // virtual antlrcpp::Any visitExprMultDiv(ifccParser::ExprMultDivContext *ctx) override;
private:
    IR::CFG * cfg;
};
