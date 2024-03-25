#include "ir-symbol-table.h"
#include "ir-base.h"
#include "params/ir-symbol.h"
#include "../error-reporter/compiler-error-token.h"

namespace IR
{
    SymbolTable::~SymbolTable()
    {
        for (pair<const string, Symbol *> symbol : symbols)
        {
            delete symbol.second;
        }
    }

    IR::Symbol * IR::SymbolTable::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx, int tableSize)
    {
        if (symbols.find(id) != symbols.end())
        {
            this->error_reporter->reportError(new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "symbol " + id + " already declared", ctx));
            exit(1);
        }

        symbol_offset -= type.size;

        IR::Symbol * symbol = new IR::Symbol();

        symbol->set_parent(parent);
        symbol->set_ctx(ctx);
        symbol->id = id;
        symbol->offset = symbol_offset;
        symbol->type = type;

        symbols[id] = symbol;

        if(type == IR::Int){
            if(tableSize == -1){
                symbol_offset -= INT_SIZE;
            } else {
                symbol_offset -= INT_SIZE * tableSize;
            }
        } else if (type == IR::Char){
            if(tableSize == -1){
                symbol_offset -= CHAR_SIZE;
            } else {
                symbol_offset -= CHAR_SIZE * tableSize;
            }
        }

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
            this->error_reporter->reportError(new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "symbol " + id + " not declared", ctx));
            exit(1);
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

}

