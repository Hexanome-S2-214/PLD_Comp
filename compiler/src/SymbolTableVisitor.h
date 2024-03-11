#pragma once


#include "antlr4-runtime.h"
#include "generated/ifccBaseVisitor.h"
#include "VariableInfo.h"

#include <map>
#include <string>

class SymbolTableVisitor  : public ifccBaseVisitor {
    private:
        int currentIndex = 4;

    public:
        std::map<std::string, VariableInfo> symbolTable;

        virtual antlrcpp::Any visitDeclaration(ifccParser::DeclarationContext *ctx) override;
        virtual antlrcpp::Any visitDeclAff(ifccParser::DeclAffContext *ctx) override;
        virtual antlrcpp::Any visitExprVar(ifccParser::ExprVarContext *ctx) override;
        void checkAllVariablesUsed();
        std::string createTempVar();
};