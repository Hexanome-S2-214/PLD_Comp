#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprMult : public IRInstr, public IRInstrBaseSrc<IRInstrExprMult>, public IRInstrBaseDest<IRInstrExprMult>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
