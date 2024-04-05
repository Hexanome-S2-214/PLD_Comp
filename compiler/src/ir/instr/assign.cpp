#include "assign.h"
#include "mov.h"

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
