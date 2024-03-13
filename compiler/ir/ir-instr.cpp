#include "ir-instr.h"
#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-symbol-table.h"

namespace IR
{
    SymbolTable * IRInstr::get_symbol_table()
    {
        return this->get_bb()->get_cfg()->get_symbol_table();
    }
}
