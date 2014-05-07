#include<stdio.h>
#include<stdlib.h>
int main(){
  int *p,*q;
  int x=7;
  p=(int *)malloc(sizeof(int));
  *p=x;
  q=p;
  printf("p=%d, q=%d",*p,*q);
  p=(int *)malloc(sizeof(int));
  *p=5;
  free(p);
  printf("p=%d, q=%d",*p,*q);
  return;
} 
