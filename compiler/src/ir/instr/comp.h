#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"
#include "../../error-reporter/compiler-error-token.h"

namespace IR
{
    class IRInstrComp : public IRInstr, public IRAttrSrc<IRInstrComp>, public IRAttrDest<IRInstrComp>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
