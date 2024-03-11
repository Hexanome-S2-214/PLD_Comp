#include "ir-symbol-table.h"

IR::Symbol * IR::SymbolTable::declare_symbol(string id, Type type, antlr4::ParserRuleContext * ctx)
{
    if (symbols.find(id) != symbols.end())
    {
        cerr << "Error: symbol " << id << " already declared" << endl;
        exit(1);
    }

    IR::Symbol * symbol = new IR::Symbol();

    symbol->offset = symbol_offset;
    symbol->used = false;
    symbol->type = type;
    symbol->ctx = ctx;

    symbols[id] = *symbol;

    symbol_offset -= SYMBOL_SIZE;

    return symbol;
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