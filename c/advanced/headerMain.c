#include<stdio.h>
#include"headerFun.h"
int main(){
    int i;
    printf("Enter last no: ");
    scanf("%d",&i);
    printf("\nCalling header function ");
    printCounting(i);
}
