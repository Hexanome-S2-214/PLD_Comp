#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprMod : public IRInstr, public IRAttrDest<IRInstrExprMod>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;

        IRParam * div_res;
        IRParam * num;
        IRParam * dem;
    };
}
