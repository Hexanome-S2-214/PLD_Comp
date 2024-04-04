#pragma once

#include "ir-symbol-table.h"
#include "../error-reporter/error-reporter.h"

namespace IR
{
    class IRScopedBlock
    {
    public:
        Symbol * declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx = nullptr, int personalized_offset = 0);
        Symbol * get_symbol(string id, antlr4::ParserRuleContext * ctx = nullptr);

        Symbol * declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx = nullptr);

        int get_st_size();

        void set_parent_scope(IRScopedBlock * parent) { parentScope = parent; }
        IRScopedBlock * get_parent_scope() { return parentScope; }

        void set_error_reporter(ErrorReporter::ErrorReporter * errorReporter) { this->errorReporter = errorReporter; }

        int log();
        string ref = "";
    private:
        SymbolTable symbolTable;
        ErrorReporter::ErrorReporter * errorReporter;
        IRScopedBlock * parentScope;
    };
}
