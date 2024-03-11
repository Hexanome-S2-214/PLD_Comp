#pragma once

#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-instr.h"

void IR::BasicBlock::add_instr(IR::IRInstr * instr)
{
    instrs.push_back(instr);
}

void IR::BasicBlock::gen_asm(ostream& o)
{
    for (auto instr : instrs)
    {
        instr->gen_asm(o);
    }
}
