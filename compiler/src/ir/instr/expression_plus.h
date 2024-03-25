#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprPlus : public IRInstr, public IRAttrSrc<IRInstrExprPlus>, public IRAttrDest<IRInstrExprPlus>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
