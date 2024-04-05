#include "ir-scoped-block.h"
#include "ir-errors.h"
#include "ir-basic-block.h"
#include "../error-reporter/compiler-error.h"

namespace IR
{
    Symbol * IRScopedBlock::declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx, int personalized_offset)
    {
        try {
            return symbolTable.declare_symbol(parent, id, type, ctx, personalized_offset);
        } catch (IRSymbolError e) {
            ErrorReporter::ErrorReporter::getInstance()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, e.what(), ctx)
            );
            return new Symbol; // Return a dummy symbol to continue compilation (we do this in case we find other errors)
        }
    }

    Symbol * IRScopedBlock::get_symbol(string id, antlr4::ParserRuleContext * ctx)
    {
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
            
            ErrorReporter::ErrorReporter::getInstance()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, e.what(), ctx)
            );

            return new Symbol; // Return a dummy symbol to continue compilation (we do this in case we find other errors)
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

    void IRScopedBlock::set_parent_scope(IRScopedBlock * parent)
    {
        parentScope = parent;
    }
}