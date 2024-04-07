#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "../generated/ifccLexer.h"
#include "../generated/ifccParser.h"
#include "../generated/ifccBaseVisitor.h"

#include "ir/ir-cfg.h"
#include "ir/ir-symbol-table.h"
#include "ir-visitor.h"
#include "error-reporter/error-reporter.h"
#include "error-reporter/error-listener.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
    stringstream in;
    if (argn == 2)
    {
        ifstream lecture(argv[1]);
        in << lecture.rdbuf();
    }
    else
    {
        cerr << "usage: ifcc path/to/file.c" << endl;
        exit(1);
    }

    ANTLRInputStream input(in.str());

    ErrorReporter::ErrorReporter *error_reporter = ErrorReporter::ErrorReporter::getInstance();
    ErrorReporter::ErrorListener *error_listener = new ErrorReporter::ErrorListener(error_reporter);

    ifccLexer lexer(&input);

    lexer.removeErrorListeners();
    lexer.addErrorListener(error_listener);

    CommonTokenStream tokens(&lexer);

    tokens.fill();

    ifccParser parser(&tokens);

    parser.removeErrorListeners();
    parser.addErrorListener(error_listener);

    tree::ParseTree *tree = parser.axiom();

    if (parser.getNumberOfSyntaxErrors() != 0)
    {
        cerr << "error: syntax error during parsing" << endl;
        exit(1);
    }

  IR::CfgSet * cfg_set = static_cast<IR::CfgSet *>(
    (new IR::CfgSet())
      ->set_error_reporter(new ErrorReporter::ErrorReporter())
      ->set_arch(IR::IRArch::X86)
  );
  IRVisitor visitor(cfg_set);

    visitor.visit(tree);

  IR::asm_arch = IR::X86;
  cfg_set->gen_asm(cout);
    map<int, vector<ErrorReporter::CompilerError *>> errors_to_report

    for (auto symbol : IR::SymbolTable::get_all_unused_symbols())
    {
        ErrorReporter::CompilerErrorToken *error = new ErrorReporter::CompilerErrorToken(
            ErrorReporter::WARNING,
            "'" + symbol->id + "' is declared but never used. Variable declared here:",
            symbol->get_ctx());

        errors_to_report[error->getLine()].push_back(error);
    }

    for (auto function : cfg_set->get_unused_functions())
    {
        ErrorReporter::CompilerErrorToken *error = new ErrorReporter::CompilerErrorToken(
            ErrorReporter::WARNING,
            "function '" + function->name + "' is declared but never used. Function declared here:",
            function->ctx);

        errors_to_report[error->getLine()].push_back(error);
    }

    for (auto &pair : errors_to_report)
    {
        for (auto error : pair.second)
        {
            error_reporter->reportError(error);
        }
    }

    if (error_reporter->getShouldThrow())
    {
        exit(1);
    }

    cfg_set->gen_asm(cout);

    delete cfg_set;
    delete error_reporter;

    return 0;
}
