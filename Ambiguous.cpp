#include<stdio.h>
#include<conio.h>
#include<string.h>
char pro[10][10];
int main(){
	int n,flg=0,l,j,i;
	printf("enter the number of productions: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("production no %d : ",i+1);
		scanf("%s",pro[i]);
	}
	for(i=0;i<n;i++){
		l=strlen(pro[i]);
		for(j=0;j<l;j++){
			if(pro[i][j]=='|'){
				flg=1;
				break;
			}
		}
		if(flg==1)
		   break;
	}
	if(flg==1)
	printf("Ambiguous grammer: ");
	else
	printf("unambiguous grammer: ");
return 0;

}
