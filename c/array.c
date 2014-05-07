#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

char b[10][10];

int main(){
    int i,j;
    for (i=0;i<10;++i){
        for (j=0;j<10;++j){
            b[i][j] = i*10 +j+1;
            printf("%d ",b[i][j]);
        }
    }
    char** d = (char**)malloc(10*sizeof(char*));
    for(i=0;i<10;++i)
        d[i]=(char*)malloc(10*sizeof(char));
    memcpy(d,b,sizeof(b));
    printf("d");
    for (i=0;i<10;++i)
        for (j=0;j<10;++j)
            printf("%d ",d[i][j]);
    return 0;
}
