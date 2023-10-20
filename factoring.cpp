#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i=0,j=0,k=0;
	char gram[10],part1[10],part2[10],alpha[10],beta1[10],beta2[10];
	
	printf("\nenter the grammer: A->");
	scanf("%s",gram);
	while(gram[i]!='|'){
		part1[j]=gram[i];
		j++;
		part1[j]='\0';
		i++;
	}

	i=strlen(part1)+1,j=0;
		while(gram[i]!='\0'){
		part2[j]=gram[i];
		j++;
		part2[j]='\0';
		i++;
	}

	i=0;
	j=0;
	while(part1[i]==part2[i]){
		alpha[j]=part2[i];
		j++;
		alpha[j];
		i++;
	}
    printf("\nalpha   %s",alpha);
    printf("%d",strlen(alpha));
    
    k=strlen(alpha);
	j=0;
	for(i=k;part1[i]!='\0';i++,j++){
		beta1[j]=part1[i];
	}
  	printf("\nalpha   %s",alpha);
	 printf("%d",strlen(alpha));
	j=0;
	for(i=strlen(alpha);part2[i]!='\0';i++,j++){
		beta2[j]=part2[i];
	}
		printf("\nalpha   %s",alpha);
	printf("\npart1   %s",part1);
	printf("\npart2   %s",part2);
	
	printf("\nbeta   %s",beta1);
    printf("\nbeta2   %s",beta2);
	printf("\nthe given grammer after eliminating left factoring");
	printf("\nA->%s A'",alpha);
	printf("\nA'->%s | %s",beta1,beta2);
	
}
