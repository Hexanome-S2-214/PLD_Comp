#pragma once

namespace IR
{
    class BasicBlock;
}

#include <vector>
#include "ir-base.h"
#include "ir-symbol-table.h"

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
    private:
        vector<BasicBlock *> blocks;
        SymbolTable symbol_table;
    };
};
