#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrJump : public IRInstr, public IRAttrOp<IRInstrJump>, public IRAttrLabel<IRInstrJump>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
