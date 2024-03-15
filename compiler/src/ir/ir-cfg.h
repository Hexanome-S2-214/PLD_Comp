#pragma once

namespace IR
{
    class BasicBlock;
}

#include <vector>
#include "ir-base.h"
#include "ir-symbol-table.h"
#include "../error-reporter/error-reporter.h"

using namespace std;

namespace IR
{
    class CFG : public IRBase
    {
    public:
        CFG();
        ~CFG() = default;

        void gen_asm(ostream& o) override;
        void gen_asm_prologue(ostream& o);
        void gen_asm_epilogue(ostream& o);

        void add_instr(IRBase * instr);

        IRBase * set_error_reporter(ErrorReporter::ErrorReporter * error_reporter);

        SymbolTable * get_symbol_table();
        BasicBlock * get_current_bb();
    private:
        vector<BasicBlock *> blocks;
        SymbolTable * symbol_table;
    };
};
