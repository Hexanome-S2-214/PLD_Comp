#include "assign.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-param.h"

namespace IR
{
    vector<IRInstr *> IRInstrAssign::get_instrs()
    {
        return {
            (new IRInstrMov)
                ->set_src(
                    ((IR::IRReg*)src)->set_size(symbol->type.size)
                )
                ->set_dest(symbol)
        };
    }
}
