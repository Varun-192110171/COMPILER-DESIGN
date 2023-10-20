%{ 
#include<stdio.h>
%} 
%% 
if|else|while|int|switch|for|char  {printf("\n %s is keyword");}
[0-9]*  {printf("\n %s is digit");}
[a-zA-Z]*  {printf("\n %s is word");}
.*  {printf("Invalid");}
%% 
int main() 
{ 
    yylex();
    return 1; 
}
int yywrap()
{
    return 1;
}