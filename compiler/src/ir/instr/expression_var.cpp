#include "expression_var.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprVar::gen_asm(ostream& o)
{
    Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id, get_ctx());

    IR::IRInstrMov(get_bb(), get_ctx(), symbol->get_asm_str(), IR::IRRegA(this).get_asm_str()).gen_asm(o);
}