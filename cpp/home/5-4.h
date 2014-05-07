/*
 * Balagurusamy 5-4: represent a vector using class and perform few operation on them
 *          Shubham Chaudhary
 * for file 5-4.cpp
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
        void addVec(vector,vector);
        friend vector add(vector,vector);
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
void vector::addVec(vector v1,vector v2){
    for(int i=0;i<size;i++){
        data[i] = v1.data[i] + v2.data[i];
    }
}
vector add(vector v1,vector v2){
    vector v3;
    for(int i=0;i<size;i++){
        v3.data[i] = v1.data[i] + v2.data[i];
    }
    return v3;
}
