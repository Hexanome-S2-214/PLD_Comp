#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrAddq : public IRInstr, public IRInstrBaseSrc<IRInstrAddq>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}