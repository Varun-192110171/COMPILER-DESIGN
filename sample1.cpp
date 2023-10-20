#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char inp[10];
	int n,i;
	
	
	printf("enter any string: ");
	scanf("%s",inp);
	int l=strlen(inp);
	for(i=0;i<l;i++){
		if(isalpha(inp[i])){
			printf("\nidentifier: %c",inp[i]);
		}
		else if(isdigit(inp[i])){
			printf("\nconstant:%c ",inp[i]);
		}
		else if(isspace(inp[i])){
			continue;
		}
		else{
			printf("\noperator: %c",inp[i]);
		}
	}
	
}
