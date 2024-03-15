#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrSete : public IRInstr, public IRInstrBaseDest<IRInstrSete>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
