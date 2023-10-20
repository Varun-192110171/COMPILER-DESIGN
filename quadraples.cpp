#include<stdio.h>
#include<string.h>
char inp[10][10]={'\0'};
int main()
{
	int n,i;
	printf("\nenter the number of input expressions: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nenter the expression number %d :",i+1);
		scanf("%s",inp[i]);
	}
	for(i=0;i<n;i++){
		printf("\n mov %c,R%d",inp[i][2],i);
		if(inp[i][3]=='+'){
		   printf("\n add %c,R%d",inp[i][4],i);
		}
		else if(inp[i][3]=='-'){
		   printf("\n sub %c,R%d",inp[i][4],i);
		}
		else if(inp[i][3]=='*'){
		   printf("\n mul %c,R%d",inp[i][4],i);
		}
	    printf("\nmov R%d,%c",i,inp[i][0]);
	}
}
