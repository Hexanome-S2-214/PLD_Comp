#pragma once

namespace IR
{
    class SymbolTable;
}

#include "ir-base.h"
#include "ir-basic-block.h"

using namespace std;

namespace IR
{
    class IRInstr : public IRBase
    {
    public:
        IRInstr(BasicBlock * bb) : IRBase(bb), bb(bb) {}
        ~IRInstr() = default;

        BasicBlock * get_bb() { return bb; };
        SymbolTable * get_symbol_table();
    private:
        BasicBlock * bb;
    };
};
