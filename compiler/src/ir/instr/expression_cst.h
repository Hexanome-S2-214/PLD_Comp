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
        IRInstrExprCst(BasicBlock * bb, string value) : IRInstr(bb), value(value) {};

        void gen_asm(ostream& o) override;
    private:
        string value;
    };
}
