#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrAddq : public IRInstr, public IRAttrSrc<IRInstrAddq>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}