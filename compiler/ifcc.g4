grammar ifcc;

axiom : prog EOF ;

prog : 'int' 'main' '(' ')' '{' statements '}' ;

statements : statement | statement statements ;
statement : affectation | declaration | return_stmt | declAff ;

declaration: 'int' VAR ';' ;
affectation: VAR '=' expr ';' ; 
return_stmt: RETURN expr ';' ;
declAff : 'int' VAR '=' expr ';';
expr : '(' expr ')' #exprPar
     | '-' expr #exprNeg
     | expr (MULT | DIV) expr #exprMultDiv
     | expr (PLUS | MINUS) expr #exprSousSomme
     | VAR #exprVar
     | CONST #exprConst
     ;


RETURN : 'return' ;
CONST : [0-9]+ ;
VAR : [a-zA-Z][a-zA-Z0-9_]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
MULT : '*' ;
DIV : '/' ;
PLUS : '+' ;
MINUS : '-' ;
