#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrMov : public IRInstr, public IRAttrSrc<IRInstrMov>, public IRAttrDest<IRInstrMov>
    {
    public:
        void gen_asm(ostream& o) override;
    private:
        string get_op();
    };
}
