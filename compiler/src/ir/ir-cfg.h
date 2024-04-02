#pragma once

namespace IR
{
    class BasicBlock;
}

#include <vector>
#include "ir-base.h"
#include "ir-symbol-table.h"
#include "../error-reporter/error-reporter.h"
#include "ir-instr-comp.h"

using namespace std;

namespace IR
{
    class CFG : public IRBase
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

        IRBase * set_error_reporter(ErrorReporter::ErrorReporter * error_reporter);
        void set_current_bb(BasicBlock * bb);
        void incr_nb_param();

        SymbolTable * get_symbol_table();
        BasicBlock * get_current_bb();
        vector<BasicBlock *> get_blocks();
        string get_next_bb_label();
        string get_epilogue_label();
        string get_fname();
        int get_nb_param();

        int calc_st_size();
        
        vector<string> stack; // TODO: Make private and add push/pop methods (also maybe rename to something that means something)
    private:
        vector<BasicBlock *> blocks;
        SymbolTable * symbol_table;

        BasicBlock * current_bb;
        static int bb_count;
        BasicBlock * epilogue_bb;
        string epilogue_label;

        string fname;
        int nb_param;
        
    };
};
