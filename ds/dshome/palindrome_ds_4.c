/*
		DS Lab- 3
	   CSE Sec 2, Group 5
	      Aug 29, 2012
	       UE 113090
    Implementation of Queue using arrays
*/
#include<stdio.h>
//#include<conio.h>

//*******Functions used********
void getstring();
void push(int);
int pop();
void check();

#define MAX 10

//******Global Variable********
int top;
int arr[MAX];


//******Main Function**********
void main()
{
  
