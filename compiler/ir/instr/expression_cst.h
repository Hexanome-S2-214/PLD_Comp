#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprCst : public IRInstr
    {
    public:
        IRInstrExprCst(BasicBlock * bb, int value) : IRInstr(bb), id(id) {};

        void gen_asm(ostream& o) override;
    private:
        string id;
    };
}
