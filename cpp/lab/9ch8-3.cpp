/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 8, 2013
  *     Roll:       UE113090
  *     Program:    Problem 8.3 and 8.4 Balagurusamy
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
class Teacher: public Staff , public Education{
    private:
        int noSubjects;
        int noPublications;
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
            Staff::display();
            Education::display();
            cout<<"\nNo of subject allocated: "<<noSubjects;
            cout<<"\nNo of Publications: "<<noPublications;
        }
};

class Officer: public Education , public Staff {
    private:
        string grade;
    public:
        Officer(){
            //Officer::Staff();
            cout<<"Enter Grade of officer: ";
            cin>>grade;
        }
        void display(){
            Staff::display();
            Education::display();
            cout<<"\nGrade: "<<grade;
        }
};

class Typist: public Staff {
    private:
        //
    protected:
        int speed;
    public:
        Typist(){
            //Typist::Staff();
            cout<<"Enter typing speed(wpm): ";
            cin>>speed;
        };
        void display(){
            Staff::display();
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
        CasualTypist():Typist(){    //actual syntax
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

/*********OUTPUT**********
Enter staff Code: 1
Enter Name: Shubham
Enter Educational Qualification: Btech
Enter Professional Qualification: 3year
Enter No of Subjects: 12
Enter No of publications published: 30

* * * Staff Info * * *
Code: 1
Name: Shubham
Highest Educational Qualification: Btech
Highest Professional Qualification: 3year
No of subject allocated: 12
No of Publications: 30
****************************/
