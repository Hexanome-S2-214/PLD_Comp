#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"

IR::CFG::CFG()
{
    symbol_table = new SymbolTable();

    blocks.push_back(new BasicBlock(this, "entry"));
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
    o << "    movq %rsp, %rbp\n" ;
}

void IR::CFG::gen_asm_epilogue(ostream& o)
{
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

IR::BasicBlock * IR::CFG::get_current_bb()
{
    return blocks.back();
}