#include "expression_minus.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrExprMinus::gen_asm(ostream& o)
{
    o << "\tsubl " << src << ", " << dest << endl;
}
