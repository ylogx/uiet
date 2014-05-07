/*Write a program to take password from user*/
#include<stdio.h>
#define MAX 500

int main(){

    char password[MAX];
    char p;
    int i=0;

    printf("Enter the password:");
   
    while((p=getch())!= 13){
         password[i++] = p;
         printf("*");
    }

    password[i] = '\0';

    if(i<6)
         printf("\nWeak password");

    printf("\nYou have entered: %s",password);

    return 0;
}
