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
        )->gen_asm(o);
    }


    void IRInstrExprMod::gen_asm_arm(ostream &o)
    {
        paste_properties(
            (new IR::IRInstrMov)
                ->set_src(num)
                ->set_dest(new IR::IRRegArmTemp1)
        )->gen_asm(o);
        paste_properties(
            (new IR::IRInstrMov)
                ->set_src(dem)
                ->set_dest(new IR::IRRegArmTemp2)
        )->gen_asm(o);
        o << "\tmsub " << dest->get_asm_str() << ", " << div_res->get_asm_str() << ", " << (new IR::IRRegArmTemp2)->get_asm_str() << ", " << (new IR::IRRegArmTemp1)->get_asm_str() << endl;
    }
}