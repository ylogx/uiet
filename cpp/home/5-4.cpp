/*
 * Balagurusamy 5-4: represent a vector using class and perform few operation on them
 *          Shubham Chaudhary
 */
#include<iostream>
#include"5-4.h"
using namespace std;
const int noVec=5;
int main(){
    vector v[noVec];
    cout<<noVec<<" vectors created";
    int num;
    int choice;
    do{
        cout<<"\nEnter Vector No. "<<"(0-"<<noVec-1<<"): ";
        cin>>num;
        cout<<"\n* * * * * * * *  M E N U  * * * * * * * * *"
            <<"\n1. To create new vector"
            <<"\n2. To modify value of a given element"
            <<"\n3. To multiply by a scalar value"
            <<"\n4. To display the vector in standard form"
            <<"\n5. To add another vector using friend function"
            <<"\n6. To add another vector using class's function"
            <<"\n7. To Exit"
            <<"\n* * * * * * * * * * * * * * * * * * * * * *"
            <<"\nYour Choice: ";
        cin>>choice;
        switch(choice){
            case 1: v[num].create(); break;
            case 2:
                    int pos;
                    float newData;
                    cout<<"\nEnter position: ";
                    cin>>pos;
                    cout<<"\nEnter New Value: ";
                    cin>>newData;
                    v[num].modify(pos,newData);
                    break;
            case 3:
                    cout<<"\nEnter scalar value: ";
                    float scalar;
                    cin>>scalar;
                    v[num].multiply(scalar);
                    break;
            case 4: v[num].display(); break;
            case 5:
                    vector vRes;
                    int sec;
                    cout<<"\nEnter Second vector: ";
                    cin>>sec;
                    vRes=add(v[num],v[sec]);
                    cout<<"\nSum is: ";
                    vRes.display();
                    break;
            case 6:
                    vector vSum;
                    int second;
                    cout<<"\nEnter Second vector: ";
                    cin>>second;
                    vSum.addVec(v[num],v[second]);
                    cout<<"\nSum is: ";
                    vSum.display();
                    break;
            case 7: break;
            default: cout<<"\nWish you knew how to count ! ! !";
        }
    }while(choice!=7);
    cout<<"\nThanks\n"<<endl;
    return 0;
}
