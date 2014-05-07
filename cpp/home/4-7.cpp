/*
 * p 4-7: make power fun to cal m to power n; default n=2
 * Shubham Chaudhary
 */
#include<iostream>
using namespace std;
//function prototype
float power(float,int n=2);
int main(){
    cout<<"power(3,3)= "<<power(3,3)<<endl<<"power(3)= "<<power(3)<<endl;
    return 0;
}
float power(float m,int n){
    float out=1;
    while(n){
        out*=m;
        n-=1;
    }
    return out;
}
