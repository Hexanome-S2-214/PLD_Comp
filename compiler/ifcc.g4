grammar ifcc;

//=============================================
// Axiome et macro-règles
//=============================================

axiom
     : prog EOF
     ;

prog
     : decla_function*
     ;

//=============================================
// Fonctions
//=============================================

fparam_call
     : (fparam_call2(',' fparam_call2)*)?
     ;

fparam_call2
     : VAR
     | NUM
     | expr    //expr includes functionCallRule
     ;

fparam_decla
     : (fparam_decla2(',' fparam_decla2)*)?
     ;

fparam_decla2
     : 'int' VAR
     ;

decla_function
     : return_type=('int' | 'void') fname=VAR '(' fparam_decla ')' struct_bloc
     ;

functionCallRule
     : fname=VAR '(' fparam_call ')'
     ;

//=============================================
// Structures de contrôle
//=============================================

struct_bloc
     : '{' content* '}'
     ;

struct_if_else
     : 'if' '(' expr ')' struct_bloc ('else' struct_bloc)?
     ;

struct_while
     : 'while' '(' expr ')' struct_bloc
     ;

struct_switch_case
     : 'switch' '(' expr ')' '{' 
          case_opt*
          default_opt?
      '}'
     ;
     
case_opt
     : 'case' case_val ':' case_block     //important : no '*' here 
     ;

default_opt
     : 'default' ':' case_block
     ;

case_val
     : NUM
     | CHARACTER
     ;

case_block
     : content*
     ;

//=============================================
// Règles de base
//=============================================

content
     : statement
     | struct_element
     ;

statement
     : declarationRule
     | instructionRule
     ;

struct_element
     : struct_bloc
     | struct_if_else
     | struct_while
     | struct_switch_case
     ;

declarationRule
     : declStdRule       # declStd
     | declAffRule       # declAff
     ;

instructionRule
     : returnStmtRule         # returnStmt
     | affectationRule        # affectation
     | functionCallRule ';'   # functionCall
     | 'break' ';'            # breakStmt
     | 'continue' ';'         # continueStmt
     ;

declStdRule
     : (INT|CHAR) VAR ';'                  #simpleDecl
     | (INT | CHAR) VAR '[' NUM ']' ';'    #tableDecl
     ;

declAffRule
     : CONST? (INT|CHAR) VAR '=' rvalue ';'
     ;

affectationRule
     : VAR '=' rvalue ';'               #simpleAff
     | VAR '[' NUM ']' '=' rvalue ';'   #tableAff
     ;

affectationRule2
     : VAR '=' rvalue
     ;

rvalue
     : functionCallRule       //you can't do func() = func2()
     | affectationRule2
     | expr
     ;

returnStmtRule
     : RETURN rvalue ';'
     ;

//=============================================
// Expressions
//=============================================

expr
     : '(' expr ')'                     #exprParExpr
     | VAR '[' NUM ']'                  #exprTable
     | op_unary=('-' | '!') expr        #exprUnary
     | expr OP_MULT expr                #exprMultDivMod
     | expr op_add=('+' | '-') expr     #exprSumSous
     | expr COMPARAISON expr            #exprComparaison
     | expr EQ_COMPARAISON expr         #exprEqComparaison
     | expr B_AND expr                  #exprAndBAB
     | expr B_XOR expr                  #exprXorBAB
     | expr B_OR expr                   #exprOrBAB
     | expr AND expr                    #exprAnd
     | expr OR expr                     #exprOr
     | functionCallRule                 #exprFunctionCall
     | CHARACTER                        #exprCharacter
     | VAR                              #exprVar
     | NUM                              #exprNum
     ;

//=============================================
// Opérateurs
//=============================================

EQ_COMPARAISON
     : '=='
     | '!='
     ;

COMPARAISON
     : '<'
     | '>'
     | '<='
     | '>='
     ;

OP_MULT
     : '*'
     | '/'
     | '%'
     ;

OP_SUM
     : '+'
     | '-'
     ;

MODULO
     : '%'
     ;

OR
     : '||'
     ;

AND
     : '&&'
     ;

B_AND
     : '&'
     ;

B_OR
     : '|'
     ;

B_XOR
     : '^'
     ;

//=============================================
// Terminaux
//=============================================

RETURN
     : 'return'
     ;

CONST
     : 'const'
     ;

CHAR
     : 'char'
     ;

INT
     : 'int'
     ;

NUM
     : [0-9]+
     ;

VAR
     : [a-zA-Z][a-zA-Z0-9_]*
     ;


CHARACTER
     : '"' [a-zA-Z0-9_ ] '"'
     | '\'' [a-zA-Z0-9_ ] '\''
     ;

COMMENT
     : '/*' .*? '*/' -> skip
     ;

DIRECTIVE
     : '#' .*? '\n' -> skip
     ;

WS
     : [ \t\r\n] -> channel(HIDDEN)
     ;

