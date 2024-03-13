#include "expression_cst.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprCst::gen_asm(ostream& o)
{
    IR::IRInstrMov(get_bb(), "$" + this->value, IR::IRRegA().get_asm_str()).gen_asm(o);
}