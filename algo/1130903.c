/**
  *     Name:   Shubham Chaudhary
  *     Lab:    ADA
  *     Date:   Jan 15, 2013
  *     Roll:   UE113090
  *     Program:To find power a^n
  **/
#include<stdio.h>
//#include<conio.h>
#define SIZE 10
//*** prototype ***
void getInput(int *);
int position(int *ptr,int lo,int hi);
void qSort(int *ptr,int lo,int hi);
void display(int *ptr,int lo,int size);
//*** main ***
void main(){
    int i;
    int arr[SIZE]={32,34,56,10,12,9,11,2,1,6,8};
    clrscr();
    printf("\n\n* * *Welcome  * * * ");
    //getInput(arr);
    display(arr,0,SIZE);
    qSort(arr,0,SIZE);
    display(arr,0,SIZE);
    getch();
}
void getInput(int *ptr){
    int i;
    printf("\nEnter %d elements: ",SIZE);
    for(i=0;i<SIZE;i++)
	scanf("%d",ptr+i);
}
void qSort(int *ptr,int lo,int hi){
    int base;
    if(hi-lo<=1){
	return;
    }
    else{
	base=position(ptr,lo,hi);
	printf("\nIn qSort: lo=%d,hi=%d:base=%d",lo,hi,base);
	display(ptr,lo,hi);
	qSort(ptr,lo,base-1);    //lower subarray
	qSort(ptr,base+1,hi);    //upper subarray
    }
}
int position(int *ptr,int lo,int hi){
    //shifts first(@lo) element to its correct position
    int i,j,temp,pivot,count;
    count=lo;
    pivot=ptr[lo];
    //printf("\nlo=%d,hi=%d,pivot=%d",lo,hi,pivot);
    for(i=lo;i<hi;i++){
	//printf("\nForLoopi=%d,count=%d,ptr[i]=%d,lo=%d,hi=%d,pivot=%d",i,count,ptr[i],lo,hi,pivot);
	if(ptr[i]<=pivot){
	    //printf("\nIf in for Loopi=%d,count=%d,ptr[i]=%d,lo=%d,hi=%d,pivot=%d",i,count,ptr[i],lo,hi,pivot);
	    temp=ptr[i];
	    for(j=i-1;j>=0;j--){   //shift all nos
		ptr[j+1]=ptr[j];
		//printf("\t%d goes to %d\t",ptr[j],ptr[j+1]);
	    }
	    ptr[lo]=temp;
	    count++;
	}//end if
	//printf("\nIn for loop i=%d,count=%d: ",i,count);
	display(ptr,lo,hi);
    }//end for
    return count;
}
void display(int *ptr,int lo,int size){
    int i;
    printf("\nArray is: ");
    for(i=lo;i<size;i++)
	printf("%d\t",ptr[i]);
}
