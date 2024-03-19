#include "expression_cst.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprCst::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov)
                ->set_src(value)
                ->set_dest(new IRRegA)
        )->gen_asm(o);
    }
}
