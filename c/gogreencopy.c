#include<stdio.h>
main()
{
	char response;
	FILE *fp;	
	struct stu
	{
	int price,total;
	char detail[15];
	};
struct stu e
fp=fopen("roll.txt","a");
if (fp==NULL)
{
printf("Can't read disk database");
exit();
}
while (response=='Y')
{
printf("\nEnter price, details" );
scanf("%s %d",&e.detail,&e.price);
e.total=e.total+e.price;
fprintf(fp,"%s %d %d\n",e.detail,e.price,e.total);
printf ( "Add another record (Y/N) ") ;
fflush(stdin);
response=getche();
}
fclose(fp);
}






/*
	printf("Enter Roll No");
	scanf("%d",&roll);
	do 
	{
		fp=fopen("roll.txt","a");
		if (fs==NULL)
		{
			printf("Can't open database from  disk");
			exit();
		}

		/*Addition in account of: NAME*/
		/*get prev tot*/
/*		printf("Enter Price");
		scanf("%d",&price);
		printf("Enter Additional Details: ");
		gets(detail);
		tot=tot+rate;
		printf("New Total = %d",tot);
		/* Store the total */
/*		printf("Add more item in Roll no: %d\'s account",roll);
		
		
		
	}
		while(res==y);
}*/
/*function to show name*/
/*function to find out monthly sales*/
