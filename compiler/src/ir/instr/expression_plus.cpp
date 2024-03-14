#include "expression_plus.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprPlus::gen_asm(ostream& o)
{
    o << "\taddl "<< src << ", " << dest << endl;
}

