#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"

IR::CFG::CFG(IRArch arch) : IRBase(arch)
{
    symbol_table = new SymbolTable();

    blocks.push_back(new BasicBlock(this, "entry"));
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

IR::SymbolTable * IR::CFG::get_symbol_table()
{
    return symbol_table;
}

IR::BasicBlock * IR::CFG::get_current_bb()
{
    return blocks.back();
}