#include<stdio.h> 
#include<ctype.h>
#include<string.h>
char intercode[5][300]={{"100: if(a<b) goto(103)"},{"101: t=0"},{"102: goto(104)"},{"103: t=1"},{"104:  "}};
int main()
{ int a,b;
	printf("\nTHREE ADDRESS CODE: \n100: if(a<b) goto(103)\n101: t=0\n102: goto(104)\n103: t=1\n104:  ");
	printf("enter the value of A:");
	scanf("%d",&a);
	printf("enter the value of B:");
	scanf("%d",&b);
	if(a<b){
		printf("%s",intercode[0]);
		printf("%s",intercode[3]);
		printf("%s",intercode[4]);
	}
	else{
		printf("%s",intercode[0]);
		printf("%s",intercode[1]);
		printf("%s",intercode[2]);
		printf("%s",intercode[4]);
	}
	
}
