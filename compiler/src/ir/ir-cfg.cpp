#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"

int IR::CFG::bb_count = 2;

IR::CFG::CFG()
{
    symbol_table = new SymbolTable();

    BasicBlock * new_bb = new BasicBlock(this, get_next_bb_label(), nullptr, nullptr);
    add_bb(new_bb);
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
    o << ".globl main\n" ;
    o << " main: \n" ;
    o << "    #prologue\n" ;
    o << "    pushq %rbp\n" ;
    o << "    movq %rsp, %rbp\n\n" ;
}

void IR::CFG::gen_asm_epilogue(ostream& o)
{
    o << "\n";
    o << "    # epilogue\n";
    o << "    popq %rbp\n";
    o << "    ret\n";
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