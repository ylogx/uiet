/*
 * Balagurusamy 5-2: represent a vector using class and perform few operation on them
 *          Shubham Chaudhary
 */
#include<iostream>
#include"5-2.h"
using namespace std;

int main(){
    vector v1;
    int choice;
    do{
        cout<<"\n* * * * * * * *  M E N U  * * * * * * * * *"
            <<"\n1. To create new vector"
            <<"\n2. To modify value of a given element"
            <<"\n3. To multiply by a scalar value"
            <<"\n4. To display the vector in standard form"
            <<"\n5. To Exit"
            <<"\n* * * * * * * * * * * * * * * * * * * * * *"
            <<"\nYour Choice: ";
        cin>>choice;
        switch(choice){
            case 1: v1.create(); break;
            case 2:
                    int pos;
                    float newData;
                    cout<<"\nEnter position: ";
                    cin>>pos;
                    cout<<"\nEnter New Value: ";
                    cin>>newData;
                    v1.modify(pos,newData);
                    break;
            case 3:
                    cout<<"\nEnter scalar value: ";
                    float scalar;
                    cin>>scalar;
                    v1.multiply(scalar);
                    break;
            case 4: v1.display(); break;
            case 5: break;
            default: cout<<"\nWish you knew how to count ! ! !";
        }
    }while(choice!=5);
    cout<<"\nThanks\n"<<endl;
    return 0;
}
