#include<stdio.h>
main()
{
int a=1,b=2;
swapr(&a,&b);
printf("After swap\na=%d, b=%d",a,b);
}
swapr(int *x, int*y) 
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}
