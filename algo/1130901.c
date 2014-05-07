#include<stdio.h>
#include<conio.h>
#define SIZE 5
//***global variable***
int a[SIZE];
//**Prototype**
void binRec(int lo,int hi,int key);
void binItr(int lo,int hi,int key);
//**main**
int main(){
    int i,lo,hi,key;
    clrscr();
    printf("\nEnter %d elements: ",SIZE);
    for(i=0;i<SIZE;i++){
	scanf("%d",&a[i]);
    }
    hi=SIZE-1;
    lo=0;
    printf("\nEnter Key: ");
    scanf("%d",&key);
    binRec(lo,hi,key);
    binItr(lo,hi,key);
    //for(i=0;i<SIZE;i++)
    //	printf("%d",a[i]);
    getch();
    return 0;

}
void binRec(int lo,int hi,int key){
    float mid;
    mid=(lo+hi)/2;
    if(mid<0 || mid>SIZE){
	printf("\nNot Found");
	return;
    }
    else if(a[mid]==key){
	printf("\nRecursive: %d found at position %d\n",key,((int)mid)+1);
	return;
    }
    else if(a[mid]<key){
	//lo=mid+1;
	binRec((int)mid+1,hi,key);
    }
    else{    //a[mid]>key
	//hi=mid-1;
	binRec(lo,(int)mid-1,key);
    }

}
void binItr(int lo,int hi,int key){
    float mid;
    while (1){
    mid=(lo+hi)/2;
    if(mid<0 || mid>SIZE){
	printf("\nNot Found");
	break;
    }
    else if(a[mid]==key){
	printf("\nIterative: %d found at position %d\n",key,((int)mid)+1);
	break;
    }
    else if(a[mid]<key){
	lo=mid+1;
	//binRec((int)mid+1,hi,key);
    }
    else{    //a[mid]>key
	hi=mid-1;
	//binRec(lo,(int)mid-1,key);
    }
    }//end while
}