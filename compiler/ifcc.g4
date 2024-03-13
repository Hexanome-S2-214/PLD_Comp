grammar ifcc;

axiom : prog EOF ;

prog: 'int' 'main' '(' ')' '{' statement* '}';

statement: declarationRule # declaration | instructionRule # instruction;

declarationRule: declStdRule # declStd | declAffRule # declAff;

instructionRule: returnStmtRule # returnStmt | affectationRule # affectation;


declStdRule: CONST? (INT|CHAR) VAR ';';
declAffRule: CONST? (INT|CHAR) VAR '=' expr ';';

affectationRule: VAR '=' expr ';';

returnStmtRule: RETURN expr ';';

expr : '(' expr ')' #exprPar
     | expr INCREMENT #exprIncrement
     | (UNARY_OP|INCREMENT) expr #exprUnaryOp
     | expr (MULT | DIV) expr #exprMultDiv
     | expr MODULO expr #exprModulo
     | expr (PLUS | MINUS) expr #exprSousSomme
     | expr COMPARAISON expr #exprComparaison
     | expr EQ_COMPARAISON expr #exprEqComparaison
     | VAR #exprVar
     | NUM #exprNUM
     | expr AND expr #exprAnd
     | expr OR expr #exprOr
     | expr OP_AFFECTATION expr #exprAffectation
     ;


RETURN : 'return' ;
CONST : 'const';
CHAR : 'char';
INT : 'int';
NUM : [0-9]+ ;
VAR : [a-zA-Z][a-zA-Z0-9_]* ;
COMMENT : '/*' .*? '*/' -> skip ;
DIRECTIVE : '#' .*? '\n' -> skip ;
WS    : [ \t\r\n] -> channel(HIDDEN);
EQ_COMPARAISON : '==' | '!=';
COMPARAISON : '<' | '>' | '<=' | '>=';
UNARY_OP : '-' | '!' | '~';
INCREMENT : '++' | '--';
MULT : '*' ;
DIV : '/' ;
PLUS : '+' ;
MINUS : '-' ;
MODULO : '%';
OR : '||';
AND : '&&';
OP_AFFECTATION : '+=' | '-=' | '*='| '/=' | '=';
B_AND : '&';
B_OR : '|';
B_XOR : '^';


