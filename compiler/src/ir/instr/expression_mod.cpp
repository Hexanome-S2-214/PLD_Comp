#include "expression_mod.h"
#include "mov.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprMod::gen_asm_x86(ostream &o)
    {
        paste_properties(
            (new IR::IRInstrMov)
                ->set_src(new IR::IRRegD)
                ->set_dest(dest)
        );
    }


    void IRInstrExprMod::gen_asm_arm(ostream &o)
    {
        o << "\tmsub " << dest->get_asm_str() << ", " << div_res->get_asm_str() << ", " << dem->get_asm_str() << ", " << num->get_asm_str() << endl;
    }
}