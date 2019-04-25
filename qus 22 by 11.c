#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
		int counter=0;
		int out_var=0;
		int safe_count=0;
	int work[]={1,5,2,0};
	int allocation[][4]={0,0,1,2,1,0,0,0,1,3,5,4,0,6,3,2,0,0,1,4};
	int max[][4]={0,0,1,2,1,7,5,0,2,3,5,6,0,6,5,2,0,6,5,6};
	int need[5][4];
	bool finish[]={false,false,false,false};
	int seq_list[5];
	int i,j,x;
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	printf("Need Matrix is:-\n\n");
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
		printf("%d    ",need[i][j]);
		}
		printf("\n");
	}
	

while(1){

out_var=0;
	for( i=0;i<5;i++){
		for( j=0;j<4;j++){
			if(finish[i]!=false||need[i][j]>work[j]){
				break;
			}
			else{
				if(j==3){
						for( x=0;x<4;x++){
							work[x]=work[x]+allocation[i][x];
						}
						seq_list[counter]=i;
						counter++;
						out_var++;
						safe_count++;
						finish[i]=true;
				}
			}
		}
	}
	if(out_var==0){
		break;
	}
	}
	if(safe_count!=5){
		printf("\n\nSystem is in unsafe state\n");
	}
	else{
			printf("\n\nSystem is in safe state\n");
			printf("\nSafe sequence is \n");
			for( i=0;i<5;i++){
				printf("P%d -> ",seq_list[i]);
			}
			printf("end\n");
			printf("\n\nTotal available are:-\n");
				for( i=0;i<4;i++){
				printf("%d -> ",work[i]);
			}
			printf("end\n");
	}
}
