#include "assign.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-param.h"
#include "../params/ir-reg.h"

namespace IR
{
    vector<IRInstr *> IRInstrAssign::get_instrs()
    {
        return {
            (new IRInstrMov)
                ->set_src(
                    (new IRRegA)
                        ->set_size(symbol->type.size)
                )
                ->set_dest(symbol)
        };
    }
}
