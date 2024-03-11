#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"

void IR::CFG::gen_asm(ostream& o)
{
    gen_asm_prologue(o);

    for (auto block : blocks)
    {
        block->gen_asm(o);
    }

    gen_asm_epilogue(o);
}

void IR::CFG::gen_asm_prologue(ostream& o)
{
    
}

void IR::CFG::gen_asm_epilogue(ostream& o)
{
    
}
