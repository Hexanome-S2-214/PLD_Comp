#include "declaration_aff.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    vector<IRInstr *> IRInstrDeclaAff::get_instrs()
    {
        return {
            (new IRInstrMov)
                ->set_src(new IRRegA)
                ->set_dest(symbol)
        };
    }
}
