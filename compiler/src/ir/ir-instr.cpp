#include "ir-instr.h"
#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-symbol-table.h"

namespace IR
{
    BasicBlock * IRInstr::get_bb()
    {
        return get_parent<BasicBlock>();
    }
}
