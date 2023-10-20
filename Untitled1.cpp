#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	fp=fopen("sample.txt","r");
	if(fp==NULL){
		printf("the file cannot be opened: ");
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF){
		for(i=0;i<6;i++){
			if(ch==op[i]){
				printf("operator: %c",op[i]);
			}
			else if(isalpha(ch)){
				buffer[j++]=ch;
			}
			else if((ch==" "||ch='\n')&&(j!=0)){
				buffer[i]='\0';
				j=0;
				if (keyword(buffer)==1){
					printf("keyword %s",buffer);
				}
				else
				    printf("identifier: %s",buffer);
			}
		}
	}
fclose(fp);
return 0;	
}
