#include<stdio.h>
main()
{
int n,sum=0,i;
printf("Enter n to find 1! + 2! + . . . + n! : ");
scanf("%d",&n);
for (i=1;i<=n;i++)
sum=sum+fac(i);
printf("1! + 2! + . . . + %d! = %d\n",n,sum);
}
fac (int a)
{
int i,out=1;
for (i=a;i>=1;i--)
out=out*i;
return(out);
}
