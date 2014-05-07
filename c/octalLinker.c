#include<stdio.h>
extern int x;   //declaration
int main(){
    do{
        do{
            printf("%o",x);
        }
        while(!-2);
    }
    while(0);
    return 0;
}
int x=8;    //definition
