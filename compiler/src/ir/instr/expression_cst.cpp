#include "expression_cst.h"
#include "mov.h"
#include "../params/ir-reg.h"

namespace IR
{
    vector<IRInstr *> IRInstrExprCst::get_instrs()
    {
        return {
            (new IRInstrMov)
                ->set_src(value)
                ->set_dest(
                    (new IRRegA)
                        ->set_size(value->get_size())
                )
        };
    }
}
