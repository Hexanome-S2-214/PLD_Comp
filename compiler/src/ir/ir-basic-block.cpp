#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-instr.h"
#include "ir-instr-comp.h"

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label) : BasicBlock(cfg, label, nullptr, nullptr) {}

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label, IR::BasicBlock * exit_true, IR::BasicBlock * exit_false) : label(label), exit_true(exit_true), exit_false(exit_false) {
    set_parent(cfg);
}

IR::BasicBlock::~BasicBlock()
{
    for (IR::IRInstr * instr : instrs)
    {
        delete instr;
    }
}

void IR::BasicBlock::add_instr(IR::IRBase * instr)
{
    IRInstrComposition * instr_comp_cast = dynamic_cast<IRInstrComposition *>(instr);

    if (instr_comp_cast != nullptr)
    {
        for (IR::IRInstr * instr : instr_comp_cast->get_instrs())
        {
            add_instr(instr);
        }
        
        return;
    }

    IRInstr * instr_cast = dynamic_cast<IRInstr *>(instr);

    if (instr_cast != nullptr)
    {
        instr->set_parent(this);
        instrs.push_back(static_cast<IR::IRInstr*>(instr));

        return;
    }

    cerr << "ERROR: Invalid instruction type" << endl;
}

vector<IR::IRInstr *> * IR::BasicBlock::get_instrs()
{
    return &instrs;
}

void IR::BasicBlock::gen_asm_x86(ostream& o)
{
    if (get_label() != "") {
        o << get_label() << ":" << endl;
    }

    for (IR::IRInstr * instr : instrs)
    {
        instr->gen_asm_x86(o);
    }

    if (exit_label != "")
    {
        o << "\tjmp " << exit_label << "" << endl;
    }
}

void IR::BasicBlock::gen_asm_arm(ostream &o){

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
