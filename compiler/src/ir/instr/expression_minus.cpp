#include "expression_minus.h"
#include "../params/ir-reg.h"
#include "mov.h"

namespace IR
{
    void IRInstrExprMinus::gen_asm_x86(ostream& o)
    {
        o << "\tsubl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }

    void IRInstrExprMinus::gen_asm_arm(ostream& o)
    {
        paste_properties(
                (new IRInstrMov)
                    ->set_src((new IRRegArmTemp1)->set_size(deest->get_size()))
                    ->set_dest(src)
            )->gen_asm(o); 

        paste_properties(
                (new IRInstrMov)
                    ->set_src((new IRRegArmTemp2)->set_size(deest->get_size()))
                    ->set_dest(dest)
            )->gen_asm(o); 

        o << "\tsub " << (new IRRegA)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << ", " << (new IRRegArmTemp1)->get_asm_str() << "\n";
    }
}
