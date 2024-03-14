#include "expression_div.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprDiv::gen_asm(ostream& o)
{
    IR::IRInstrMov(get_bb(), IR::IRRegA(this).get_asm_str(), IR::IRRegB(this).get_asm_str()).gen_asm(o);
    IR::IRInstrMov(get_bb(), src, IR::IRRegA(this).get_asm_str()).gen_asm(o);
    o << "\tcltd" << endl;
    o << "\tidivl " << IR::IRRegB(this).get_asm_str() << endl;
}