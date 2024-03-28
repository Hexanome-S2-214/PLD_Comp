#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprBitABit : public IRInstr, public IRAttrOp<IRInstrExprBitABit>, public IRAttrSrc<IRInstrExprBitABit> , public IRAttrDest<IRInstrExprBitABit>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
