#pragma once

#include "IR.h"

CFG::CFG(DefFonction* ast){
    this->ast = ast;
    this->current_bb = nullptr;
    this->nextFreeSymbolIndex = 0;
    this->nextBBnumber = 0;
    this->symbolTable = new SymbolTable();
    this->add_bb(new BasicBlock(this, "entry"));
}

