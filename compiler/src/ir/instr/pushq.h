#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrPushq : public IRInstr, public IRAttrSrc<IRInstrPushq> , public IRAttrDest<IRInstrPushq>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}