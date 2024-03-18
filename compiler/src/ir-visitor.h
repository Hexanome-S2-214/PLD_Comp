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

    virtual antlrcpp::Any visitExprNum(ifccParser::ExprNumContext *ctx) override;
    virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override;

    virtual antlrcpp::Any visitExprSumSous(ifccParser::ExprSumSousContext *ctx) override;
    virtual antlrcpp::Any visitExprMultDivMod(ifccParser::ExprMultDivModContext *ctx) override;

    virtual antlrcpp::Any visitExprUnary(ifccParser::ExprUnaryContext *ctx) override;

    virtual antlrcpp::Any visitExprEqComparaison(ifccParser::ExprEqComparaisonContext *ctx) override;
    virtual antlrcpp::Any visitExprComparaison(ifccParser::ExprComparaisonContext *ctx) override;

    virtual antlrcpp::Any visitExprAndBAB(ifccParser::ExprAndBABContext *ctx) override;
    virtual antlrcpp::Any visitExprXorBAB(ifccParser::ExprXorBABContext *ctx) override;
    virtual antlrcpp::Any visitExprOrBAB(ifccParser::ExprOrBABContext *ctx) override;

    virtual antlrcpp::Any visitStruct_if_else(ifccParser::Struct_if_elseContext *ctx) override;
private:
    IR::CFG * cfg;
};
