%{
	#include<stdio.h>
	int num=0;
%}

%token A B


%%
input:S
    S:A C B|B
    C:A C|;
%%

void main(){
printf("Enter the expression: ");
yyparse();
if(num==0) printf("valid\n");
}

int yyerror(){
printf("Invalid expression..\n");
num=1;
return -1;
}
