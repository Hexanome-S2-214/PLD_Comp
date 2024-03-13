#pragma once

namespace IR
{
    class BasicBlock;
    class SymbolTable;
}

#include "ir-base.h"

using namespace std;

namespace IR
{
    class IRInstr : public IRBase
    {
    public:
        IRInstr(BasicBlock * bb) : bb(bb) {}
        ~IRInstr() = default;

        BasicBlock * get_bb() { return bb; };
        SymbolTable * get_symbol_table();
    private:
        BasicBlock * bb;
    };
};
