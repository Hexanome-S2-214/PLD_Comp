#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "../generated/ifccLexer.h"
#include "../generated/ifccParser.h"
#include "../generated/ifccBaseVisitor.h"

// #include "CodeGenVisitor.h"
// #include "SymbolTableVisitor.h"
#include "ir/ir-cfg.h"
#include "ir-visitor.h"
#include "error-reporter/error-reporter.h"
#include "error-reporter/error-listener.h"

using namespace antlr4;
using namespace std;

int main(int argn, const char **argv)
{
  stringstream in;
  if (argn==2)
  {
     ifstream lecture(argv[1]);
     in << lecture.rdbuf();
  }
  else
  {
      cerr << "usage: ifcc path/to/file.c" << endl ;
      exit(1);
  }
  
  ANTLRInputStream input(in.str());

  ErrorReporter::ErrorReporter * error_reporter = new ErrorReporter::ErrorReporter();
  ErrorReporter::ErrorListener * error_listener = new ErrorReporter::ErrorListener(error_reporter);

  ifccLexer lexer(&input);

  lexer.removeErrorListeners();
  lexer.addErrorListener(error_listener);

  CommonTokenStream tokens(&lexer);

  tokens.fill();

  ifccParser parser(&tokens);

  parser.removeErrorListeners();
  parser.addErrorListener(error_listener);

  tree::ParseTree* tree = parser.axiom();

  if(parser.getNumberOfSyntaxErrors() != 0)
  {
      cerr << "error: syntax error during parsing" << endl;
      exit(1);
  }

  IR::CFG * cfg = static_cast<IR::CFG *>(
    (new IR::CFG())
      ->set_error_reporter(error_reporter)
      ->set_arch(IR::X86)
  );
  IRVisitor visitor(cfg);

  visitor.visit(tree);

  cfg->gen_asm(cout);

  delete cfg;
  delete error_reporter;

  return 0;
}
