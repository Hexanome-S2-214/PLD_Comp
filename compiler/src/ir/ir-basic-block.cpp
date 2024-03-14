#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-instr.h"
#include "ir-reg.h"

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label) : BasicBlock(cfg, label, nullptr, nullptr) {}

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label, IR::BasicBlock * exit_true, IR::BasicBlock * exit_false) : IRBase(cfg), cfg(cfg), label(label), exit_true(exit_true), exit_false(exit_false)
{
    // this->test_var = this->cfg->get_symbol_table()->get_next_tmp();
    // this->cfg->get_symbol_table()->declare_symbol(this->test_var, Bool);
}

void IR::BasicBlock::add_instr(IR::IRInstr * instr)
{
    instrs.push_back(instr);
}

void IR::BasicBlock::gen_asm(ostream& o)
{
    for (IR::IRInstr * instr : instrs)
    {
        instr->gen_asm(o);
    }

    if(exit_false != nullptr)
    {
        if (exit_true != nullptr)
        {
            o << "\tcmpq $1, " << IR::IRRegA(this).get_asm_str() << endl;
            o << "\tje " << exit_true->get_label() << endl;
            o << "\tjmp " << exit_false->get_label() << endl;
        }
        else
        {
            o << "\tjmp " << exit_false->get_label() << endl;
        }
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

string IR::BasicBlock::get_label()
{
    return label;
}
