#include "declaration_aff.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrDeclaAff::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id);

    o << "\tmovl " << IR::IRRegA().get_asm_str() << ", " << symbol->get_asm_str() << endl;
}