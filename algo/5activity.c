/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     Activity Selection Problem via greedy approach
 **/
#include<stdio.h>
#define DEBUG1
//***Global Variable****
#ifdef DEBUG1
#define SIZE 11
int s[SIZE]={1,3,0,5,3,5, 6,8, 8, 2, 12};   //start time array
int f[SIZE]={4,5,6,7,9,9,10,11,12,14,16};   //finish time array
#endif
#ifdef DEBUG2
#define SIZE 8
int s[SIZE]={1,4,6,8,10,12,14,16};   //start time array
int f[SIZE]={3,5,7,9,11,13,15,17};   //finish time array
#endif
//NOTE: assumption-already sorted by finish time
int select[SIZE]={0};
//****Prototype***
void activitySelector();
void printSelection();
void sortBin();
void insSortHome();

//****MAIN***
int main(){
    //sortBin();
    insSortHome();
    //printSelection();
    activitySelector();
    printSelection();
    return 0;
}
void activitySelector(){
    int i;
    for(i=0;i<SIZE;i++)
        printf("\ts[%d]=%d - f[%d]=%d",i,s[i],i,f[i]);
    int lastFinish=f[0];
    select[0]=1;    //activity finishing earliest is always selected
    for(i=1;i<SIZE;i++){
        if(s[i]>lastFinish){
            select[i]=1;
            lastFinish=f[i];
        }
    }
}
void printSelection(){
    int i;
    printf("\n\n---------------------\n\n");
    for(i=0;i<SIZE;i++){
        printf("\n\t\t\tselect(%d)=%d",i,select[i]);
        if(select[i]){
            printf("\ts=%d\tf=%d",s[i],f[i]);
        }
    }
    printf("\n\n----------------------\n\n");
}
void sortBin(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE-i+1;j++){
            if(f[j]<f[j-1]){
                int temp=f[j];
                f[j]=f[j-1];
                f[j-1]=temp;
            }
        }
    }
    printf("\nAfter sorting: \n");
    for(i=0;i<SIZE;i++)
        printf("\ts[%d]=%d - f[%d]=%d\t",i,s[i],i,f[i]);
}
    
void insSortHome(){
    int i,j,key,temp;
    for(i=1;i<SIZE;i++){
        key=f[i];
        temp=s[i];
        for(j=i-1;j>=0&&f[j]>key;j--){
            if(f[j]>key){     //shift
                f[j+1]=f[j];
                s[j+1]=s[j];
            }
        }
        f[j+1]=key;
        s[j+1]=temp;
        //display(ptr, 0,SIZE);
    }
    printf("\nAfter sorting: \n");
    for(i=0;i<SIZE;i++)
        printf("\ts[%d]=%d - f[%d]=%d\t",i,s[i],i,f[i]);
}

/********************
After sorting: 
	s[0]=1 - f[0]=4		s[1]=3 - f[1]=5		s[2]=0 - f[2]=6		s[3]=5 - f[3]=7		s[4]=3 - f[4]=9		s[5]=5 - f[5]=9		s[6]=6 - f[6]=10		s[7]=8 - f[7]=11		s[8]=8 - f[8]=12	s[9]=2 - f[9]=14		s[10]=12 - f[10]=16		s[0]=1 - f[0]=4	s[1]=3 - f[1]=5	s[2]=0 - f[2]=6	s[3]=5 - f[3]=7	s[4]=3 - f[4]=9	s[5]=5 - f[5]=9	s[6]=6 - f[6]=10	s[7]=8 - f[7]=11	s[8]=8 - f[8]=12	s[9]=2 - f[9]=14s[10]=12 - f[10]=16

---------------------


			select(0)=1	    s=1	f=4
			select(1)=0
			select(2)=0
			select(3)=1	    s=5	f=7
			select(4)=0
			select(5)=0
			select(6)=0
			select(7)=1	    s=8	f=11
			select(8)=0
			select(9)=0
			select(10)=1	s=12	f=16

----------------------
*****************************/
