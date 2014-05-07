#include<stdio.h>
main()
{
int i;
printf("Enter the last number you want: ");
for (scanf("%d",&i);i>=1;i--)
{
	printf("%d\t",i);
}
}
