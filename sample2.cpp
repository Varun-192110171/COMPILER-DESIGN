#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char inp[10];
	int n,i,flg=0;	
	printf("enter any string: ");
	scanf("%s",inp);
	int l=strlen(inp);
	for(i=0;i<l;i++){
		if((inp[i]=='/')&&(inp[i+1]=='/')){
			flg=1;
			break;
		}
		else if((inp[i]=='/')&&(inp[i+1]=='*')){
			flg=1;
			break;
		}
	}
	if(flg==1)
	   printf("it is a commented line");
	else
	   printf("it is not a commented line ");
}

