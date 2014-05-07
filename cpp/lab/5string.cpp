/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Feb 11, 2013
  *     Roll:   UE113090
  *     Program:To perform certain operations on strings using C++
  **/
#include <iostream>
#include <stdio.h>
using namespace std;
const int SIZE=20;
//*****Prototype*****
void getS(char* );
void putS(char* );
//*****Class Declaration*****
class s1{
    private:
        char var[SIZE];
    public:
        void input(){ gets(var); }//getS(var); }
        void display(){ cout<<"\nvar= "; puts(var); } //putS(var); }
};
class s2{
    private:
        char var[SIZE];
    public:
        void input(){ gets(var); }//getS(var); }
        void display(){ cout<<"\nvar= "; puts(var); }// putS(var); }
};
class s3{
    private:
        char var[SIZE<<1];
    public:
        void input(){ gets(var); }//getS(var); }
        void display(){ cout<<"\nvar= "; puts(var); }// putS(var); }
};
//******main******
int main(){
    cout<<"Size: "<<SIZE<<endl;
    s1 a;
    s2 b;
    s3 c;
    a.input();
    b.input();
    c.input();
    a.display();
    b.display();
    c.display();
    return 0;
}
void getS(char* ptr){
    char temp;
    int i;
    for(i=0;((temp=getchar())!='\n') || (i!=SIZE);i++){
        ptr[i]=temp;
    }
    ptr[i]='\0';
}
void putS(char* ptr){
    for(int i=0;(ptr[i]!='\0')||(i!=SIZE);i++){
        cout<<ptr[i]<<'\t';
    }
}
/****************************************
Size: 20
Shubham Chaudhary
Ubuntu - Linux
Algorithm
var= Shubham Chaudhary
var= Ubuntu - Linux
var= Algorithm
*****************************************/
