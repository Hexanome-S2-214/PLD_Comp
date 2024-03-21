#include "ir-symbol-table.h"
#include "ir-base.h"
#include "params/ir-symbol.h"
#include "../error-reporter/compiler-error-token.h"

namespace IR
{
    Symbol * SymbolTable::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx)
    {
        if (symbols.find(id) != symbols.end())
        {
            this->error_reporter->reportError(new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "symbol " + id + " already declared", ctx));
            exit(1);
        }

        Symbol * symbol = new Symbol;

        symbol->set_parent(parent);
        symbol->set_ctx(ctx);
        symbol->id = id;
        symbol->offset = symbol_offset;
        symbol->type = type;

        symbols[id] = symbol;

        symbol_offset -= SYMBOL_SIZE;

        return symbol;
    }

    Symbol * SymbolTable::declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx)
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

