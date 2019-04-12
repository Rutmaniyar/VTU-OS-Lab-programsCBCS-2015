%{
	#include<stdio.h>
	#include "y.tab.h"
	extern FILE *yyin;
%}

%token key
%token id
%token op
%token num

%%
input:key input
      |id input
      |num input
      |op input
      |;
%%

main(){
	FILE *f1;
	yyin=fopen("file6b.c","r");;
	yyparse();
}

int yyerror(){
printf("Invalid expression..\n");
return -1;
}
