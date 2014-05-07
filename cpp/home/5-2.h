/*
 * Balagurusamy 5-2: represent a vector using class and perform few operation on them
 *          Shubham Chaudhary
 * for file 5-2.cpp
 */
#include<iostream>

using namespace std;
const int size=3;
class vector{
    private:
        float data[size];
    public:
        void create();
        void modify(int pos, float newVal){ data[pos-1]=newVal; }  //inline function
        void multiply(float);
        void display();
};
inline void vector::create(){
    cout<<"\nEnter data of vector: ";
    for(int i=0; i<size; i++)
        cin>>data[i];
}
inline void vector::multiply(float scaler){
    for(int i=0;i<size;i++)
        data[i]*=scaler;
}
void vector::display(){
    cout<<"\nVector: "<<'(';
    for(int i=0;i<size;i++)
        cout<<data[i]<<", ";
    cout<<"\b\b)"<<endl;    //XXX \b to delete ',' and ' '
}

