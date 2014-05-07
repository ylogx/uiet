#include<stdio.h>
struct nodeS{
    int info;
    struct nodeS * next;
};
typedef struct nodeS* NODEPTR;
int main(){
    int choice;
    printf("Enter operation # -\nYou have the following choices:\n");
    printf("1. Push\n2. Pop\n3.exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: break;
        }
    }while(choice!=3);
}
push(){
    int ele;
    printf("Enter element to push: ");
    scanf("%d",&ele);

