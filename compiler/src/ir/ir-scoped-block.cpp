#include "ir-scoped-block.h"
#include "ir-errors.h"

namespace IR
{
    Symbol * IRScopedBlock::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx, int personalized_offset)
    {
        cerr << "Declare symbol " << id << " in :" << endl;
        log();
        return symbolTable.declare_symbol(parent, id, type, ctx, personalized_offset);
    }

    Symbol * IRScopedBlock::get_symbol(string id, antlr4::ParserRuleContext * ctx)
    {
        cerr << "Get symbol " << id << " in :" << endl;
        log();
        try
        {
            return symbolTable.get_symbol(id, ctx);
        }
        catch (IRSymbolError e)
        {
            if (parentScope != nullptr)
            {
                return parentScope->get_symbol(id, ctx);
            }
            
            throw e;
        }
    }

    Symbol * IRScopedBlock::declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx)
    {
        return symbolTable.declare_tmp(parent, type, ctx);
    }

    int IRScopedBlock::get_st_size()
    {
        int offset = symbolTable.get_symbol_offset();

        return offset == 0
            ? 0
            : ((-offset / 16)+1)*16;
    }

    int IRScopedBlock::log()
    {
        int depth = 1;
        if (parentScope != nullptr)
        {
            depth += parentScope->log();
        }

        for (int i = 0; i < depth; ++i)
        {
            cerr << "  ";
        }
        cerr << this << " (" << ref << ")" << endl;

        return depth;
    }
}