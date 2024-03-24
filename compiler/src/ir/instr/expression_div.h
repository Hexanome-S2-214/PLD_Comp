#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprDiv : public IRInstr
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
