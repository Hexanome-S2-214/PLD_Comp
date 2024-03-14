#include "declaration_aff.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrDeclaAff::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id);

    IR::IRInstrMov(get_bb(), IR::IRRegA(this).get_asm_str(), symbol->get_asm_str()).gen_asm(o);
}