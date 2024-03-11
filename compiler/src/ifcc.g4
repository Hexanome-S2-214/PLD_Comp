grammar ifcc;

axiom : prog EOF ;

prog: 'int' 'main' '(' ')' '{' statement* '}';

statement: declarationRule # declaration | instructionRule # instruction;

declarationRule: declStdRule # declStd | declAffRule # declAff;

instructionRule: returnStmtRule # returnStmt | affectationRule # affectation;


declStdRule: 'int' VAR ';';
declAffRule: 'int' VAR '=' expr ';';

affectationRule: VAR '=' expr ';';

returnStmtRule: RETURN expr ';';

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
