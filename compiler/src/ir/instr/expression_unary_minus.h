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
        void gen_asm(ostream& o) override;
    };
}
