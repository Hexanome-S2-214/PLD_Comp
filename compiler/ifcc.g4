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
     : TYPE_FUNCTION fname=VAR '(' fparam_decla ')' struct_bloc
     ;

functionCallRule
     : fname=VAR '(' fparam_call ')'
     ;

TYPE_FUNCTION
     : 'int'
     | 'void'
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

//=============================================
// Règles de base
//=============================================

content
     : statement
     | struct_element
     ;

statement
     : declarationRule        # declaration
     | instructionRule        # instruction
     ;

struct_element
     : struct_bloc
     | struct_if_else
     | struct_while
     ;

//=============================================
// Rules
//=============================================

declarationRule
     : declStdRule       # declStd
     | declAffRule       # declAff
     ;

instructionRule
     : returnStmtRule         # returnStmt
     | affectationRule        # affectation
     | functionCallRule ';'   # functionCall
     ;

declStdRule
     : CONST? (INT|CHAR) VAR ';'
     ;

declAffRule
     : CONST? (INT|CHAR) VAR '=' rvalue ';'
     ;

affectationRule
     : VAR '=' rvalue ';'
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
