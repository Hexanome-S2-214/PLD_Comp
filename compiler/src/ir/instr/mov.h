#pragma once

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrMov : public IRInstr, public IRAttrSrc<IRInstrMov>, public IRAttrDest<IRInstrMov>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    private:
        string get_op();
    };
}
