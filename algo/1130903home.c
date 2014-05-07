/**
  *     Name:   Shubham Chaudhary
  *     Lab:    ADA
  *     Date:   Jan 15, 2013
  *     Roll:   UE113090
  *     Program:To perform quicksort
  **/
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#define SIZE 11
//*** prototype ***
void getInput(int *);
int position(int *ptr,int lo,int hi);
int positionHome(int *ptr,int lo,int hi);
int partition(int *ptr,int lo,int hi);
void qSort(int *ptr,int lo,int hi);
void display(int *ptr,int lo,int size);
//*** main ***
int main(){
    int arr[SIZE]={32,34,56,10,12,9,11,2,1,6,8};
    //clrscr();
    system("clear");
    printf("\n\n\t\t\t  * * *  Welcome  * * * ");
    //getInput(arr);
    printf("\n\t\t\t* * * ORIGINAL Array * * *\n");
    display(arr,0,SIZE);
    qSort(arr,0,SIZE-1);
    printf("\n\n\t\t\t* * * FINAL Array * * *\n");
    display(arr,0,SIZE);
    //getch();
    return 0;
}
void getInput(int *ptr){
    int i;
    printf("\nEnter %d elements: ",SIZE);
    for(i=0;i<SIZE;i++)
	scanf("%d",ptr+i);
}
void qSort(int *ptr,int lo,int hi){
    int base;
    if(lo<hi){
	    base=positionHome(ptr,lo,hi);
	    //base=partition(ptr,lo,hi);
	    //printf("\nIn qSort: lo=%d,hi=%d:base=%d",lo,hi,base);
	    //display(ptr,lo,hi);
	    display(ptr,0,SIZE);
	    qSort(ptr,lo,base-1);    //lower subarray
	    qSort(ptr,base+1,hi);    //upper subarray
    }
}
void display(int *ptr,int lo,int size){
    int i;
    printf("\nArray is: ");
    for(i=lo;i<size;i++)
	printf("%d\t",ptr[i]);
}
int partition(int*ptr,int lo,int hi){
    // shifts last element(pivot) to its correct position
    //  l - c | - -| j -| h
    //  2 1 3 | 8 7| 5 6| 4
    //  --<=--|-->-|unchk|pivot
    //  pg 7.172
    int pivot,count,j,temp;
    pivot=ptr[hi];
    count=lo-1;
    for(j=lo;j<=hi-1;j++){
        if(ptr[j]<=pivot){
            count+=1;
            //exchange ptr[count] and ptr[j]
            temp=ptr[count];
            ptr[count]=ptr[j];
            ptr[j]=temp;
        }
    }
    //exchange ptr[i+1] (a ele higher than pivot) with ptr[hi] i.e. our pivot; NOTE still in '>' partiton
    temp=ptr[count+1];
    ptr[count+1]=ptr[hi];
    ptr[hi]=temp;
    return count+1;
}
int positionHome(int *ptr,int lo,int hi){
    //shifts first(@lo) element to its correct position
    int i,temp,pivot,count;
    count=lo;
    pivot=ptr[lo];
    //printf("\nlo=%d,hi=%d,pivot=%d",lo,hi,pivot);
    for(i=hi;i>lo;i--){
	    //printf("\nForLoopi=%d,count=%d,ptr[i]=%d,lo=%d,hi=%d,pivot=%d",i,count,ptr[i],lo,hi,pivot);
	    if(ptr[i]>pivot){
	        //printf("\nIf in for Loopi=%d,count=%d,ptr[i]=%d,lo=%d,hi=%d,pivot=%d",i,count,ptr[i],lo,hi,pivot);
	        count+=1;
	        temp=ptr[count];
	        ptr[count]=ptr[i];
	        ptr[i]=temp;
	    }//end if
	    //printf("\nIn for loop i=%d,count=%d: ",i,count);
    }//end for
	temp=ptr[count];
	ptr[count]=ptr[lo];
	ptr[lo]=temp;
	printf("\nAfter position home: lo=%d,hi=%d,pivot=%d",lo,hi,pivot);
	display(ptr,lo,hi);
    return count;
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
