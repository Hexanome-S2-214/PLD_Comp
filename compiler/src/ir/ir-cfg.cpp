#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"
#include "instr/epilogue.h"
#include "ir-errors.h"

int IR::CFG::bb_count = 2;

IR::CFG::CFG(string name)
{
    fname = name;
    nb_param = 0;

    //Create epilogue BB -> we store it apart from the other because we need to write it at the end
    epilogue_label = get_next_bb_label();
    this->epilogue_bb = new BasicBlock(this, epilogue_label, nullptr, nullptr);
    this->epilogue_bb->add_instr(new IR::IRInstrEpilogue);

    //Create BB to write beginning of the function in -> the order of the blocks doesn't matter since we store epilogue_label
    BasicBlock * bb = new BasicBlock(this, get_next_bb_label(), nullptr, nullptr);
    add_bb(bb);
}

IR::CFG::~CFG()
{
    for (BasicBlock * block : blocks)
    {
        delete block;
    }
}

void IR::CFG::gen_asm_x86(ostream& o)
{
    gen_asm_x86_prologue(o);

    for (auto block : blocks)
    {
        block->gen_asm_x86(o);
    }

    gen_asm_x86_epilogue(o);
}

void IR::CFG::gen_asm_arm(ostream& o)
{
    gen_asm_arm_prologue(o);

    for (auto block : blocks)
    {
        block->gen_asm_arm(o);
    }

    // gen_asm_arm_epilogue(o);
}

void IR::CFG::gen_asm_arm_prologue(ostream& o){
    o << ".globl main\n";
    o << "main:\n";
    o << "    push {fp, lr}\n";
    o << "    add fp, sp, #4\n";
}

// void IR::CFG::gen_asm_arm_epilogue(ostream& o){
//     o << "    pop {fp, pc}\n";
// }

void IR::CFG::gen_asm_x86_prologue(ostream& o)
{
    o << endl;
    o << ".globl " << fname << endl;
    o << fname << ":" << endl;
    o << "\tpushq %rbp\n" ;
    o << "\tmovq %rsp, %rbp\n" ;
    //TODO : handle this via an instr ?
    o << "\tsubq $" << get_st_size() << ", %rsp" << endl;
}

void IR::CFG::gen_asm_x86_epilogue(ostream& o)
{
    this->epilogue_bb->gen_asm_x86(o);
}

void IR::CFG::add_instr(IR::IRBase * instr)
{
    get_current_bb()->add_instr(instr);
}

void IR::CFG::set_current_bb(IR::BasicBlock * bb)
{
    current_bb = bb;
}

string IR::CFG::get_fname() {
    return fname;
}

int IR::CFG::get_nb_param() {
    return nb_param;
}

void IR::CFG::set_nb_param(int n) {
    this->nb_param = n;
}

void IR::CFG::set_no_return(bool b) {
    this->no_return = b;
}

IR::BasicBlock * IR::CFG::get_current_bb()
{
    return current_bb;
}

void IR::CFG::push_break(string label) {
    break_stack.push(label);
}

string IR::CFG::pop_break() {
    if (break_stack.empty()) {
        throw IRLoopError("break statement outside of a loop or switch");
    }

    string label = break_stack.top();
    break_stack.pop();

    return label;
}

string IR::CFG::get_break() {
    if (break_stack.empty()) {
        throw IRLoopError("break statement outside of a loop or switch");
    }

    return break_stack.top();
}

void IR::CFG::push_continue(string label) {
    continue_stack.push(label);
}

string IR::CFG::pop_continue() {
    if (continue_stack.empty()) {
        throw IRLoopError("continue statement outside of a loop");
    }

    string label = continue_stack.top();
    continue_stack.pop();
    return label;
}

string IR::CFG::get_continue() {
    if (continue_stack.empty()) {
        throw IRLoopError("continue statement outside of a loop");
    }

    return continue_stack.top();
}

vector<IR::BasicBlock *> IR::CFG::get_blocks()
{
    return blocks;
}

string IR::CFG::get_next_bb_label(string name_label)
{
    string label = ".L" + to_string(IR::CFG::bb_count);

    if (name_label.length() > 0)
    {
        label += "_" + name_label;
    }

    IR::CFG::bb_count++;
    return label;
}

string IR::CFG::get_epilogue_label() {
    return epilogue_label;
}

bool IR::CFG::get_no_return() {
    return no_return;
}

void IR::CFG::add_bb(IR::BasicBlock * bb)
{
    if (bb->get_parent_scope() == nullptr)
    {
        if (get_current_bb() != nullptr)
        {
            bb->set_parent_scope(get_current_bb());
        }
        else
        {
            bb->set_parent_scope(this);
        }
    }

    blocks.push_back(bb);
    set_current_bb(bb);
}

// IR::BasicBlock * IR::CFG::create_bb(IR::BasicBlock * exit_true, IR::BasicBlock * exit_false)
// {
//     string label = ".L" + to_string(IR::CFG::bb_count);
//     IR::CFG::bb_count++;

//     BasicBlock * new_bb = new BasicBlock(this, label, exit_true, exit_false);

//     blocks.push_back(new_bb);
//     current_bb = new_bb;
    
//     return new_bb;
// }