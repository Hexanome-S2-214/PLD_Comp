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

void IR::BasicBlock::set_exit_true(IR::BasicBlock * exit_true)
{
    this->exit_true = exit_true;
}

void IR::BasicBlock::set_exit_false(IR::BasicBlock * exit_false)
{
    this->exit_false = exit_false;
}
