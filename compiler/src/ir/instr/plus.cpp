#include "plus.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprPlus::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id);
    
    o << "\taddl "<<symbol->get_asm_str() << ", " << IR::IRRegA().get_asm_str() << endl;

}

