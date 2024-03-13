
// Generated from ifcc.g4 by ANTLR 4.9.2


#include "ifccVisitor.h"

#include "ifccParser.h"


using namespace antlrcpp;
using namespace antlr4;

ifccParser::ifccParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ifccParser::~ifccParser() {
  delete _interpreter;
}

std::string ifccParser::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ifccParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- AxiomContext ------------------------------------------------------------------

ifccParser::AxiomContext::AxiomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ifccParser::ProgContext* ifccParser::AxiomContext::prog() {
  return getRuleContext<ifccParser::ProgContext>(0);
}

tree::TerminalNode* ifccParser::AxiomContext::EOF() {
  return getToken(ifccParser::EOF, 0);
}


size_t ifccParser::AxiomContext::getRuleIndex() const {
  return ifccParser::RuleAxiom;
}


antlrcpp::Any ifccParser::AxiomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAxiom(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AxiomContext* ifccParser::axiom() {
  AxiomContext *_localctx = _tracker.createInstance<AxiomContext>(_ctx, getState());
  enterRule(_localctx, 0, ifccParser::RuleAxiom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(20);
    prog();
    setState(21);
    match(ifccParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgContext ------------------------------------------------------------------

ifccParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ifccParser::StatementContext *> ifccParser::ProgContext::statement() {
  return getRuleContexts<ifccParser::StatementContext>();
}

ifccParser::StatementContext* ifccParser::ProgContext::statement(size_t i) {
  return getRuleContext<ifccParser::StatementContext>(i);
}


size_t ifccParser::ProgContext::getRuleIndex() const {
  return ifccParser::RuleProg;
}


antlrcpp::Any ifccParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ProgContext* ifccParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 2, ifccParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23);
    match(ifccParser::T__0);
    setState(24);
    match(ifccParser::T__1);
    setState(25);
    match(ifccParser::T__2);
    setState(26);
    match(ifccParser::T__3);
    setState(27);
    match(ifccParser::T__4);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ifccParser::T__0)
      | (1ULL << ifccParser::RETURN)
      | (1ULL << ifccParser::VAR))) != 0)) {
      setState(28);
      statement();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
    match(ifccParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ifccParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::StatementContext::getRuleIndex() const {
  return ifccParser::RuleStatement;
}

void ifccParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InstructionContext ------------------------------------------------------------------

ifccParser::InstructionRuleContext* ifccParser::InstructionContext::instructionRule() {
  return getRuleContext<ifccParser::InstructionRuleContext>(0);
}

ifccParser::InstructionContext::InstructionContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationContext ------------------------------------------------------------------

ifccParser::DeclarationRuleContext* ifccParser::DeclarationContext::declarationRule() {
  return getRuleContext<ifccParser::DeclarationRuleContext>(0);
}

ifccParser::DeclarationContext::DeclarationContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::StatementContext* ifccParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, ifccParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(38);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__0: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::DeclarationContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(36);
        declarationRule();
        break;
      }

      case ifccParser::RETURN:
      case ifccParser::VAR: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ifccParser::InstructionContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(37);
        instructionRule();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationRuleContext ------------------------------------------------------------------

ifccParser::DeclarationRuleContext::DeclarationRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::DeclarationRuleContext::getRuleIndex() const {
  return ifccParser::RuleDeclarationRule;
}

void ifccParser::DeclarationRuleContext::copyFrom(DeclarationRuleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclStdContext ------------------------------------------------------------------

ifccParser::DeclStdRuleContext* ifccParser::DeclStdContext::declStdRule() {
  return getRuleContext<ifccParser::DeclStdRuleContext>(0);
}

ifccParser::DeclStdContext::DeclStdContext(DeclarationRuleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::DeclStdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclStd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclAffContext ------------------------------------------------------------------

ifccParser::DeclAffRuleContext* ifccParser::DeclAffContext::declAffRule() {
  return getRuleContext<ifccParser::DeclAffRuleContext>(0);
}

ifccParser::DeclAffContext::DeclAffContext(DeclarationRuleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::DeclAffContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclAff(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::DeclarationRuleContext* ifccParser::declarationRule() {
  DeclarationRuleContext *_localctx = _tracker.createInstance<DeclarationRuleContext>(_ctx, getState());
  enterRule(_localctx, 6, ifccParser::RuleDeclarationRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationRuleContext *>(_tracker.createInstance<ifccParser::DeclStdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(40);
      declStdRule();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationRuleContext *>(_tracker.createInstance<ifccParser::DeclAffContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(41);
      declAffRule();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionRuleContext ------------------------------------------------------------------

ifccParser::InstructionRuleContext::InstructionRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::InstructionRuleContext::getRuleIndex() const {
  return ifccParser::RuleInstructionRule;
}

void ifccParser::InstructionRuleContext::copyFrom(InstructionRuleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

ifccParser::ReturnStmtRuleContext* ifccParser::ReturnStmtContext::returnStmtRule() {
  return getRuleContext<ifccParser::ReturnStmtRuleContext>(0);
}

ifccParser::ReturnStmtContext::ReturnStmtContext(InstructionRuleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AffectationContext ------------------------------------------------------------------

ifccParser::AffectationRuleContext* ifccParser::AffectationContext::affectationRule() {
  return getRuleContext<ifccParser::AffectationRuleContext>(0);
}

ifccParser::AffectationContext::AffectationContext(InstructionRuleContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::AffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectation(this);
  else
    return visitor->visitChildren(this);
}
ifccParser::InstructionRuleContext* ifccParser::instructionRule() {
  InstructionRuleContext *_localctx = _tracker.createInstance<InstructionRuleContext>(_ctx, getState());
  enterRule(_localctx, 8, ifccParser::RuleInstructionRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::RETURN: {
        _localctx = dynamic_cast<InstructionRuleContext *>(_tracker.createInstance<ifccParser::ReturnStmtContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(44);
        returnStmtRule();
        break;
      }

      case ifccParser::VAR: {
        _localctx = dynamic_cast<InstructionRuleContext *>(_tracker.createInstance<ifccParser::AffectationContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(45);
        affectationRule();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclStdRuleContext ------------------------------------------------------------------

ifccParser::DeclStdRuleContext::DeclStdRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::DeclStdRuleContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}


size_t ifccParser::DeclStdRuleContext::getRuleIndex() const {
  return ifccParser::RuleDeclStdRule;
}


antlrcpp::Any ifccParser::DeclStdRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclStdRule(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::DeclStdRuleContext* ifccParser::declStdRule() {
  DeclStdRuleContext *_localctx = _tracker.createInstance<DeclStdRuleContext>(_ctx, getState());
  enterRule(_localctx, 10, ifccParser::RuleDeclStdRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(ifccParser::T__0);
    setState(49);
    match(ifccParser::VAR);
    setState(50);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclAffRuleContext ------------------------------------------------------------------

ifccParser::DeclAffRuleContext::DeclAffRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::DeclAffRuleContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExprContext* ifccParser::DeclAffRuleContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::DeclAffRuleContext::getRuleIndex() const {
  return ifccParser::RuleDeclAffRule;
}


antlrcpp::Any ifccParser::DeclAffRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitDeclAffRule(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::DeclAffRuleContext* ifccParser::declAffRule() {
  DeclAffRuleContext *_localctx = _tracker.createInstance<DeclAffRuleContext>(_ctx, getState());
  enterRule(_localctx, 12, ifccParser::RuleDeclAffRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(ifccParser::T__0);
    setState(53);
    match(ifccParser::VAR);
    setState(54);
    match(ifccParser::T__7);
    setState(55);
    expr(0);
    setState(56);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AffectationRuleContext ------------------------------------------------------------------

ifccParser::AffectationRuleContext::AffectationRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::AffectationRuleContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExprContext* ifccParser::AffectationRuleContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::AffectationRuleContext::getRuleIndex() const {
  return ifccParser::RuleAffectationRule;
}


antlrcpp::Any ifccParser::AffectationRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitAffectationRule(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::AffectationRuleContext* ifccParser::affectationRule() {
  AffectationRuleContext *_localctx = _tracker.createInstance<AffectationRuleContext>(_ctx, getState());
  enterRule(_localctx, 14, ifccParser::RuleAffectationRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(ifccParser::VAR);
    setState(59);
    match(ifccParser::T__7);
    setState(60);
    expr(0);
    setState(61);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtRuleContext ------------------------------------------------------------------

ifccParser::ReturnStmtRuleContext::ReturnStmtRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ifccParser::ReturnStmtRuleContext::RETURN() {
  return getToken(ifccParser::RETURN, 0);
}

ifccParser::ExprContext* ifccParser::ReturnStmtRuleContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}


size_t ifccParser::ReturnStmtRuleContext::getRuleIndex() const {
  return ifccParser::RuleReturnStmtRule;
}


antlrcpp::Any ifccParser::ReturnStmtRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitReturnStmtRule(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ReturnStmtRuleContext* ifccParser::returnStmtRule() {
  ReturnStmtRuleContext *_localctx = _tracker.createInstance<ReturnStmtRuleContext>(_ctx, getState());
  enterRule(_localctx, 16, ifccParser::RuleReturnStmtRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(ifccParser::RETURN);
    setState(64);
    expr(0);
    setState(65);
    match(ifccParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ifccParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ifccParser::ExprContext::getRuleIndex() const {
  return ifccParser::RuleExpr;
}

void ifccParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprMultDivContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::ExprMultDivContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::ExprMultDivContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::ExprMultDivContext::MULT() {
  return getToken(ifccParser::MULT, 0);
}

tree::TerminalNode* ifccParser::ExprMultDivContext::DIV() {
  return getToken(ifccParser::DIV, 0);
}

ifccParser::ExprMultDivContext::ExprMultDivContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ExprMultDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprMultDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprNegContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ExprNegContext::MINUS() {
  return getToken(ifccParser::MINUS, 0);
}

ifccParser::ExprContext* ifccParser::ExprNegContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ExprNegContext::ExprNegContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ExprNegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprNeg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprSousSommeContext ------------------------------------------------------------------

std::vector<ifccParser::ExprContext *> ifccParser::ExprSousSommeContext::expr() {
  return getRuleContexts<ifccParser::ExprContext>();
}

ifccParser::ExprContext* ifccParser::ExprSousSommeContext::expr(size_t i) {
  return getRuleContext<ifccParser::ExprContext>(i);
}

tree::TerminalNode* ifccParser::ExprSousSommeContext::PLUS() {
  return getToken(ifccParser::PLUS, 0);
}

tree::TerminalNode* ifccParser::ExprSousSommeContext::MINUS() {
  return getToken(ifccParser::MINUS, 0);
}

ifccParser::ExprSousSommeContext::ExprSousSommeContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ExprSousSommeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprSousSomme(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParContext ------------------------------------------------------------------

ifccParser::ExprContext* ifccParser::ExprParContext::expr() {
  return getRuleContext<ifccParser::ExprContext>(0);
}

ifccParser::ExprParContext::ExprParContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ExprParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ExprVarContext::VAR() {
  return getToken(ifccParser::VAR, 0);
}

ifccParser::ExprVarContext::ExprVarContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprConstContext ------------------------------------------------------------------

tree::TerminalNode* ifccParser::ExprConstContext::CONST() {
  return getToken(ifccParser::CONST, 0);
}

ifccParser::ExprConstContext::ExprConstContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ifccParser::ExprConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ifccVisitor*>(visitor))
    return parserVisitor->visitExprConst(this);
  else
    return visitor->visitChildren(this);
}

ifccParser::ExprContext* ifccParser::expr() {
   return expr(0);
}

ifccParser::ExprContext* ifccParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ifccParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ifccParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, ifccParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ifccParser::T__2: {
        _localctx = _tracker.createInstance<ExprParContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(68);
        match(ifccParser::T__2);
        setState(69);
        expr(0);
        setState(70);
        match(ifccParser::T__3);
        break;
      }

      case ifccParser::MINUS: {
        _localctx = _tracker.createInstance<ExprNegContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(72);
        match(ifccParser::MINUS);
        setState(73);
        expr(5);
        break;
      }

      case ifccParser::VAR: {
        _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(74);
        match(ifccParser::VAR);
        break;
      }

      case ifccParser::CONST: {
        _localctx = _tracker.createInstance<ExprConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(75);
        match(ifccParser::CONST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(86);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(84);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMultDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(78);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(79);
          _la = _input->LA(1);
          if (!(_la == ifccParser::MULT

          || _la == ifccParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(80);
          expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprSousSommeContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(81);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(82);
          _la = _input->LA(1);
          if (!(_la == ifccParser::PLUS

          || _la == ifccParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(83);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ifccParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ifccParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ifccParser::_decisionToDFA;
atn::PredictionContextCache ifccParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ifccParser::_atn;
std::vector<uint16_t> ifccParser::_serializedATN;

std::vector<std::string> ifccParser::_ruleNames = {
  "axiom", "prog", "statement", "declarationRule", "instructionRule", "declStdRule", 
  "declAffRule", "affectationRule", "returnStmtRule", "expr"
};

std::vector<std::string> ifccParser::_literalNames = {
  "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'return'", 
  "", "", "", "", "", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> ifccParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "RETURN", "CONST", "VAR", "COMMENT", 
  "DIRECTIVE", "WS", "MULT", "DIV", "PLUS", "MINUS"
};

dfa::Vocabulary ifccParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ifccParser::_tokenNames;

ifccParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x14, 0x5c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x20, 0xa, 
       0x3, 0xc, 0x3, 0xe, 0x3, 0x23, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x29, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0x2d, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x31, 0xa, 0x6, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x4f, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x57, 0xa, 0xb, 
       0xc, 0xb, 0xe, 0xb, 0x5a, 0xb, 0xb, 0x3, 0xb, 0x2, 0x3, 0x14, 0xc, 
       0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 0x4, 0x3, 
       0x2, 0x11, 0x12, 0x3, 0x2, 0x13, 0x14, 0x2, 0x5a, 0x2, 0x16, 0x3, 
       0x2, 0x2, 0x2, 0x4, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 
       0x2, 0x2, 0x8, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x30, 0x3, 0x2, 0x2, 
       0x2, 0xc, 0x32, 0x3, 0x2, 0x2, 0x2, 0xe, 0x36, 0x3, 0x2, 0x2, 0x2, 
       0x10, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x41, 0x3, 0x2, 0x2, 0x2, 0x14, 
       0x4e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x5, 0x4, 0x3, 0x2, 0x17, 0x18, 
       0x7, 0x2, 0x2, 0x3, 0x18, 0x3, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 
       0x3, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x4, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0x5, 
       0x2, 0x2, 0x1c, 0x1d, 0x7, 0x6, 0x2, 0x2, 0x1d, 0x21, 0x7, 0x7, 0x2, 
       0x2, 0x1e, 0x20, 0x5, 0x6, 0x4, 0x2, 0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 
       0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 
       0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 0x7, 0x8, 0x2, 0x2, 0x25, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0x29, 0x5, 0x8, 0x5, 0x2, 0x27, 0x29, 0x5, 0xa, 
       0x6, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 
       0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x5, 0xc, 0x7, 0x2, 
       0x2b, 0x2d, 0x5, 0xe, 0x8, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 
       0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 
       0x5, 0x12, 0xa, 0x2, 0x2f, 0x31, 0x5, 0x10, 0x9, 0x2, 0x30, 0x2e, 
       0x3, 0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0xb, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x33, 0x7, 0x3, 0x2, 0x2, 0x33, 0x34, 0x7, 0xd, 
       0x2, 0x2, 0x34, 0x35, 0x7, 0x9, 0x2, 0x2, 0x35, 0xd, 0x3, 0x2, 0x2, 
       0x2, 0x36, 0x37, 0x7, 0x3, 0x2, 0x2, 0x37, 0x38, 0x7, 0xd, 0x2, 0x2, 
       0x38, 0x39, 0x7, 0xa, 0x2, 0x2, 0x39, 0x3a, 0x5, 0x14, 0xb, 0x2, 
       0x3a, 0x3b, 0x7, 0x9, 0x2, 0x2, 0x3b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3c, 
       0x3d, 0x7, 0xd, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0xa, 0x2, 0x2, 0x3e, 0x3f, 
       0x5, 0x14, 0xb, 0x2, 0x3f, 0x40, 0x7, 0x9, 0x2, 0x2, 0x40, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xb, 0x2, 0x2, 0x42, 0x43, 0x5, 
       0x14, 0xb, 0x2, 0x43, 0x44, 0x7, 0x9, 0x2, 0x2, 0x44, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0x45, 0x46, 0x8, 0xb, 0x1, 0x2, 0x46, 0x47, 0x7, 0x5, 
       0x2, 0x2, 0x47, 0x48, 0x5, 0x14, 0xb, 0x2, 0x48, 0x49, 0x7, 0x6, 
       0x2, 0x2, 0x49, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x14, 
       0x2, 0x2, 0x4b, 0x4f, 0x5, 0x14, 0xb, 0x7, 0x4c, 0x4f, 0x7, 0xd, 
       0x2, 0x2, 0x4d, 0x4f, 0x7, 0xc, 0x2, 0x2, 0x4e, 0x45, 0x3, 0x2, 0x2, 
       0x2, 0x4e, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
       0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x58, 0x3, 0x2, 0x2, 0x2, 0x50, 
       0x51, 0xc, 0x6, 0x2, 0x2, 0x51, 0x52, 0x9, 0x2, 0x2, 0x2, 0x52, 0x57, 
       0x5, 0x14, 0xb, 0x7, 0x53, 0x54, 0xc, 0x5, 0x2, 0x2, 0x54, 0x55, 
       0x9, 0x3, 0x2, 0x2, 0x55, 0x57, 0x5, 0x14, 0xb, 0x6, 0x56, 0x50, 
       0x3, 0x2, 0x2, 0x2, 0x56, 0x53, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 
       0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 
       0x2, 0x2, 0x59, 0x15, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 
       0x2, 0x9, 0x21, 0x28, 0x2c, 0x30, 0x4e, 0x56, 0x58, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ifccParser::Initializer ifccParser::_init;
