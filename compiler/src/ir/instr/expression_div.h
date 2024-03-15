#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprDiv : public IRInstr, public IRInstrBaseSrc<IRInstrExprDiv>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
