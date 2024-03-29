#pragma once

#include "antlr4-runtime.h"
#include "../generated/ifccBaseVisitor.h"

#include "ir/ir-cfg-set.h"

class IRVisitor : public ifccBaseVisitor
{
public:
    IRVisitor(IR::CfgSet * cfg_set) : cfg_set(cfg_set) {}

    //To make it easier to manipulate CFGs during visit
    void set_cfg(IR::CFG * cfg) { this->cfg = cfg; }

    virtual antlrcpp::Any visitDeclStdRule(ifccParser::DeclStdRuleContext *ctx) override;
    virtual antlrcpp::Any visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx) override;
    virtual antlrcpp::Any visitAffectationRule(ifccParser::AffectationRuleContext *ctx) override;
    virtual antlrcpp::Any visitAffectationRule2(ifccParser::AffectationRule2Context *ctx) override;

    virtual antlrcpp::Any visitExprCharacter(ifccParser::ExprCharacterContext *ctx) override;
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
    virtual antlrcpp::Any visitStruct_while(ifccParser::Struct_whileContext *ctx) override;

    virtual antlrcpp::Any visitFunctionCallRule(ifccParser::FunctionCallRuleContext *ctx) override;

    virtual antlrcpp::Any visitDecla_function(ifccParser::Decla_functionContext *ctx) override;
private:
    IR::CfgSet * cfg_set;
    IR::CFG * cfg;   //we keep this CFG (be careful : updated during visit) for simplicity in the code
    const vector<IR::IRReg *> reg_function_params = {new IR::IRRegDest, new IR::IRRegSrc, new IR::IRRegD, new IR::IRRegC, new IR::IRReg8, new IR::IRReg9};
};
