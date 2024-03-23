#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrMovsbl : public IRInstr, public IRInstrBaseSrc<IRInstrMovsbl>, public IRInstrBaseDest<IRInstrMovsbl>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
