#include "ir-symbol-table.h"
#include "ir-reg.h"
#include "ir-base.h"

IR::Symbol::Symbol(IRBase * parent, string id, int offset, Type type, antlr4::ParserRuleContext * ctx) : IRBase(parent), id(id), offset(offset), type(type), ctx(ctx) {}

void IR::Symbol::gen_asm(ostream& o)
{
    o << offset << IR::IRRegStack(this).get_asm_str();
}

IR::Symbol * IR::SymbolTable::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx)
{
    if (symbols.find(id) != symbols.end())
    {
        cerr << "Error: symbol " << id << " already declared" << endl;
        exit(1);
    }

    IR::Symbol * symbol = new IR::Symbol(parent, id, symbol_offset, type, ctx);
    symbols[id] = *symbol;

    symbol_offset -= SYMBOL_SIZE;

    return symbol;
}

IR::Symbol * IR::SymbolTable::declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx)
{
    string tmp = get_next_tmp();
    return declare_symbol(parent, tmp, type, ctx);
}

IR::Symbol * IR::SymbolTable::get_symbol(string id, antlr4::ParserRuleContext * ctx)
{
    if (symbols.find(id) == symbols.end())
    {
        cerr << "Error: symbol " << id << " not declared" << endl;
        exit(1);
    }

    symbols[id].used = true;

    return &symbols[id];
}

string IR::SymbolTable::get_next_tmp()
{
    string tmp = "!tmp" + to_string(tmp_offset);
    tmp_offset++;

    return tmp;
}

