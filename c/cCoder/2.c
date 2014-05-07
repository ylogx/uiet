//Shubham Chaudhary
#include <stdio.h>
#include <stdlib.h>
int i,j;
int loca,locb;
int moves=0;
int mat[4][4];
int tes[16]={1,4,15,7, 8,10,2,11, 14,3,6,13, 12,9,5,0};
void init(){
    int count=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            mat[i][j]=tes[count++];
        }
    }
    loca=3;
    locb=3;
}
void dis(){
    system("clear");
    for(i=0;i<4;i++){
        printf("---------------------------------------------------------\n");       //
        for(j=0;j<4;j++){
            if(!mat[i][j]){
                printf("_\t|\t");
            }else{
                printf("%d\t|\t",mat[i][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------------\n");       //
    printf("\nMoves: %d",moves);
    printf("\nPress 'e' to exit\n");
}
void left(){
    //
    int tempu;
    if(locb-1>=0){
        //temp0=locb-1;
        tempu=mat[loca][locb-1];
        mat[loca][locb]=tempu;
        mat[loca][locb-1]=0;
        moves+=1;
        locb-=1;
    }else{
        printf("\nInvalid\n");
    }
    dis();
}
    
void right(){
    //
    int tempu;
    if(locb+1<=3){
        //temp0=locb+1;
        tempu=mat[loca][locb+1];
        mat[loca][locb]=tempu;
        mat[loca][locb+1]=0;
        moves+=1;
        locb+=1;
        
        dis();
    }else{
        printf("\nInvalid\n");
    }
}
void up(){
    //
    int tempu;
    if(loca-1>=0){
        //temp0=loca-1;
        tempu=mat[loca-1][locb];
        mat[loca][locb]=tempu;
        mat[loca-1][locb]=0;
        moves+=1;
        loca-=1;
        dis();
    }else{
        printf("\nInvalid\n");
    }
}
void down(){
    //
    int tempu;
    if(loca+1<=3){
        //temp0=loca+1;
        tempu=mat[loca+1][locb];
        mat[loca][locb]=tempu;
        mat[loca+1][locb]=0;
        moves+=1;
        loca+=1;
        
        dis();
    }else{
        printf("\nInvalid\n");
    }
}
void check(){
    int count=1;
    int valid=1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(valid && mat[i][j]!=count++){
                valid=0;
                printf("\n\nSorry not in ascending order\n\n");
                break;
            }
        }
    }
    if(valid==1){
        printf("\n\nCongratulation you did it in %d moves",moves);
    }
    exit(0);
}
void game(){
    char in;
    while(1){
        printf("\nEnter: ");
        //system("ssty cbreak -echo");
        in=getchar();
        //system("ssty cbreak -echo");
        //scanf("%c",&in);
        printf("%c",in);
        switch(in){
            case 'a':
                left(); break;
            case 's':
                down(); break;
            case 'd':
                right(); break;
            case 'w':
                up(); break;
            case 'e':
                check(); break;
            default:
                printf("\npress e when done\n");
                dis();
                break;
        }
    }
}

int main(){
    init();
    dis();
    game();
    
    return 0;
}
