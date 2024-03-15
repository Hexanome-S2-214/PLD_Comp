#include "expression_cst.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

namespace IR
{
    void IRInstrExprCst::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov())
                ->set_src("$" + this->value)
                ->set_dest(IR::IRRegA(this).get_asm_str())
        )->gen_asm(o);
    }
}
