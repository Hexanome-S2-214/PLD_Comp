#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprUnaryMinus : public IRInstr
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
