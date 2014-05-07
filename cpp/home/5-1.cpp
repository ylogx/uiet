#include<iostream>
#include"5-1.h"
using namespace std;
enum accountType{BASIC,EMPLOYEE};

void myprintline(char ch='-',int len=20);//(char ch='-', int len=20);

int main(){
    Account cstmr;
    int choice;
    do{
        cout<<'\n';
        myprintline();
        cout<<"\nEnter the operation code: "<<endl<<endl
            <<"\n1. to start a new Account"<<endl
            <<"\n2. to deposit in an Account"<<endl
            <<"\n3. to withdraw cash from an Account"<<endl
            <<"\n4. to display Account details"<<endl
            <<"\n5. to exit\n";
        myprintline('*');
        //fflush(stdin);
        //scanf("%d",&choice);
        cin>>choice;
        //cout<<endl<<choice<<endl<<(int)choice<<endl<<int(choice)<<endl;
        switch((int)(choice)){
            case 1: cstmr.initial(); break;
            case 2: cstmr.deposit(); break;
            case 3: cstmr.withdraw(); break;
            case 4: cstmr.display(); break;
            case 5: break;
            default: cout<<"\nWish you knew how to count!"; break;
        }
    }while(choice!=5);
    cout<<"\nThanks\n\n";
    return 0;
}

void myprintline(char ch,int len){
    for(int i=1; i<=len; i++)
        cout<<ch;
    cout<<'\n';
}
