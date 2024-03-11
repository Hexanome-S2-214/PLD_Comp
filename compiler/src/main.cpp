#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "antlr4-runtime.h"
#include "generated/ifccLexer.h"
#include "generated/ifccParser.h"
#include "generated/ifccBaseVisitor.h"

#include "CodeGenVisitor.h"
#include "SymbolTableVisitor.h"

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

  ifccLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();

  ifccParser parser(&tokens);
  tree::ParseTree* tree = parser.axiom();

  if(parser.getNumberOfSyntaxErrors() != 0)
  {
      cerr << "error: syntax error during parsing" << endl;
      exit(1);
  }

  SymbolTableVisitor s;
  s.visit(tree);
  s.checkAllVariablesUsed();

  std::cout<< ".globl main\n" ;
  std::cout<< " main: \n" ;
  std::cout<< "    # prologue\n" ;
  std::cout<< "    pushq %rbp\n" ;
  std::cout<< "    movq %rsp, %rbp\n" ;

  CodeGenVisitor v(&s);
  v.visit(tree);
  
  std::cout << "    # epilogue\n";
  std::cout << "    popq %rbp\n";
  std::cout << "    ret\n";

  return 0;
}
