#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrPushq : public IRInstr, public IRInstrBaseSrc<IRInstrPushq> , public IRInstrBaseDest<IRInstrPushq>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}