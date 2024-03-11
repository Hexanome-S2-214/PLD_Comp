#include "SymbolTableVisitor.h"



antlrcpp::Any SymbolTableVisitor::visitDeclaration(ifccParser::DeclarationContext *ctx) {
    std::string varName = ctx->VAR()->getText();
    if (symbolTable.count(varName) > 0) {
        std::cerr << "Error: Variable " << varName << " is already declared.\n";
        exit(1);
    }
    symbolTable[varName] = {currentIndex, false};
    currentIndex += 4;
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitDeclAff(ifccParser::DeclAffContext *ctx){
    std::string varName = ctx->VAR()->getText();
    if (symbolTable.count(varName) > 0) {
        std::cerr << "Error: Variable " << varName << " is already declared.\n";
        exit(1);
    }
    symbolTable[varName] = {currentIndex, true};
    currentIndex += 4;
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitExprVar(ifccParser::ExprVarContext *ctx){
    std::string varName = ctx->VAR()->getText();
    if (symbolTable.count(varName) == 0) {
        std::cerr << "Error: Variable " << varName << " is not declared.\n";
        exit(1);
    }
    symbolTable[varName].used = true;
    return 0;
}

void SymbolTableVisitor::checkAllVariablesUsed() {
    for (const auto& pair : symbolTable) {
        if (!pair.second.used) {
            std::cerr << "Warning: Variable " << pair.first << " is declared but not used.\n";
        }
    }
}

std::string SymbolTableVisitor::createTempVar(){
    std::string tempVar = "!temp" + std::to_string(currentIndex);
    symbolTable[tempVar] = {currentIndex, true};
    currentIndex += 4;
    return tempVar;
}