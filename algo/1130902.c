/**
  *     Name:   Shubham Chaudhary
  *     Lab:    ADA
  *     Date:   Jan 15, 2013
  *     Program:To find power a^n
  **/
#include<stdio.h>
//#include<conio.h>
int sqrCase(int a,int n);
int nearestMul(int input);
int general(int a,int n);
int main(){
    int a,n;
    int nearest;
    //clrscr();
    int choice;
    do{
        printf("\n\n* * * W E L C O M E * * *");
        printf("\n    1 .   Find Power");
        printf("\n    2 .   Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("\nEnter a^n: ");
                scanf("%d %d",&a,&n);
                //printf("\nYou entered %d^%d.",a,n);
                //printf("\nSolution sqrCase: %d^%d = %d",a,n,sqrCase(a,n));
                printf("\nSolution General: %d^%d = %d",a,n,general(a,n));
                break;
            case 2:
                printf("\n* * * THANKS * * *");
                break;
            default:
                printf("\nWish you knew how to count ! ! !");
                break;
        }
    }while(choice!=2);

    //getch();
    return 0;
}
int sqrCase(int a,int n){  //when n is 2^k
    if(n==1){
        return (a);   //Base Case
    }
    else{
        a=sqrCase(a,n/2)*sqrCase(a,n/2);
    }
}
int general(int a,int n){
    //int out=0;
    int near;
    near=nearestMul(n);  //nearestMul(n) returns nearest 2^k multiple of n.
    if(near==1){
        return (a);   //Base Case: 2^1
    }
    else if(near==n){
        return(sqrCase(a,near));
    }
    else{
        a=sqrCase(a,near)*general(a,n-near);
    }
}



int nearestMul(int in){  //$: To find nearest multiple of 2
    int count=0,out=1,i;
    while (in!=1){
    	in=in>>1;
    	count+=1;
    }
    for(i=0;i<count;i++)    //To find power i.e. 2^k
        out*=2;
    //return(pow(2,count));  //NOTE return the nearest value of k for 2^k
    return (out);
}
/* Test Values
    2^19=524288,
    3^19= 1162261467,
    4^15=1073741824
*/
