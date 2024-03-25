#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrCall : public IRInstr, public IRAttrLiteral<IRInstrCall>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
