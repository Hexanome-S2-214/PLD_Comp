#pragma once

namespace IR
{
    class CFG;
    class IRInstr;
    class IRInstrComposition;
}

#include <list>
#include "ir-base.h"
#include "ir-scoped-block.h"

using namespace std;

namespace IR
{
    class BasicBlock : public IRBase, public IRScopedBlock
    {
    public:
        BasicBlock(CFG * cfg, string label);
        BasicBlock(CFG * cfg, string label, BasicBlock * exit_true, BasicBlock * exit_false);
        ~BasicBlock();

        void add_instr(IRBase * instr);
        list<IRInstr *> * get_instrs();

        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;

        void remove_last_instructions(int n);

        void set_exit_true(BasicBlock * exit_true);
        void set_exit_false(BasicBlock * exit_false);
        void set_exit(string exit);
        void set_write_mode(bool wm);
        void set_bb_id(int bb_id);

        string get_label();
        string get_exit_label();
        int get_bb_id();
        CFG * get_cfg();
    private:
        list<IRInstr *> instrs;
        string label;
        
        BasicBlock * exit_true;
        BasicBlock * exit_false;
        string exit_label;
        
        string test_var; //TODO : ça sert à quoi ça ?
        int bb_id = 0;

        bool write_mode = true;
    };
};
