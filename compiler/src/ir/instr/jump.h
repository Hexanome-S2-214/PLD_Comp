#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrJump : public IRInstr, public IRInstrBaseSymbol<IRInstrJump>, public IRInstrBaseDest<IRInstrJump>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
