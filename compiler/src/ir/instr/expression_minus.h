#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprMinus : public IRInstr, public IRAttrSrc<IRInstrExprMinus>, public IRAttrDest<IRInstrExprMinus>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
