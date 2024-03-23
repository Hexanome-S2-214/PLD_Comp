#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrCheat : public IRInstr
    {
    public:
        IRInstrCheat * set_instr(string instr);
        void gen_asm(ostream& o) override;
    private:
        string instr;
    };
}
