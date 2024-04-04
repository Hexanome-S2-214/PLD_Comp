#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprMult : public IRInstr, public IRAttrSrc<IRInstrExprMult>, public IRAttrDest<IRInstrExprMult>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
