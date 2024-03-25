#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"

int IR::CFG::bb_count = 2;

IR::CFG::CFG(string name)
{
    fname = name;

    symbol_table = new SymbolTable();

    BasicBlock * new_bb = new BasicBlock(this, get_next_bb_label(), nullptr, nullptr);
    add_bb(new_bb);
}

IR::CFG::~CFG()
{
    delete symbol_table;

    for (BasicBlock * block : blocks)
    {
        delete block;
    }
}

IR::IRBase * IR::CFG::set_error_reporter(ErrorReporter::ErrorReporter * error_reporter)
{
    IRBase::set_error_reporter(error_reporter);
    symbol_table->error_reporter = error_reporter;

    return this;
}

void IR::CFG::gen_asm(ostream& o)
{
    gen_asm_prologue(o);

    for (auto block : blocks)
    {
        block->gen_asm(o);
    }

    gen_asm_epilogue(o);
}

void IR::CFG::gen_asm_prologue(ostream& o)
{
    o << endl;
    o << ".globl " << fname << endl;
    o << fname << ":" << endl;
    o << "\tpushq %rbp\n" ;
    o << "\tmovq %rsp, %rbp\n" ;
    //TODO : handle this via an instr ?
    o << "\tsubq $" << calc_st_size() << ", %rsp" << endl;
}

void IR::CFG::gen_asm_epilogue(ostream& o)
{
    o << "\n";
    o << "\tleave\n";
    o << "\tret\n";
}

int IR::CFG::calc_st_size() {
    int offset = symbol_table->get_symbol_offset();

    if (offset == 0) {
        return 0;
    } else {
        return ((-offset / 16)+1)*16;
    }
}

void IR::CFG::add_instr(IR::IRBase * instr)
{
    get_current_bb()->add_instr(instr);
}

IR::SymbolTable * IR::CFG::get_symbol_table()
{
    return symbol_table;
}

void IR::CFG::set_current_bb(IR::BasicBlock * bb)
{
    current_bb = bb;
}

IR::BasicBlock * IR::CFG::get_current_bb()
{
    return current_bb;
}

string IR::CFG::get_next_bb_label()
{
    string label = ".L" + to_string(IR::CFG::bb_count);
    IR::CFG::bb_count++;
    return label;
}

void IR::CFG::add_bb(IR::BasicBlock * bb)
{
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