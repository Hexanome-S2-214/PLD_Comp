#pragma once

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrExprPlus : public IRInstr, public IRInstrBaseSrc<IRInstrExprPlus>, public IRInstrBaseDest<IRInstrExprPlus>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
