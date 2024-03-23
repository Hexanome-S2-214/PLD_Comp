#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrCharacter : public IRInstr, public IRInstrBaseValue<IRInstrCharacter>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}