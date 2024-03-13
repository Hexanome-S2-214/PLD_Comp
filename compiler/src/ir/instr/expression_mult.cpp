#include "expression_mult.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprMult::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->tmpVar);

    o << "    imull "<< tmpVar << IR::IRRegA().get_asm_str() << endl;
}