#pragma once

namespace IR
{
    class BasicBlock;
}

#include <vector>
#include <stack>
#include "ir-base.h"
#include "ir-symbol-table.h"
#include "../error-reporter/error-reporter.h"
#include "ir-instr-comp.h"
#include "ir-scoped-block.h"

#define BB_INSTR 0

#define BB_IF 10
#define BB_WHILE 20
#define BB_SWITCH 30

#define BB_END_IF 1
#define BB_END_WHILE 2
#define BB_END_SWITCH 3

using namespace std;

namespace IR
{
    class CFG : public IRBase, public IRScopedBlock
    {
    public:
        CFG(string name);
        ~CFG();

        void gen_asm_x86(ostream& o) override;
        void gen_asm_x86_prologue(ostream& o);
        void gen_asm_x86_epilogue(ostream& o);

        void gen_asm_arm(ostream& o) override;
        void gen_asm_arm_prologue(ostream& o);
        void gen_asm_arm_epilogue(ostream& o);

        void add_instr(IRBase * instr);
        void add_bb(BasicBlock * bb);
        void remove_bb(BasicBlock * bb);

        void set_current_bb(BasicBlock * bb);
        void set_nb_param(int n);
        void set_no_return(bool b);

        BasicBlock * get_current_bb();
        vector<BasicBlock *> get_blocks();
        string get_next_bb_label(string name_label = "");
        string get_epilogue_label();
        string get_fname();
        int get_nb_param();
        bool get_no_return();

        int calc_st_size();

        void push_break(string label);
        string pop_break();
        string get_break();
        void push_continue(string label);
        string pop_continue();
        string get_continue();
    private:
        vector<BasicBlock *> blocks;

        BasicBlock * current_bb = nullptr;
        static int bb_count;
        BasicBlock * epilogue_bb;
        string epilogue_label;

        stack<string> break_stack;
        stack<string> continue_stack;

        string fname;
        int nb_param;
        bool no_return;
        
    };
};
