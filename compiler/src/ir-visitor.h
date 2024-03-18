#pragma once

#include "antlr4-runtime.h"
#include "../generated/ifccBaseVisitor.h"

#include "ir/ir-cfg.h"

class IRVisitor : public ifccBaseVisitor
{
public:
    IRVisitor(IR::CFG * cfg) : cfg(cfg) {}

    virtual antlrcpp::Any visitSimpleDecl(ifccParser::SimpleDeclContext *ctx) override;
    virtual antlrcpp::Any visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx) override;
    virtual antlrcpp::Any visitTableDecl(ifccParser::TableDeclContext *ctx) override;
    virtual antlrcpp::Any visitSimpleAff(ifccParser::SimpleAffContext *ctx) override;
    virtual antlrcpp::Any visitTableAff(ifccParser::TableAffContext *ctx) override;
    // virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *ctx) override;
    // virtual antlrcpp::Any visitExprPar(ifccParser::ExprParContext *ctx) override;

    virtual antlrcpp::Any visitExprNum(ifccParser::ExprNumContext *ctx) override;
    virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override;

    virtual antlrcpp::Any visitExprSomme(ifccParser::ExprSommeContext *ctx) override;
    virtual antlrcpp::Any visitExprSoustr(ifccParser::ExprSoustrContext *ctx) override;
    virtual antlrcpp::Any visitExprMultDiv(ifccParser::ExprMultDivContext *ctx) override;
    virtual antlrcpp::Any visitExprModulo(ifccParser::ExprModuloContext *ctx) override;

    virtual antlrcpp::Any visitExprUnaryMinus(ifccParser::ExprUnaryMinusContext *ctx) override;
private:
    IR::CFG * cfg;
};
