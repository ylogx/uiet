/**
  *     Name:   Shubham Chaudhary
  *     Lab:    ADA
  *     Date:   Jan 29, 2013
  *     Roll:   UE113090
  *     Program:To perform insertionsort
  **/
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#define SIZE 11
//*** prototype ***
//void display(int* ptr,int lo=0,int size=SIZE);
void display(int*,int,int);
void insSort(int*,int);
void insSortHome(int*,int);
//*** main ***
int main(){
    int arr[SIZE]={32,99,56,10,12,9,11,2,1,6,8};
    //clrscr();
    system("clear");
    printf("\n\n\t\t\t     * * *  Welcome  * * * \n");
    printf("\n\n\t\t\t  * * *  Insertion Sort  * * * \n");
    display(arr,0,SIZE);
    insSortHome(arr,SIZE);
    display(arr,0,SIZE);
    printf("\n");
    //getch();
    return 0;
}

void insSortHome(int *ptr, int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key=ptr[i];
        for(j=i-1;j>=0&&ptr[j]>key;j--){
            if(ptr[j]>key){     //shift
                ptr[j+1]=ptr[j];
            }
        }
        ptr[j+1]=key;
        display(ptr, 0,SIZE);
    }
}
void insSort(int *ptr, int size){
    int i,key;
    for(i=1;i<size;i++){
        int j;
        key=ptr[i];
        //position(ptr,0,i);
        for(j=i-1;j>=0&&ptr[j]>key;j--){
            if(ptr[j]>key){
                ptr[j+1]=ptr[j];
                //temp=ptr[j];
                //ptr[j]=ptr[i];
                //ptr[i]=temp;
                //j-=1;
            }
        }
        ptr[j+1]=key;
    }
}
/*
void position(int * ptr,int lo,int end){
    int i;
    for(i=lo;i<end;i++){
    }
}
*/
void display(int *ptr,int lo,int size){
    int i;
    printf("\nArray is: ");
    for(i=lo;i<size;i++)
    printf("%d\t",ptr[i]);
}
/* * * * * * O U T P U T * * * * 
chaudhary@Dell-XPS-L502XC:~/code/algo$ valgrind --leak-check=full ./1130904in.out
==6374== Memcheck, a memory error detector
==6374== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==6374== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==6374== Command: ./1130904in.out
==6374== 



                 * * *  Welcome  * * * 


              * * *  Insertion Sort  * * * 

Array is: 32    99  56  10  12  9   11  2   1   6   8   
Array is: 1 2   6   8   9   10  11  12  32  56  99  
==6374== 
==6374== HEAP SUMMARY:
==6374==     in use at exit: 0 bytes in 0 blocks
==6374==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6374== 
==6374== All heap blocks were freed -- no leaks are possible
==6374== 
==6374== For counts of detected and suppressed errors, rerun with: -v
==6374== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
* * * * * * * * * * * * *  ** * * */
