#include "minus.h"
#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-reg.h"

void IR::IRInstrMinus::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id);

    o << "    movl - "<<IR::IRRegA().get_asm_str() <<", "<< IR::IRRegD().get_asm_str() << "\n    movl -"<< symbol->get_asm_str() <<", "<<IR::IRRegA().get_asm_str()<< "\n    subl "<<IR::IRRegD().get_asm_str()<<", "<<IR::IRRegA().get_asm_str() <<endl;

}

