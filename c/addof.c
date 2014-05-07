#include<stdio.h>
main()
{
int i;
int *j;
j=&i;
printf("j=%u,i=%d,&i=%u,&j=%u",j,i,&i,&j);
//printf("&i=%u",&i);
}
