#include<stdio.h>
#define max(a,b) (a>b ? a : b)
//***Prototype***

int matrix[100][100] = {0};
//****Main****
int main(){
    int noItem=4;
    int knapSize = 10;
    int weights[4]={5,4,6,3};
    int values[4]={10,40,30,50};
    printf("Max Value: %d",knapsack(noItem-1,knapSize,weights,values));
    return 0;
}
int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;
        for (i=1;i<=nItems;i++){
            for (j=0;j<=size;j++){
                if (weights[i-1]<=j){
                    matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                }
                else{
                    matrix[i][j] = matrix[i-1][j];
                }
            }
        }
        return matrix[nItems][size];
}
void printPicks(int item, int size, int weights[]){
    while (item>0){
        if (picks[item][size]==1){
            printf("%d ",item-1);
            item--;
            size -= weights[item];
        }
        else{
            item--;
        }
    }
    printf("\n");
    return;
}
