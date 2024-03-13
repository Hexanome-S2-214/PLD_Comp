#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprSum : public IRInstr
    {
    public:
        IRInstrExprSum(BasicBlock * bb, string id) : IRInstr(bb), id(id) {};

        void gen_asm(ostream& o) override;
    private:
        string id;
    };
}
