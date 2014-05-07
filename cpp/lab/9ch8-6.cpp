/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 8, 2013
  *     Roll:       UE113090
  *     Program:    Problem 8.6 Balagurusamy
  **/
#include <iostream>
#include <string.h>
using namespace std;

class Staff{
    private:
        int code;
        string name;
    protected:
        //
    public:
        Staff(int in1,string in2){  //constructor
            code = in1;
            name=in2;
        }
        Staff(){
            cout<<"Enter staff Code: ";
            cin>>code;
            cout<<"Enter Name: ";
            cin>>name;
        }
        void display(){
            cout<<"\n* * * Staff Info * * *";
            cout<<"\nCode: "<<code
                <<"\nName: "<<name;
        }
};

class Education {   //Problem 8-4
    private:
        string eduQual;
        string proQual;
    public:
        Education(){
            cout<<"Enter Educational Qualification: ";
            cin>>eduQual;
            //cin.get(eduQual);
            cout<<"Enter Professional Qualification: ";
            cin>>proQual;
        }
        void display(){
            cout<<"\nHighest Educational Qualification: "<<eduQual;
            cout<<"\nHighest Professional Qualification: "<<proQual;
        }
};
class Teacher: public Education{
    private:
        int noSubjects;
        int noPublications;
        Staff tcr;
    protected:
        //
    public:
        Teacher(){
            //Teacher::Staff();
            cout<<"Enter No of Subjects: ";
            cin>>noSubjects;
            cout<<"Enter No of publications published: ";
            cin>>noPublications;
        }
        void display(){
            tcr.display();
            Education::display();
            cout<<"\nNo of subject allocated: "<<noSubjects;
            cout<<"\nNo of Publications: "<<noPublications;
        }
};

class Officer: public Education {
    private:
        string grade;
        Staff ofr;
    public:
        Officer(){
            //Officer::Staff();
            cout<<"Enter Grade of officer: ";
            cin>>grade;
        }
        void display(){
            ofr.display();
            Education::display();
            cout<<"\nGrade: "<<grade;
        }
};

class Typist {
    private:
        Staff typ;
    protected:
        int speed;
    public:
        Typist(){
            //Typist::Staff();
            cout<<"Enter typing speed(wpm): ";
            cin>>speed;
        };
        void display(){
            typ.display();
            cout<<"\nTyping speed: "<<speed<<" wpm";
        }
};

class RegTypist: public Typist {
    private:
        int sal;
    public:
        RegTypist(){
            //RegTypist::Typist();
            cout<<"Enter Monthly Salary: ";
            cin>>sal;
        }
        void display(){
            Typist::display();
            cout<<"\nMonthly Salary: "<<sal;
        }
};


class CasualTypist: public Typist {
    private:
        int wage;
    public:
        CasualTypist(){
            //CasualTypist::Typist();
            cout<<"Enter daily wages: ";
            cin>>wage;
        }
        void display(){
            Typist::display();
            cout<<"\nDaily wages: "<<wage;
        }
};



int main(){
    //RegTypist rtObj;
    //rtObj.display();
    Teacher tObj;
    tObj.display();
    return 0;
}

/********OUTPUT**********
Enter Educational Qualification: btech
Enter Professional Qualification: 5years
Enter staff Code: 23
Enter Name: Shubham Chaudhary
Enter No of Subjects: 2
Enter No of publications published: 3
* * * Staff Info * * *
Code: 23
Name: Shubham
Highest Educational Qualification: btech
Highest Professional Qualification: 5years
No of subject allocated: 1
No of Publications: 3
***************************/
