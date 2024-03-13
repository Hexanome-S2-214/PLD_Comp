#include "expression_div.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprDiv::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->tmpVar);

    o << "    movl " << IR::IRRegA().get_asm_str() << IR::IRRegC().get_asm_str() << endl;
    o << "    movl " <<  symbol->get_asm_str() << ", " << IR::IRRegA().get_asm_str() << endl ;
    o << "    cltd\n";
    o << "    idivl " << IR::IRRegC().get_asm_str() << endl;
}