#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrComp : public IRInstr, public IRAttrSrc<IRInstrComp>, public IRAttrDest<IRInstrComp>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
