#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrCheat : public IRInstr
    {
    public:
        IRInstrCheat * set_instr(string instr);
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
    private:
        string instr;
    };
}
