#include "minus.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprMinus::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id);

    o << "\tmovl "<<IR::IRRegA().get_asm_str() <<", "<< IR::IRRegB().get_asm_str() << endl
        << "\tmovl "<< symbol->get_asm_str() <<", "<<IR::IRRegA().get_asm_str() << endl 
        << "\tsubl "<<IR::IRRegB().get_asm_str()<<", "<<IR::IRRegA().get_asm_str() <<endl;

}

