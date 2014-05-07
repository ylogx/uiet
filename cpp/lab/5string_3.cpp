/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Feb 11, 2013
  *     Roll:   UE113090
  *     Program:To concatenate strings using C++
  **/
#include <iostream>
#include <stdio.h>
using namespace std;
const int SIZE=20;
//***** Prototype *****
//*****Class Declaration*****
class s1{
    //private:
    public:
        char var[SIZE];
    public:
        void input(){ gets(var); }
        void display(){ cout<<"\nvar= "; puts(var); }
};
class s2{
    //private:
    public:
        char var[SIZE];
    public:
        void input(){ gets(var); }
        void display(){ cout<<"\nvar= "; puts(var); }
};
class s3{
    private:
        char var[SIZE<<1];  //size must be at least double the size of other arrays
    public:
        void input(){ gets(var); }
        void display(){ cout<<"\nvar= "; puts(var); }
        void concat( s1 , s2 );
};
void s3::concat(s1 in1, s2 in2){
    int i,j;
    for(i=0;(i<SIZE)&&(in1.var[i]!='\0');i++){
        var[i]=in1.var[i];
    }
    for(j=i;(j<(SIZE<<1))&&(in2.var[j-i]);j++){
        var[j]=in2.var[j-i];
    }
}
//****************
//******main******
int main(){
    //cout<<SIZE;
    s1 a;
    s2 b;
    s3 c;
    cout<<"Input a: ";
    a.input();
    cout<<"Input b: ";
    b.input();
    //cout<<"Input c: ";
    //c.input();
    c.concat(a,b);
    a.display();
    b.display();
    c.display();
    return 0;
}
/*
void gets(char* ptr){
    char temp;
    int i;
    for(i=0;((temp=getchar())!='\n') || (i!=SIZE);i++){
        ptr[i]=temp;
    }
    ptr[i]='\0';
}
void puts(char* ptr){
    for(int i=0;(ptr[i]!='\0')||(i!=SIZE);i++){
        cout<<ptr[i]<<'\t';
    }
}
*/
/***********************
***** OUTPUT ***********

Input a: shubham
Input b: chaudhary92

var= shubham

var= chaudhary92

var= shubhamchaudhary92


------------------
(program exited with code: 0)
Press return to continue


************************/
