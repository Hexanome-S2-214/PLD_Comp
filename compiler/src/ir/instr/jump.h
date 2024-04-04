#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"
#include "../../error-reporter/compiler-error-token.h"

namespace IR
{
    class IRInstrJump : public IRInstr, public IRAttrJump<IRInstrJump>, public IRAttrLabel<IRInstrJump>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    };
}
