#include<iostream>
//#include<string>
#include<iomanip>   //for mainpulator setw()
//#include<conio.h>   //for getch()
using namespace std;
//*********Function Prototype*************
void printline(char ch='*', int len=15);
//**************Class declaration*************
class Account{
    private:
        float balance;
        int type;
    public:
        char name[30];
        int accno;
        void initial();    //name,acc#,balance,type
        void deposit();    //acc,amt deposited
        void withdraw();   //acc#,withdrawal amt
        void display();  //acc#
};
void Account::initial(){
    printline();
    cout<<"Enter Account type: ";
    cin>>type;
    cout<<"Enter New Account holder's Name: ";
    //getline(name);
    cin>>name;
    cout<<"Enter the Account #: ";
    cin>>accno;
    cout<<"Enter initial balance: ";
    cin>>balance;
}
void Account::deposit(){
    float amtDep;
    cout<<"\nEnter amount to be deposited: ";
    cin>>amtDep;
    balance+=amtDep;
    printline();
    cout<<"\nSuccessfully deposited $ "<<amtDep;
    //cout<<"Continue ?";
    //getch();
}
void Account::withdraw(){
    int amtWid;
    cout<<"\nEnter amount you wish to withdraw: ";
    cin>>amtWid;
    if(amtWid<=balance){
        balance-=amtWid;
        printline();
        cout<<"\nSuccessfully withdrew $ "<<amtWid;
    }
    else
        cout<<"\nInsufficient Funds ! ! !";
    //cout<<"Continue ?";
    //getch();
}
void Account::display(){
    int acc;
/*
    cout<<"Enter Account No: ";
    cin>>acc;
    if(acc==accno){
        printline();
        cout<<"\nName of Account Holder: "<<name;
        cout<<"\nAvailable Balance in Account # "<<accno<<" is ";
        cout<<setw(10)<<balance<<endl;
        printline();
    }
    else
        cout<<"\nSorry Account # "<<acc<<" doesn't exist in database !";
*/
    if(1){
        printline();
        cout<<"\nName of Account Holder: "<<name;
        cout<<"\nAvailable Balance in Account # "<<accno<<" is ";
        cout<<setw(10)<<balance<<endl;
        printline();
    }
    else
        cout<<"\nSorry Account # "<<acc<<" doesn't exist in database !";
    //cout<<"Continue ?";
    //getch();
}
//***********Class declaration ends****************
void printline(char ch, int len){
    for(int i=1;i<=30;i++)
        cout<<ch;   //printf("%c",ch);
    //printf("\n");
    cout<<'\n';
}
