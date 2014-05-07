/*
 * Balagurusamy Prob. 6.2: make a string class
 *          Shubham Chaudhary
 */
#include<iostream>
#include"6-2.h"
using namespace std;
int main(){
    cout<<"\nCreating s1\n";
    //String s1("Shubham");
    char *first="Shubham";
    String s1(first);
    s1.display();
    cout<<"\ncopying s1 into s2\n";
    String s2(s1);
    s2.display();
    cout<<"\nThanks !"<<endl;
    return 0;
}
