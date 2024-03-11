#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
    std::cout<< ".globl _main\n" ;
    std::cout<< " _main: \n" ;
    std::cout<< "    # prologue\n" ;
    std::cout<< "    pushq %rbp\n" ;
    std::cout<< "    movq %rsp, %rbp\n" ;

    this->visit( ctx->statements() );
    
    std::cout << "    # epilogue\n";
    std::cout << "    popq %rbp\n";
    std::cout << "    ret\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitAffectation(ifccParser::AffectationContext *ctx){
    std::string varName = ctx->VAR()->getText();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;

    this->visit(ctx->expr());
    std::cout << "    movl %eax, -"<<varIndex<<"(%rbp)\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclAff(ifccParser::DeclAffContext *ctx){
    std::string varName = ctx->VAR()->getText();
    int varIndex = symbolTableVisitor->symbolTable[varName].index;
    this->visit(ctx->expr());
    std::cout << "    movl %eax, -"<<varIndex<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitExprPar(ifccParser::ExprParContext *ctx){
    return this->visit(ctx->expr());
}

antlrcpp::Any CodeGenVisitor::visitExprConst(ifccParser::ExprConstContext *ctx){
    int value = stoi(ctx->CONST()->getText());
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
