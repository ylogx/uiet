#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fopen(),*fp;
int c;
char filename[40];
printf("Enter file to be opened: ");
gets(filename);
fp=fopen(filename,"r");
if (fp==NULL)
{
printf("Can't read %s\n",filename);
exit(1);
}
c=getc(fp);
while (c!=EOF)
{
putchar(c);
c=getc(fp);
}
fclose(fp);
}
