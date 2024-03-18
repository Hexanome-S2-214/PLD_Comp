#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrSetFlagComp : public IRInstr, public IRInstrBaseSymbol<IRInstrSetFlagComp>, public IRInstrBaseDest<IRInstrSetFlagComp>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
