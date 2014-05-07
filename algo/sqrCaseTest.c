#include<stdio.h>
//#include<conio.h>
int sqrCase(int a,int n);
int nearestMul(int input);
int general(int a,int n);
int main(){
    int a,n;
    //clrscr();
    //input
    printf("\nEnter a^n: ");
    scanf("%d %d",&a,&n);
    printf("\nYou entered %d^%d.",a,n);

    printf("\nSolution: %d^%d = %d",a,n,sqrCase(a,n));
    //getch();
    return 0;
}
int sqrCase(int a,int n){  //when n is 2^k
    if(n==1){
        return a;
    }
    else{
        a=sqrCase(a,n/2)*sqrCase(a,n/2);
    }
}
