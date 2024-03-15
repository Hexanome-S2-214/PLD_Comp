grammar ifcc;

//=============================================
// Axiome et macro-règles
//=============================================

axiom
     : prog EOF
     ;

prog
     : 'int' 'main' '(' ')' '{'
               content*
               '}'
     ;

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
     : returnStmtRule    # returnStmt
     | affectationRule   # affectation
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
     : ( affectationRule2 | expr)
     ;

returnStmtRule
     : RETURN rvalue ';'
     ;

//=============================================
// Expressions
//=============================================

expr
     : '(' expr ')'                     #exprParExpr
     | '-' expr                         #exprUnaryMinus
     | '!' expr                         #exprUnaryNot
     | expr OP_MULT expr                #exprMultDiv
     | expr MODULO expr                 #exprModulo
     | expr '+' expr                    #exprSomme
     | expr '-' expr                    #exprSoustr
     | expr COMPARAISON expr            #exprComparaison
     | expr EQ_COMPARAISON expr         #exprEqComparaison
     | expr B_AND expr                  #exprAndBAB
     | expr B_XOR expr                  #exprXorBAB
     | expr B_OR expr                   #exprOrBAB
     | expr AND expr                    #exprAnd
     | expr OR expr                     #exprOr
     | VAR                              #exprVar
     | NUM                              #exprNum
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
