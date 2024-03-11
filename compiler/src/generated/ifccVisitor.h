
// Generated from ifcc.g4 by ANTLR 4.10.1

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
    virtual std::any visitAxiom(ifccParser::AxiomContext *context) = 0;

    virtual std::any visitProg(ifccParser::ProgContext *context) = 0;

    virtual std::any visitStatements(ifccParser::StatementsContext *context) = 0;

    virtual std::any visitStatement(ifccParser::StatementContext *context) = 0;

    virtual std::any visitDeclaration(ifccParser::DeclarationContext *context) = 0;

    virtual std::any visitAffectation(ifccParser::AffectationContext *context) = 0;

    virtual std::any visitReturn_stmt(ifccParser::Return_stmtContext *context) = 0;

    virtual std::any visitDeclAff(ifccParser::DeclAffContext *context) = 0;

    virtual std::any visitExprMultDiv(ifccParser::ExprMultDivContext *context) = 0;

    virtual std::any visitExprNeg(ifccParser::ExprNegContext *context) = 0;

    virtual std::any visitExprSousSomme(ifccParser::ExprSousSommeContext *context) = 0;

    virtual std::any visitExprPar(ifccParser::ExprParContext *context) = 0;

    virtual std::any visitExprVar(ifccParser::ExprVarContext *context) = 0;

    virtual std::any visitExprConst(ifccParser::ExprConstContext *context) = 0;


};

