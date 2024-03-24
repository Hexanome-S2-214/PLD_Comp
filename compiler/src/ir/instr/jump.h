#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrJump : public IRInstr, public IRInstrBaseOp<IRInstrJump>, public IRInstrBaseLabel<IRInstrJump>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
