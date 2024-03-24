#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprPlus : public IRInstr, public IRAttrSrc<IRInstrExprPlus>, public IRAttrDest<IRInstrExprPlus>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
