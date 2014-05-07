#include<stdio.h>
main()
{
int a,b;
printf("Enter Number to find Factorial: " );
scanf("%d",&a);
b=rec(a);
printf("Factorial of %d= %d\n",a,b);
}
rec (int x)
{
int y;
if (x==1)
return(1);
else
y=x*rec(x-1);

return (y);
}
