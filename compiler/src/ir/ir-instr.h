#pragma once

namespace IR
{
    class SymbolTable;
}

#include "ir-base.h"
#include "ir-basic-block.h"
#include "antlr4-runtime.h"

using namespace std;

namespace IR
{
    class IRInstr : public IRBase
    {
    public:
        IRInstr() {}
        ~IRInstr() = default;

        BasicBlock * get_bb();
    };
};
