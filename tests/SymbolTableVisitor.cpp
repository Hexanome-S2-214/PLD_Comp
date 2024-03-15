#include "SymbolTableVisitor.h"

antlrcpp::Any SymbolTableVisitor::visitDeclStd(ifccParser::DeclStdContext *ctx)
{
    declaration(ctx->declStdRule()->VAR()->getText(), "visitDeclStd");
    return 0;
}

antlrcpp::Any SymbolTableVisitor::visitDeclAff(ifccParser::DeclAffContext *ctx)
{
    this->visit(ctx->declAffRule()->expr()); //Checks if variable exists
    declaration(ctx->declAffRule()->VAR()->getText(), "visitDeclAff");
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

void SymbolTableVisitor::declaration(std::string symbol, std::string callSource)
{
    if(symbolTable.find(symbol) != symbolTable.end()){
        std::cerr << callSource << ": Symbol already declared !" << std::endl;
        exit(1);
    }
    symbolTable[symbol] = {currentIndex, false};
    currentIndex += 4;
}