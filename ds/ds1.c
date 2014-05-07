#include<stdio.h>
void arpr(int *);                          //function to print the array
void main()
{
#define LIMIT 10                           //no of elements
  int arr[LIMIT];
  int i,j,del_pos,mod_pos,no2bs;
  printf("Enter: ");
  for(i=0;i<10;i++)
    {
      scanf("%d",&arr[i]);
    }
  do
    {
      printf("---Enter---\n1 to insert\n2 to delete\n3 to modify\n4 to search\n5 to escape\n");
      scanf("%d",&j);
      switch (j)
	{
	case 1:
	  /*printf("Enter the new element to be inserted: ");
	    scanf("%d",&arr[*/
	  break;
	case 2:                        	 //deletion of element at specified position
	  printf("Enter position to be deleted: ");
	  scanf("%d",&del_pos);       		 //deletion position
	  for(i=del_pos-1;i<LIMIT;i++)
	    {
	      arr[i]=arr[i+1];
	    }
	  arpr(&arr[0]);
			break;
	case 3:                        		 	 //element modification at specific position
	  printf("Enter the position to be modified: ");
	  scanf("%d",&mod_pos);             	//modification position
	  printf("Enter new element: ");
	  scanf("%d",&arr[mod_pos-1]);		 	//-1 for a[0]
	  arpr(&arr[0]);
	  break;
		case 4:
		  printf("Enter no to be  searched : ");
		  scanf("%d",&no2bs);                  //get no to be searched
		  for(i=0;i<LIMIT;i++)
		    {
		      if(no2bs==arr[i])              	//print only if no matches no to be searched
			printf("Found @ : %d\n",i+1);
		    }
		  arpr(&arr[0]);
		  break;
	}
}while (j!=5);        				 //run the menu untill the escape condition is entered
}
//function to print the array
void arpr(int *a)
{
  int i;
	for(i=0;*(a+i)!='\0';i++)
	  {
	    printf("%d\t",*(a+i));
	  }
}
