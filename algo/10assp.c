/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     All pair shortest path
 **/
#include<stdio.h>
// - - - Global Variables - - -
int cost[10][10],P[10][10] ={0};
int D[10][10][10];
// - - - prototype - - -
void assp(int);
void path(int,int);

int main()
{
	int i,j,n,k;
	printf("\nEnter no. of nodes: ");
	scanf("%d",&n);
	//Matrix Input
	printf("\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				cost[i][j] = 0;
			}else{
				printf("Enter the cost of element [%d,%d]: ",i,j);
				scanf("%d",&cost[i][j]);
			}
		}
	}
	//Display matrix user fed
    printf("\nYou Entered: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
    //Call algorithm
	assp(n);
    //Display states of different matrix
	printf("\nDifferent matrices are: \n");
	for(k=0;k<n;k++){
		printf("Matrix %d\n",k);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d\t",D[k][i][j]);
			}
			printf("\n");
		}
	}
    //Display path for different pairs
    printf("\n\n==============================\n");

	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("\nPath for (%d,%d)\n",i,j);
                path(i,j);
		}
		printf("\n-------------------------\n");
	}

    path(0,n);
	return 0;
}

void path(int q,int r){
      if(P[q][r]!=0){
            path(q,P[q][r]);
            printf("Vertex %d ->  ",P[q][r]);
            path(P[q][r],r);
       }
}


// * * * Algo for all pair shortest path * * *
void assp(int n){
	int i,j,k;
        for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				D[0][i][j] = cost[i][j];
				//printf("%d",D[0][i][j]);  //debugging
			}
		}
		for(k=1;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(D[k-1][i][j]>(D[k-1][i][k] + D[k-1][k][j])){
						D[k][i][j] = D[k-1][i][k] + D[k-1][k][j];
						P[i][j] = k;
					}
					else{
						D[k][i][j] = D[k-1][i][j];
					}
				}
			}
		}

}

