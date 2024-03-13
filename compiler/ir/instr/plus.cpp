#include "plus.h"
#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-reg.h"

void IR::IRInstrPlus::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id);
    
    o << "    addl -"<<symbol->get_asm_str()<<" , "<<IR::IRRegA().get_asm_str() << endl;

}

