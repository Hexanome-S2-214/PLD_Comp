#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

void IR::IRInstrMov::gen_asm(ostream& o)
{
    o << "\tmovl "<< src << ", " << dest << endl;
}

