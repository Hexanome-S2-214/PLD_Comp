#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrSetFlagComp : public IRInstr, public IRAttrOp<IRInstrSetFlagComp>, public IRAttrDest<IRInstrSetFlagComp>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
