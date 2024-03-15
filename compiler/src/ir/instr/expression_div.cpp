#include "expression_div.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

namespace IR
{
    void IRInstrExprDiv::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov)
                ->set_src(IR::IRRegA(this).get_asm_str())
                ->set_dest(IR::IRRegB(this).get_asm_str())
        )->gen_asm(o);
        paste_properties(
            (new IRInstrMov)
                ->set_src(src)
                ->set_dest(IR::IRRegA(this).get_asm_str())
        )->gen_asm(o);

        o << "\tcltd" << endl;
        o << "\tidivl " << IR::IRRegB(this).get_asm_str() << endl;
    }
}
