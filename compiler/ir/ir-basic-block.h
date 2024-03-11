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
        BasicBlock(CFG * cfg, string label);
        BasicBlock(CFG * cfg, string label, BasicBlock * exit_true, BasicBlock * exit_false);
        ~BasicBlock();

        void add_instr(IRInstr * instr);

        void gen_asm(ostream& o) override;

        void set_exit_true(BasicBlock * exit_true);
        void set_exit_false(BasicBlock * exit_false);

        string get_label();
        CFG * get_cfg() { return cfg; }
    private:
        BasicBlock * exit_true;
        BasicBlock * exit_false;
        CFG * cfg;
        vector<IRInstr *> instrs;
        string label;
        string test_var;
    };
};
