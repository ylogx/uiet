#include<stdio.h>
#include<iostream.h>
//using namespace std;

char a[20];
int i;
void swch();
void insert();
void display();

int main()
{
	for(i=0;i<20;i++)
	{
		a[i] = '@';
	}
	swch();
	return 0;
}

void swch()
{
	char c;

	cout<<"enter 1 to insert\nenter 2 to delete\nenter 3 to modify\nenter 4 to search\nneter 5 to sort\nenter 6 to display";
	cin>>c;
	 switch(c)
	 {
	case '1':
	{
		insert();
		swch();
		break;
	}

	case '2':
	{
		swch();
		break;
	}
	case '3':
	{
		swch();
		break;
	}
	case '4':
	{
		swch();
		break;
	}
	case '5':
	{
		swch();
		break;
	}
	case '6':
	{
		display();
		swch();
		break;
	}
	default:
	{
		cout<<"wrong character enetered....try again";
		swch();
		break;
	}
  }
}

void insert()
{
		char c;

		cout<<"\nenter 1 to insert at specific position\nenter 2 to eneter at end:  ";
		cin>>c;

		switch(c)
		{
			case'1':
			{
				int pos;
				cout<<"\nenter the position where you want to insert: ";
				cin>>pos;
				if(pos > 20)
				{
					cout<<"position is out of the limit of array......array size is 20";
				}
				else
				{
				  /*
					cout<<"enter the no you want to insert: ";
					cin>>c;


					i=20;
					while( i != pos||i > 0)
					{
						a[i+1] = a[i];
						i--;
					}*/
					display();


				}

				insert();
				break;
			}

			case'2':
			{
				insert();
				break;
			}

			default:
			{

				insert();
				break;
			}
		}

		/*cout<<"\nenter no you want to insert: ";

		cout<<"\nenter position where you want to insert: ";
		int i=0;
		while(i != 20 || a[i])
		{
			i++;
		}
		i++;
		cin>>a[i]; 8?     */
}

void display()
{
	for(i=0;i<20;i++)
	{
		cout<<a[i];
	}
   cout<<"\n";
}