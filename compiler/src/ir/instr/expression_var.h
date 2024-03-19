#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprVar : public IRInstr, public IRInstrBaseSymbol<IRInstrExprVar>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
