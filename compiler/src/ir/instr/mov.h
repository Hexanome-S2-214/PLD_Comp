#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrMov : public IRInstr, public IRInstrBaseSrc<IRInstrMov>, public IRInstrBaseDest<IRInstrMov>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
