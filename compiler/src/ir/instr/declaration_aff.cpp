#include "declaration_aff.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrDeclaAff::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov)
                ->set_src(new IR::IRRegA)
                ->set_dest(symbol)
        )->gen_asm(o);
    }
}
