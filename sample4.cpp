#include<stdio.h>
#include<string.h>
#include<ctype.h>
void FIRST(char[],char );
void addToResultSet(char[],char);
int numOfProductions;
char productionSet[10][10];
int main()
{
    int i;
    char choice;
    char c;
    char result[20];
    printf("Enter the number of productions :");
    scanf(" %d",&numOfProductions);
    for(i=0;i<numOfProductions;i++)//read production string eg: E=E+T
    {
        printf("Enter production %d : ",i+1);
        scanf(" %s",productionSet[i]);
    }
    do
    {
        printf("\n Find FIRST of  :"); 
        scanf(" %c",&c);
        FIRST(result,c); //Compute FIRST; Get Answer in 'result' array
        printf("\n FIRST(%c)= { ",c);
        for(i=0;result[i]!='\0';i++)
        printf(" %c ",result[i]);       //Display result
        printf("}\n");
         printf("press 'y' to continue : ");
        scanf(" %c",&choice);
    }
    while(choice=='y'||choice =='Y');
    return 0;
}

void FIRST(char Result[],char c){
    int i,j,k,l;
    
    char subResult[20];
    int foundepsilon;
    subResult[0]='\0';
    Result[0]='\0';
	if(islower(c)){
	   addToResultSet(Result,c);
	}
		for(i=0;i<numOfProductions;i++){
			l=strlen(productionSet[i]);
			if(productionSet[i][0]==c){
				
				 if(productionSet[i][2]=='$')
				  addToResultSet(Result,'$');
				  
				 else{
				    for(j=2;j<l;j++){
				    	foundepsilon=0;
				    	FIRST(subResult,productionSet[i][j]);
				    	for(k=0;subResult[k]!='\0';k++){
				    		addToResultSet(Result,subResult[k]);
						}
						for(k=0;subResult[k]!=0;k++){
							if(subResult[k]=='$'){
								foundepsilon=1;
								break;
							}
						}
						if(!foundepsilon)
						   break;
					} 
			    }
		   }
		}
}

void addToResultSet(char Result[],char val){
	int k;
	for(k=0;Result[k]!='\0';k++)
		if(Result[k]==val){
			return;
		}
	Result[k]=val;
		Result[k+1]='\0';
}
