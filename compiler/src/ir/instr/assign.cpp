#include "assign.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrAssign::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_symbol_table()->get_symbol(this->id, get_ctx());

    IR::IRInstrMov(get_bb(), this->get_ctx(), IR::IRRegA(this).get_asm_str(), symbol->get_asm_str()).gen_asm(o);
}
