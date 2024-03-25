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
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
