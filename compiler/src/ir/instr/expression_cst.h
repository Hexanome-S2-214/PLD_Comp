#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprCst : public IRInstr, public IRInstrBaseValue<IRInstrExprCst>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
