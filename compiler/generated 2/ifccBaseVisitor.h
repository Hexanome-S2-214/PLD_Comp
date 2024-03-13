
// Generated from ifcc.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "ifccVisitor.h"


/**
 * This class provides an empty implementation of ifccVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ifccBaseVisitor : public ifccVisitor {
public:

  virtual antlrcpp::Any visitAxiom(ifccParser::AxiomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(ifccParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclStd(ifccParser::DeclStdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(ifccParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclStdRule(ifccParser::DeclStdRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclAffRule(ifccParser::DeclAffRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectationRule(ifccParser::AffectationRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmtRule(ifccParser::ReturnStmtRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMultDiv(ifccParser::ExprMultDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprNeg(ifccParser::ExprNegContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprSousSomme(ifccParser::ExprSousSommeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprPar(ifccParser::ExprParContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprConst(ifccParser::ExprConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

