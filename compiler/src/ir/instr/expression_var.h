#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprVar : public IRInstr
    {
    public:
        IRInstrExprVar(BasicBlock * bb, string id) : IRInstr(bb), id(id) {};

        void gen_asm(ostream& o) override;
    private:
        string id;
    };
}
