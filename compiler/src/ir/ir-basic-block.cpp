#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-instr.h"

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label) : BasicBlock(cfg, label, nullptr, nullptr) {}

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label, IR::BasicBlock * exit_true, IR::BasicBlock * exit_false) : label(label), exit_true(exit_true), exit_false(exit_false) {
    set_parent(cfg);
}

void IR::BasicBlock::add_instr(IR::IRBase * instr)
{
    instr->set_parent(this);
    instrs.push_back(static_cast<IR::IRInstr*>(instr));
}

void IR::BasicBlock::gen_asm(ostream& o)
{
    if (get_label() != "") {
        o << get_label() << ":" << endl;
    }

    for (IR::IRInstr * instr : instrs)
    {
        instr->gen_asm(o);
    }

    if (exit_label != "")
    {
        o << "\tjmp " << exit_label << "" << endl;
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

void IR::BasicBlock::set_exit(string exit_label)
{
    this->exit_label = exit_label;
}

string IR::BasicBlock::get_label()
{
    return label;
}

IR::CFG * IR::BasicBlock::get_cfg()
{
    return this->get_parent<IR::CFG>();
}
