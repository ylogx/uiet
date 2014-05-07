/**
  *     Name:   Shubham Chaudhary
  *     Lab:    ADA
  *     Date:   Jan 29, 2013
  *     Roll:   UE113090
  *     Program:To perform selectionsort
  **/
#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
#define SIZE 10
//*** prototype ***
int min(int *ptr,int lo,int hi);
void display(int *);
void selSort(int *,int);
//*** main ***
int main(){
    int arr[SIZE]={32,99,56,10,12,9,11,1,6,8};
    //clrscr();
    //system("clear");
    printf("\n\n\t\t\t  * * *  Welcome  * * * ");
    display(arr);
    selSort(arr,SIZE);
    display(arr);
    //getch();
    return 0;
}
void selSort(int *ptr, int size){
    int i,temp,minUnsort;
    for(i=0;i<size;i++){
        minUnsort=min(ptr,i,size);    //after i
        //exchange this and first unsorted
        temp=ptr[i];
        ptr[i]=ptr[minUnsort];
        ptr[minUnsort]=temp;
        display(ptr);
    }
}
int min(int *ptr,int lo,int hi){
    int i,min=ptr[lo],minIndex=lo;
    for(i=lo+1;i<hi;i++){
        if(ptr[i]<min){
            min=ptr[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void display(int *ptr){
    int i;
    printf("\nArray is: ");
    for(i=0;i<SIZE;i++){
        printf("%d\t",ptr[i]);
    }
    printf("\n");
}
/*
Consider sorting n numbers stored in array A by first finding the smallest element
of A and exchanging it with the element in A[1]. Then find the second smallest
element of A, and exchange it with A[2]. Continue in this manner for the first n-1
elements of A. Write pseudocode for this algorithm, which is known as selection
sort.
* * * * * * * * O U T P U T * * * * * * * * * * *
* chaudhary@Dell-XPS-L502XC:~/code/algo$ valgrind --leak-check=full ./1130904se
==7091== Memcheck, a memory error detector
==7091== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==7091== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==7091== Command: ./1130904se
==7091== 


			  * * *  Welcome  * * * 
Array is: 32	99	56	10	12	9	11	1	6	8	

Array is: 1	99	56	10	12	9	11	32	6	8	

Array is: 1	6	56	10	12	9	11	32	99	8	

Array is: 1	6	8	10	12	9	11	32	99	56	

Array is: 1	6	8	9	12	10	11	32	99	56	

Array is: 1	6	8	9	10	12	11	32	99	56	

Array is: 1	6	8	9	10	11	12	32	99	56	

Array is: 1	6	8	9	10	11	12	32	99	56	

Array is: 1	6	8	9	10	11	12	32	99	56	

Array is: 1	6	8	9	10	11	12	32	56	99	

Array is: 1	6	8	9	10	11	12	32	56	99	

Array is: 1	6	8	9	10	11	12	32	56	99	
==7091== 
==7091== HEAP SUMMARY:
==7091==     in use at exit: 0 bytes in 0 blocks
==7091==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7091== 
==7091== All heap blocks were freed -- no leaks are possible
==7091== 
==7091== For counts of detected and suppressed errors, rerun with: -v
==7091== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

*/
