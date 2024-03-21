#include "assign.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-param.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrAssign::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov)
                ->set_src(new IRRegA)
                ->set_dest(symbol)
        )->gen_asm(o);
    }
}
