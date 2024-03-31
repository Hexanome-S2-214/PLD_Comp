#pragma once

namespace IR
{
    class CFG;
    class IRInstr;
    class IRInstrComposition;
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

        void add_instr(IRBase * instr);
        vector<IRInstr *> * get_instrs();

        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;

        void set_exit_true(BasicBlock * exit_true);
        void set_exit_false(BasicBlock * exit_false);
        void set_exit(string exit);
        void set_write_mode(bool wm);

        string get_label();
        CFG * get_cfg();
    private:
        BasicBlock * exit_true;
        BasicBlock * exit_false;
        string exit_label;
        vector<IRInstr *> instrs;
        string label;
        string test_var;
        bool write_mode = true;
    };
};
