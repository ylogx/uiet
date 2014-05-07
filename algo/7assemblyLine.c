/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     Assembly Line Scheduling - Find fastest way out of factory
 **/
#include <stdio.h>
//Global Constants
const int rMax=2+1,cMax=20;
int min(int,int);
int main(){
    int
        a[rMax][cMax],  //assembly time at station S[i,j]
        e[rMax],
        x[rMax],        //entry and exit time for respective lines
        t[rMax][cMax];  //transfer cost to shift from jth station of line i to j+i of other line
                        //to transfer to the other line after station S[i,j]
    int f[rMax][cMax];  //fastest time to reach station j of s[i] line
    int l[rMax][cMax];
    int final,lFinal,i,j,n;
    //===Get Input===
    printf("\nEnter no of stations: ");
    scanf("%d",&n);
    for(i=1;i<=2;i++){
        printf("Enter e[%d]: ",i);
        scanf("%d",&e[i]);
    }
    for(i=1;i<=2;i++){
        for(j=1;j<=n;j++){
            printf("Enter a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=2;i++){
        for(j=1;j<=n-1;j++){    //not for last station
            printf("Enter t[%d][%d]: ",i,j);
            scanf("%d",&t[i][j]);
        }
    }
    for(i=1;i<=2;i++){
        printf("Enter x[%d]: ",i);
        scanf("%d",&x[i]);
    }
    //===End Input===
    //-----------fastest way---------------
    //int j;
    f[1][1]=e[1]+a[1][1];
    f[2][1]=e[2]+a[2][1];
    for(j=2;j<=n;j++){
        if( f[1][j-1] + a[1][j] <= f[2][j-1] + t[2][j-1] + a[1][j] ){
            f[1][j]=f[1][j-1]+a[1][j];
            l[1][j]=1;
        }
        else{
            f[1][j]=f[2][j-1]+t[2][j-1]+a[1][j];
            l[1][j]=2;
        }
        if( f[2][j-1] + a[2][j] <= f[1][j-1] + t[1][j-1] + a[2][j] ){
            f[2][j]=f[2][j-1] + a[2][j];
            l[2][j]=2;
        }
        else{
            f[2][j]=f[1][j-1] + a[2][j];
            l[2][j]=1;
        }
    }
    if( f[1][n]  + x[1] <= f[2][n] + x[2] ){
        final=f[1][n] + x[1];
        lFinal=1;
    }
    else{
        final=f[2][n] + x[2];
        lFinal=2;
    }
    //-------------------------------------
    //=============print fast==============
    i=lFinal;
    printf("\nLine %d, Station %d",i,n);
    for(j=n;j >= 2;j--){
        i=l[i][j];
        printf("\nLine %d, Station %d",i,j-1);
    }
    //=====================================
    printf("\nFinal Time: %d\n",final);
    return 0;
}
inline int min(int a,int b){
    return( a<b ? a : b );
}
