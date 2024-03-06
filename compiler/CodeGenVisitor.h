#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"

#include "SymbolTableVisitor.h"

#include <map>
#include <string>

// VAR '=' VAR ';' | VAR '=' CONST ';' ;
class  CodeGenVisitor : public ifccBaseVisitor {
        public:
        SymbolTableVisitor* symbolTableVisitor;

        CodeGenVisitor(SymbolTableVisitor* visitor) : symbolTableVisitor(visitor){};
        virtual antlrcpp::Any visitProg(ifccParser::ProgContext *ctx) override ;
        virtual antlrcpp::Any visitReturn_stmt(ifccParser::Return_stmtContext *ctx) override;
        virtual antlrcpp::Any visitAffectation(ifccParser::AffectationContext *ctx) override;
        virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *ctx) override;

        virtual antlrcpp::Any visitExprPar(ifccParser::ExprParContext *ctx) override;
        virtual antlrcpp::Any visitExprConst(ifccParser::ExprConstContext *ctx) override;
        virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override;
        virtual antlrcpp::Any visitExprSousSomme(ifccParser::ExprSousSommeContext *ctx) override;
        virtual antlrcpp::Any visitExprNeg(ifccParser::ExprNegContext *ctx) override;
        virtual antlrcpp::Any visitExprMultDiv(ifccParser::ExprMultDivContext *ctx) override;
};
