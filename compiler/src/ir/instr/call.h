#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrCall : public IRInstr, public IRInstrBaseCall<IRInstrCall>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
