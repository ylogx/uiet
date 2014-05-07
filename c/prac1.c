#include<stdio.h>
//To point out odd or even
void main()
{
int input;
printf("Enter 1 no.: ");
scanf("%d",&input);
if (input%2==0)
{
printf("It's an even no\n");}
else if (input%2!=0)
{
printf("It's an odd no\n");}
else
{
printf("this is an invalid input . . .\nPlease Run again . . .");}
}
