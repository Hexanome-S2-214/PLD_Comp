
// Generated from ifcc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual std::any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(ifccParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(ifccParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAffectation(ifccParser::AffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclAff(ifccParser::DeclAffContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprMultDiv(ifccParser::ExprMultDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprNeg(ifccParser::ExprNegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprSousSomme(ifccParser::ExprSousSommeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPar(ifccParser::ExprParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprVar(ifccParser::ExprVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprConst(ifccParser::ExprConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

