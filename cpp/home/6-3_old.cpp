/*
 *  Programmer: Shubham Chaudhary
 *  Problem: 6.3 of Balaguruswamy OOPS
 */
#include<iostream>
#include<string>    //for strcpy()
#include<list>
using namespace std;
struct blist{
    char *author, *title, *pub, *stack;
    float price;
};
list<blist> inven(3);

//class Books{
    //private:
        //char *author, *title, *pub, *stack;
        //float price;
    //public:
        //Books(){}       //constructor 1 defined
        //Books(char *);  //constructor 2 declared
        //Books(char*,char*); //constructor 3 declared
        //details();
//}
//Books::Books(char *input){
//}
//Books::Books(char *title, char *author){
//}
int main(){
    cout<<inven.size();
    inven(0)->author="shithole";
    cout<<inven(0).author;
    return(0);
}
