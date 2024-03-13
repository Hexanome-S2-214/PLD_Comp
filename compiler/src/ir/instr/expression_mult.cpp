#include "expression_mult.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprMult::gen_asm(ostream& o)
{
    o << "\timull " << src << ", " << dest << endl;
}