%{
	#include<stdio.h>
%}
%token Num
%left '+' '-'
%right '*' '/'
%nonassoc UMINUS

%%
	stmt:exp {printf("Result is %d\n",$$);}
	exp:exp'+'exp {$$=$1+$3;}
	   |exp'-'exp {$$=$1-$3;}
	   |exp'*'exp {$$=$1*$3;}
	   |exp'/'exp {if($3==0) {printf("Division by 0 error"); return;} else $$=$1/$3;}
	   |'-'exp%prec UMINUS {$$=-$2;}
	   |'('exp')' {$$=$2;}
	   |Num {$$=$1;}
%%

main(){
printf("Enter the expression: ");
yyparse();
}

int yyerror(){
printf("Syntax error");
return -1;
}
