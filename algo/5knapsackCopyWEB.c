#include<stdio.h>
int w[22]={9,13,153,50,15,68,27,39,23,52,11,32,24,48,73,42,43,22,7,18,4,30};
int p[22]={150,35,200,60,60,45,60,40,30,10,70,30,15,10,40,70,75,80,20,12,50,10};
int v[22][22],n=22,i,j,cap=400,x[22]={0};

int max(int i,int j)
{
  return ((i>j)?i:j);
}
int knap(int i,int j)
{
  int value;
  if(v[i][j]<0)
    {
      if(j<w[i])
	value=knap(i-1,j);
      else
	value=max(knap(i-1,j),p[i]+knap(i-1,j-w[i]));
      v[i][j]=value;
    }
  return(v[i][j]);
}
int main()
{
  int profit,count=0;
  /*printf("\nEnter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the profit and weights of the elements\n");
    for(i=1;i<=n;i++)
    {
    printf("For item no %d\n",i);
    scanf("%d%d",&p[i],&w[i]);
    }
    printf("\nEnter the capacity \n");
    scanf("%d",&cap);*/
  for(i=0;i<=n;i++)
    for(j=0;j<=cap;j++)
      if((i==0)||(j==0))
	v[i][j]=0;
      else
	v[i][j]=-1;
  profit=knap(n,cap);
  i=n;
  j=cap;
  while(j!=0&&i!=0)
    {
      if(v[i][j]!=v[i-1][j])
	{
	  x[i]=1;
	  j=j-w[i];
	  i--;
	}
      else
	i--;
    }
  printf("Items included are\n");
  printf("Sl.no\tweight\tprofit\n");
  for(i=1;i<=n;i++)
    if(x[i])
      printf("%d\t%d\t%d\n",++count,w[i],p[i]);
  printf("Total profit = %d\n",profit);
  return 0;
}
/* * * ** * * * ** * * 
   
Items included are
Sl.no	weight	profit
1	15	60
2	27	60
3	23	30
4	11	70
5	48	10
6	43	75
7	22	80
8	4	50
Total profit = 1306
* * * * ** * * * * * * */
