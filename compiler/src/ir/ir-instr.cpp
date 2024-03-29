#include "ir-instr.h"
#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-symbol-table.h"

namespace IR
{
    SymbolTable * IRInstr::get_symbol_table()
    {
        return get_bb()->get_cfg()->get_symbol_table();
    }

    BasicBlock * IRInstr::get_bb()
    {
        return get_parent<BasicBlock>();
    }
}
