#include "ir-symbol-table.h"
#include "ir-base.h"
#include "ir-errors.h"
#include "params/ir-symbol.h"
#include "../error-reporter/compiler-error-token.h"

namespace IR
{
    int SymbolTable::symbol_offset = 0;
    vector<SymbolTable *> SymbolTable::symbol_tables = {};

    SymbolTable::SymbolTable()
    {
        symbol_tables.push_back(this);
    }

    SymbolTable::~SymbolTable()
    {
        for (pair<const string, Symbol *> symbol : symbols)
        {
            delete symbol.second;
        }
    }

    Symbol * SymbolTable::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx, bool const_var, int tableSize)
    {
        if (symbols.find(id) != symbols.end())
        {
            throw IRSymbolError("symbol '" + id + "' already declared");
        }

        symbol_offset -= size_to_bytes(type.size);
        
        
        Symbol * symbol = new Symbol;

        symbol->set_parent(parent);
        symbol->set_ctx(ctx);
        symbol->id = id;
        symbol->type = type;
        symbol->const_var = const_var;
        symbol->used = id[0] == "!"[0];
        symbol->offset = symbol_offset;
        symbol_offset -= type.size / 8 * tableSize;
        symbols[id] = symbol;

        return symbol;
    }

    IR::Symbol * IR::SymbolTable::declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx)
    {
        string tmp = get_next_tmp();
        return declare_symbol(parent, tmp, type, ctx);
    }

    Symbol * SymbolTable::get_symbol(string id, antlr4::ParserRuleContext * ctx)
    {
        if (symbols.find(id) == symbols.end() || symbols[id]->offset == 0)
        {
            throw IRSymbolError("symbol '" + id + "' not declared");
        }

        symbols[id]->used = true;

        return symbols[id];
    }

    string SymbolTable::get_next_tmp()
    {
        string tmp = "!tmp" + to_string(tmp_offset);
        tmp_offset++;
        
        return tmp;
    }

    vector<Symbol *> SymbolTable::get_unused_symbols()
    {
        vector<Symbol *> unused_symbols;
        for (pair<const string, Symbol *> symbol : symbols)
        {
            if (!symbol.second->used)
            {
                unused_symbols.push_back(symbol.second);
            }
        }

        return unused_symbols;
    }

    vector<Symbol *> SymbolTable::get_all_unused_symbols()
    {
        vector<Symbol *> unused_symbols;
        for (SymbolTable * symbol_table : symbol_tables)
        {
            vector<Symbol *> table_unused_symbols = symbol_table->get_unused_symbols();
            unused_symbols.insert(unused_symbols.end(), table_unused_symbols.begin(), table_unused_symbols.end());
        }

        return unused_symbols;
    }
}

