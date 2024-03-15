#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprMinus : public IRInstr, public IRInstrBaseSrc<IRInstrExprMinus>, public IRInstrBaseDest<IRInstrExprMinus>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
