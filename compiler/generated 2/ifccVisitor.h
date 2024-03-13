
// Generated from ifcc.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ifccParser.
 */
class  ifccVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ifccParser.
   */
    virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual antlrcpp::Any visitProg(ifccParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(ifccParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitDeclStd(ifccParser::DeclStdContext *context) = 0;

    virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(ifccParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *context) = 0;

    virtual antlrcpp::Any visitDeclStdRule(ifccParser::DeclStdRuleContext *context) = 0;

    virtual antlrcpp::Any visitDeclAffRule(ifccParser::DeclAffRuleContext *context) = 0;

    virtual antlrcpp::Any visitAffectationRule(ifccParser::AffectationRuleContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmtRule(ifccParser::ReturnStmtRuleContext *context) = 0;

    virtual antlrcpp::Any visitExprMultDiv(ifccParser::ExprMultDivContext *context) = 0;

    virtual antlrcpp::Any visitExprNeg(ifccParser::ExprNegContext *context) = 0;

    virtual antlrcpp::Any visitExprSousSomme(ifccParser::ExprSousSommeContext *context) = 0;

    virtual antlrcpp::Any visitExprPar(ifccParser::ExprParContext *context) = 0;

    virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *context) = 0;

    virtual antlrcpp::Any visitExprConst(ifccParser::ExprConstContext *context) = 0;


};

