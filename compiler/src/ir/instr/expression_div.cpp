#include "expression_div.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprDiv::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov)
                ->set_src(new IRRegA)
                ->set_dest(new IRRegB)
        )->gen_asm(o);
        paste_properties(
            (new IRInstrMov)
                ->set_src(src)
                ->set_dest(new IRRegA)
        )->gen_asm(o);

        o << "\tcltd" << endl;
        o << "\tidivl " << (new IRRegB)->get_asm_str() << endl;
    }
}
