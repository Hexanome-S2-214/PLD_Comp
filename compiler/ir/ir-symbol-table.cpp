#include "ir-symbol-table.h"

IR::Symbol::Symbol(string id, int offset, Type type, antlr4::ParserRuleContext * ctx) : id(id), offset(offset), type(type), ctx(ctx) {}

void IR::Symbol::gen_asm(ostream& o)
{
    o << offset << "(%rbp)" << endl;
}

IR::Symbol * IR::SymbolTable::declare_symbol(string id, Type type, antlr4::ParserRuleContext * ctx)
{
    if (symbols.find(id) != symbols.end())
    {
        cerr << "Error: symbol " << id << " already declared" << endl;
        exit(1);
    }

    IR::Symbol * symbol = new IR::Symbol(id, symbol_offset, type, ctx);
    symbols[id] = *symbol;

    symbol_offset -= SYMBOL_SIZE;

    return symbol;
}

IR::Symbol * IR::SymbolTable::declare_tmp(Type type, antlr4::ParserRuleContext * ctx)
{
    string tmp = get_next_tmp();
    return declare_symbol(tmp, type, ctx);
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