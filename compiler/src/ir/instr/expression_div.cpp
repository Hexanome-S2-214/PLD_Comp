#include "expression_div.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprDiv::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->tmpVar);

    IR::IRInstrMov(get_bb(), IR::IRRegA().get_asm_str(), IR::IRRegC().get_asm_str()).gen_asm(o);
    IR::IRInstrMov(get_bb(), symbol->get_asm_str(), IR::IRRegA().get_asm_str()).gen_asm(o);
    o << "\tcltd" << endl;
    o << "\tidivl " << IR::IRRegC().get_asm_str() << endl;
}