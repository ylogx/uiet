#include<stdio.h>
#include<stdlib.h>
//**prototype**
void practice();
void firstClassProb();
void main(){
    int choice;
    practice();
    do{
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                firstClassProb();
                break;
            case 2:
                break;
            default:
                printf("\nError in Input");
                break;
        }
    }while(choice!=2);

}
void firstClassProb(){
    //To find nearest multiple of 2
    int i=0,in;
    printf("\nEnter a #: ");
    scanf("%d",&in);
    while (in!=1){
    	in=in>>1;
    	i++;
    	printf("\ni=%d:   in>>1=%d",i,in);
    }
    printf("\n\nEnd: i=%d,    in=%d",i,in);

}

void practice(){
    int a,b,c,d;
    a=2;
    b=64;
    c=13;
    d=99;
    printf("\n* * * Practice Function * * *\na=%d b=%d c=%d d=%d",a,b,c,d);
    a=a>>2;
    b=b<<2;
    c=c>>3;
    d=d<<5;
    printf("\na>>2=%d    b<<2=%d    c>>3=%d    d<<5=%d\n",a,b,c,d);
}
