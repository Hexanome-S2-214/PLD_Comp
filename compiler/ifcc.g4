grammar ifcc;

//=============================================
// Axiome et macro-règles
//=============================================

axiom
     : prog EOF
     ;

prog
     : 'int' 'main' '(' ')' '{' statement* '}'
     ;

statement
     : declarationRule        # declaration
     | instructionRule        # instruction
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
     : CONST? (INT|CHAR) VAR '=' expr ';'
     ;

affectationRule
     : VAR '=' (expr | affectationRule) ';'
     ;

returnStmtRule
     : RETURN (expr | affectationRule) ';'
     ;

//=============================================
// Non-terminaux
//=============================================

expr
     : expr '+' expr                    #exprSomme
     | expr '-' expr                    #exprSoustr
     | '-' expr                         #exprUnaryMinus
     | '!' expr                         #atomUnaryNot
     | expr OP_MULT expr                #exprMultDiv
     | expr MODULO expr                 #exprModulo
     | expr COMPARAISON expr            #exprComparaison
     | expr EQ_COMPARAISON expr         #exprEqComparaison
     | expr AND expr                    #exprAnd
     | expr OR expr                     #exprOr
     | VAR                              #atomVar
     | NUM                              #atomNum
     | '(' expr ')'                     #atomParExpr
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
