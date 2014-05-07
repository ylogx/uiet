#include<stdio.h>
main()
{
printf("flag 1");
fun1();
printf("flag 2");
fun2();
printf("flag 3");
}
fun1()
{
printf("fflag 1");
fun2();
}
fun2()
{
printf("fflag 2");
}

