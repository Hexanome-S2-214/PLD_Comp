#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrSetFlagComp : public IRInstr, public IRAttrOp<IRInstrSetFlagComp>, public IRAttrDest<IRInstrSetFlagComp>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
