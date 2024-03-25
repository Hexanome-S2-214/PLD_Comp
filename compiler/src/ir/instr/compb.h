#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrCompb : public IRInstr, public IRInstrBaseSrc<IRInstrCompb>, public IRInstrBaseDest<IRInstrCompb>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
