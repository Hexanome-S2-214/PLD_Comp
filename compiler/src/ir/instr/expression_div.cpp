#include "expression_div.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprDiv::gen_asm(ostream& o)
{
    IR::IRInstrMov(get_bb(), IR::IRRegA().get_asm_str(), IR::IRRegB().get_asm_str()).gen_asm(o);
    IR::IRInstrMov(get_bb(), src, IR::IRRegA().get_asm_str()).gen_asm(o);
    o << "\tcltd" << endl;
    o << "\tidivl " << IR::IRRegB().get_asm_str() << endl;
}