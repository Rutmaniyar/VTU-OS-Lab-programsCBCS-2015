%{
	#include<stdio.h>
	int id=0,op=0;
%}

%%
[0-9] {printf("the identifier is:%s\n",yytext); ++id;}
['\+','\*','\(','\)','\{','\}','/[','/]'] { printf("the operator is:%s\n",yytext); ++op;}
[a-z]|[A-Z] {printf("invalid identifier in expression:%s\n",yytext);}
[-,/] {printf("invalid operator in expression:%s\n",yytext);}

%%

main(){
	printf("enter the expression:");
	yylex();
	printf("the number of identifiers are:%d\n",id);
	printf("the number of operators are:%d\n",op);
	
}
