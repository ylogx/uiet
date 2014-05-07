/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 8, 2013
  *     Roll:       UE113090
  *     Program:    Problem 8.5 Balagurusamy
  **/
#include <iostream>
#include <string.h>
using namespace std;

class Person {
    protected:
        string name;
        int code;
    public:
        virtual void create(){
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Code: ";
            cin>>code;
        }
        void display(){
            cout<<"\nName: "<<name
                <<"\nCode: "<<code;
        }
};

class Account : public Person {
    protected:
        int pay;
    public:
        void create(){
            Person::create();
            cout<<"Enter Pay: ";
            cin>>pay;
        }
        void display(){
            Person::display();
            cout<<"\nPay: "<<pay;
        }
};

class Admin : public Person {
    protected:
        int exp;
    public:
        void create(){
            Person::create();
            cout<<"Enter Experience: ";
            cin>>exp;
        }
        void display(){
            Person::display();
            cout<<"\nExperience: "<<exp;
        }
};

class Master : public Account, public Admin {
    protected:
        //
    public:
        void create(){
            Account::create();
            Admin::create();
        }
        void display(){
            Account::display();
            Admin::display();
        }
};
        
int main(){
    Master masObj;
    masObj.create();
    masObj.display();
    return 0;
}
