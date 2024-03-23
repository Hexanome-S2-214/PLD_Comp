#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrMovb : public IRInstr, public IRInstrBaseSrc<IRInstrMovb>, public IRInstrBaseDest<IRInstrMovb>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
