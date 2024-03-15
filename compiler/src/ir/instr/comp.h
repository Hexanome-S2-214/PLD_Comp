#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrComp : public IRInstr, public IRInstrBaseSrc<IRInstrComp>, public IRInstrBaseDest<IRInstrComp>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
