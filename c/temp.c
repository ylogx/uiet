#include<stdio.h>
int main(){
    int i,j;
    for(i=3;i<8;i++){
    int out=11;
        for(j=0;j<i-1;j++){
            out*=11;
        }
        printf("%d\n",out);
    }
    return 0;
}
