#include<iostream>
//#include<process.h>
using namespace std;
void main()
{
    char pw[11]={'i','l','o','v','e','c','o','d','i','n','g'};              //Saved Pass-Word
    char un[14]={'i','a','m','a','p','r','o','g','r','a','m','m','e','r'};          //Saved User-Name
    short uc=0,pc=0;                                                                //Imp Variables
    int unc[50]={0};                                                            //Char array for Camparison
    int pwc[50]={0};                                                            //Char array for Camparison
    cout<<"Enter Your Username : \n";
    int i=0;
    while(1)
    {
        unc[i]=(int)getch();

        if((unc[i])==8)                                                    //ASCII Value of "Backspace Key" is "8"
        {
            uc=0;
            if(i==0)
                continue;
            if(i!=0)
            {
                cout<<"\b \b";
                i--;
            }
            continue;
        }

        cout<<(char)unc[i];

        if((unc[i])==13)                                                   //ASCII Value of "Enter Key" is "13"
            break;

        if((char)unc[i]!=un[i])
            uc=1;
        i++;
    }

    i=0;
    cout<<"\n\n\n";
    cout<<"Enter Your Password : \n";

    while(1)
    {
        pwc[i]=(int)getch();

        if((pwc[i])==8)                                                    //ASCII Value of "Backspace Key" is "8"
        {
            uc=0;
            if(i==0)
                continue;
            pc=0;
            if(i!=0)
            {
                cout<<"\b\b ";
                i--;
            }
            continue;
        }
        if((pwc[i])==13)                                                   //ASCII Value of "Enter Key" is "13"
            break;

        if((char)pwc[i]!=pw[i])
            pc=1;

        cout<<"\b* ";
        i++;
    }
    if(uc==1 || i==0 || pc==1)
        cout<<"\n\n\n\nUsername and/or Password Incorrect!!!!!!!!";
    else
        cout<<"\n\n\n\nLogged in Successfully........";
}
