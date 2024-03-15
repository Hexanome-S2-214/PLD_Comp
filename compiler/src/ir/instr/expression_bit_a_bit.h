#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprBitABit : public IRInstr, public IRInstrBaseSymbol<IRInstrExprBitABit>, public IRInstrBaseSrc<IRInstrExprBitABit> , public IRInstrBaseDest<IRInstrExprBitABit>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
