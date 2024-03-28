#include "expression_var.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    vector<IRInstr *> IRInstrExprVar::get_instrs()
    {
        return {
            (new IRInstrMov)
                ->set_src(symbol)
                ->set_dest(
                    (new IRRegA)
                        ->set_size(symbol->type.size)
                )
        };
    }
}
