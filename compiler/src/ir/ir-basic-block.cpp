#include "ir-basic-block.h"
#include "ir-cfg.h"
#include "ir-instr.h"
#include "ir-instr-comp.h"

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label) : BasicBlock(cfg, label, nullptr, nullptr) {
}

IR::BasicBlock::BasicBlock(IR::CFG * cfg, string label, IR::BasicBlock * exit_true, IR::BasicBlock * exit_false) : label(label), exit_true(exit_true), exit_false(exit_false) {
    set_parent(cfg);
    ref = "BB<" + label + ">";
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

    if (!write_mode) {
        return;
    }

    //write_mode : to handle returns anywhere
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
    exit_true->set_parent_scope(this);
    this->exit_true = exit_true;
}

void IR::BasicBlock::set_exit_false(IR::BasicBlock * exit_false)
{
    exit_false->set_parent_scope(this);
    this->exit_false = exit_false;
}

void IR::BasicBlock::set_exit(string exit_label)
{
    this->exit_label = exit_label;
}

void IR::BasicBlock::set_write_mode(bool wm) {
    this->write_mode = wm;
}

void IR::BasicBlock::set_bb_id(int bb_id) {
    this->bb_id = bb_id;
}

int IR::BasicBlock::get_bb_id() {
    return bb_id;
}

string IR::BasicBlock::get_exit_label() {
    return this->exit_label;
}

string IR::BasicBlock::get_label()
{
    return label;
}

IR::CFG * IR::BasicBlock::get_cfg()
{
    return this->get_parent<IR::CFG>();
}
