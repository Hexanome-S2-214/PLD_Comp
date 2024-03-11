#pragma once

namespace IR
{
    class CFG;
    class IRInstr;
}

#include <vector>
#include "ir-base.h"

using namespace std;

namespace IR
{
    class BasicBlock : public IRBase
    {
    public:
        BasicBlock(CFG * cfg);
        ~BasicBlock();

        void add_instr(IRInstr * instr);

        void gen_asm(ostream& o) override;
    private:
        BasicBlock * exit_true;
        BasicBlock * exit_false;
        CFG * cfg;
        vector<IRInstr *> instrs;
    };
};
