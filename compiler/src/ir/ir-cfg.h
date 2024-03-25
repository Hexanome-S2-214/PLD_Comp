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
        CFG();
        ~CFG();

        void gen_asm(ostream& o) override;
        void gen_asm_prologue(ostream& o);
        void gen_asm_epilogue(ostream& o);

        void add_instr(IRBase * instr);

        IRBase * set_error_reporter(ErrorReporter::ErrorReporter * error_reporter);

        SymbolTable * get_symbol_table();

        BasicBlock * get_current_bb();
        vector<BasicBlock *> get_blocks();
        void set_current_bb(BasicBlock * bb);
        string get_next_bb_label();
        void add_bb(BasicBlock * bb);
        vector<string> stack; // TODO: Make private and add push/pop methods (also maybe rename to something that means something)
    private:
        vector<BasicBlock *> blocks;
        BasicBlock * current_bb;
        SymbolTable * symbol_table;

        static int bb_count;
    };
};
