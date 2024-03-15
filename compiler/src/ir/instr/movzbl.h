#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrMovzbl : public IRInstr, public IRInstrBaseSrc<IRInstrMovzbl>, public IRInstrBaseDest<IRInstrMovzbl>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
