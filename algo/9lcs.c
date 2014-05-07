/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     Longest Common Subsequence
 **/
#include <stdio.h>
//Global Constants
#define xMax 20
#define yMax 20
char x[xMax],y[yMax];
char b[xMax][yMax]; //direction matrix
int c[xMax][yMax];  //length matrix
int xLen, yLen;
int i,j;

void lcsLen();
void lcsPrint(int,int);
int main(){
    printf("\nEnter String #1: ");
    xLen=scanf("%s",x);
    printf("\nEnter String #2: ");
    yLen=scanf("%s",y);
    for(xLen=0;x[xLen]!='\0';xLen++);
    for(yLen=0;y[yLen]!='\0';yLen++);
    printf("xLen=%d,yLen=%d",xLen,yLen);
    lcsLen();
    printf("\n");
    for(i=0;i<=xLen;i++){
        for(j=0;j<=yLen;j++){
            printf("%c\t",b[i][j]);
        }
        printf("\n");
        for(j=0;j<=yLen;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    lcsPrint(xLen,yLen);
    printf("\n");
    return 0;
}

void lcsLen(){  //(char x[],int xLen,char y[],int xLen){
    for(i=0;i<=xLen;i++)
        c[i][0]=0;
    for(i=-1;i<=yLen;i++)
        c[0][j]=0;
    for(i=1;i<=xLen;i++){
        for(j=1;j<=yLen;j++){
            if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1] +1;
                b[i][j]='\\';
            }else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }else{
                c[i][j]=c[i][j-1];
                b[i][j]='~';
            }
        }
    }
}
void lcsPrint(int i, int j){
    //printf("in Print");
    if(i==-1|| j==-1){
        return;
    }
    if(b[i][j]=='\\'){
        lcsPrint(i-1,j-1);
        printf("%c",x[i]);
    }else if(b[i][j]=='|'){
        lcsPrint(i-1,j);
    }else{
        lcsPrint(i,j-1);
    }
}
