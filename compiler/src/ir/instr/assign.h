#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrAssign : public IRInstr, public IRInstrBaseSymbol<IRInstrAssign>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
