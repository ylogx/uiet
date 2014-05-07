#include<stdio.h>
#define length(x) (sizeof x/sizeof *x)
int insert(int *array, int val, size_t size,size_t at)
{
  size_t i;
  //In range?
  if(at>=size)
    return -1;
  //shift elements to make a hole
  for(i=size -1;i>at;i--)
    array[i]=array[i-1];
  //Insertion
  array[at]=val;
  return 0;
}
int main(void)
{
  int a[11]={0,1,2,3,4,5,6,7,8,9};
  int i;
  if(insert(a,6,length(a),3)!=-1)
    {
      for(i=0;i<length(a);i++)
	printf("%-3d",a[i]);
      printf("\n");
    }
  else
    fprintf(stderr,"Insertion failed\n");
  return 0;
}
