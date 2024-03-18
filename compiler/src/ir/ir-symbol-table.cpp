#include "ir-symbol-table.h"
#include "ir-reg.h"
#include "ir-base.h"
#include "../error-reporter/compiler-error-token.h"

IR::Symbol::Symbol(IRBase * parent, string id, int offset, Type type, antlr4::ParserRuleContext * ctx) : id(id), offset(offset), type(type) {
    set_parent(parent);
    set_ctx(ctx);
}

void IR::Symbol::gen_asm(ostream& o)
{
    o << offset << IR::IRRegStack(this).get_asm_str();
}

IR::Symbol * IR::SymbolTable::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx, int tableSize)
{
    if (symbols.find(id) != symbols.end())
    {
        this->error_reporter->reportError(new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "symbol " + id + " already declared", ctx));
        exit(1);
    }

    IR::Symbol * symbol = new IR::Symbol(parent, id, symbol_offset, type, ctx);
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

IR::Symbol * IR::SymbolTable::get_symbol(string id, antlr4::ParserRuleContext * ctx)
{
    if (symbols.find(id) == symbols.end())
    {
        this->error_reporter->reportError(new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "symbol " + id + " not declared", ctx));
        exit(1);
    }

    symbols[id]->used = true;

    return symbols[id];
}

string IR::SymbolTable::get_next_tmp()
{
    string tmp = "!tmp" + to_string(tmp_offset);
    tmp_offset++;

    return tmp;
}

