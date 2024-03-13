#include "expression_cst.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprCst::gen_asm(ostream& o)
{
    o << "\tmovl $ " <<  this->value << ", " << IR::IRRegA().get_asm_str() << endl;
}