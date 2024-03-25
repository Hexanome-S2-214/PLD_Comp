#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprMult : public IRInstr, public IRAttrSrc<IRInstrExprMult>, public IRAttrDest<IRInstrExprMult>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
