#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx){
    std::string varName = ctx->affectationRule()->VAR()->getText();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;

    this->visit(ctx->affectationRule()->expr());
    std::cout << "    movl %eax, -"<<varIndex<<"(%rbp)\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclAff(ifccParser::DeclAffContext *ctx){
    std::string varName = ctx->declAffRule()->VAR()->getText();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;
    this->visit(ctx->declAffRule()->expr());
    std::cout << "    movl %eax, -"<<varIndex<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprPar(ifccParser::ExprParContext *ctx){
    return this->visit(ctx->expr());
}

antlrcpp::Any CodeGenVisitor::visitExprNum(ifccParser::ExprNumContext *ctx){
    int value = stoi(ctx->NUM()->getText());
    std::cout << "    movl $"<<value<<", %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprVar(ifccParser::ExprVarContext *ctx){
    std::string varName = ctx->VAR()->getText();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;
    std::cout << "    movl -"<<varIndex<<"(%rbp), %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprSousSomme(ifccParser::ExprSousSommeContext *ctx){
    this->visit(ctx->expr(0));
    std::string varName = symbolTableVisitor->createTempVar();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;
    std::cout << "    movl %eax, -"<<varIndex<<"(%rbp)\n";
    this->visit(ctx->expr(1));

    if(ctx->getTokens(ifccParser::PLUS).size() > 0){
        std::cout << "    addl -"<<varIndex<<"(%rbp), %eax\n";
    }else if(ctx->getTokens(ifccParser::MINUS).size() > 0){
        std::cout << "    movl %eax, %edx\n";
        std::cout << "    movl -"<<varIndex<<"(%rbp), %eax\n";
        std::cout << "    subl %edx, %eax\n";
    }

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprNeg(ifccParser::ExprNegContext *ctx){
    this->visit(ctx->expr());
    std::cout << "    negl %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprMultDiv(ifccParser::ExprMultDivContext *ctx){
    this->visit(ctx->expr(0));
    std::string varName = symbolTableVisitor->createTempVar();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;
    std::cout << "    movl %eax, -"<<varIndex<<"(%rbp)\n";
    this->visit(ctx->expr(1));
    
    if(ctx->getTokens(ifccParser::MULT).size() > 0){
        std::cout << "    imull -"<<varIndex<<"(%rbp), %eax\n";
    }else if(ctx->getTokens(ifccParser::DIV).size() > 0){
        std::cout << "    movl %eax, %ecx\n";
        std::cout << "    movl -"<<varIndex<<"(%rbp), %eax\n";
        std::cout << "    cltd\n";
        std::cout << "    idivl %ecx\n";
    }

    return 0;
}
