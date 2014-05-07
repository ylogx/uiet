/*
 *      Programmer: Shubham Chaudhary
 *      Problem: 5.1 of Balaguruswamy OOP
 *
 */
#include<iostream>
//#include<string>
#include<iomanip>   //for mainpulator setw()
using namespace std;
enum accountType{BASIC,EMPLOYEE};
//*********Function Prototype*************
void printline();//(char , int );
void myprintline(int,char);//(char ch='-', int len=20);
//**************Class declaration*************
class Account{
    private:
        float balance;
        int type;
    public:
        char name[30];
        int accno;
        Account(void){}       //constructor does nothing
        Account(int);        //constructor
        void initial();       //name,acc#,balance,type
        void deposit();       //acc,amt deposited
        void withdraw();      //acc#,withdrawal amt
        void display();       //acc#
};
Account::Account(int input){
    balance=0;
    type=1;
    accno=input;
}

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
}
void Account::display(){
    int acc;
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
}
//***********Class declaration ends****************
int main(){
    Account cstmr;
    int choice;
    do{
        cout<<'\n';
        printline();
        cout<<"\nEnter the operation code: "
            <<"\n1. to start a new Account"
            <<"\n2. to deposit in an Account"
            <<"\n3. to withdraw cash from an Account"
            <<"\n4. to display Account details"
            <<"\n5. to exit\n";
        cin>>choice;
        switch(choice){
            case 1: cstmr.initial(); break;
            case 2: cstmr.deposit(); break;
            case 3: cstmr.withdraw(); break;
            case 4: cstmr.display(); break;
            case 5: break;
            default: cout<<"\nWish you knew how to count!"; break;
        }
    }while(choice!=5);
    cout<<"\nThanks\n\n";
}
void printline(){//(char ch='*', int len=15){
    for(int i=1;i<=30;i++)
        cout<<'*';//printf("%c",ch);
    //printf("\n");
    cout<<'\n';
}
void myprintline(int len,char ch='-'){
    for(int i=1; i<=len; i++)
        cout<<ch;
    cout<<'\n';
}
