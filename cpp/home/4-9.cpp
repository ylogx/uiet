/*
 * Balagurusamy prob 4.9: Compute area of triangle and circle by  overloading area() function
 *  Shubham Chaudhary
 */
#include<iostream>
#include<math.h>
using namespace std;
const float PI=3.141;
//function prototypes
float area(float);  //circle
float area(float, float);   //triangle - h&b=height and base
float area(float, float, float);    //triangle - a,b,c area=s*s-a*s-b*s-c
int main(){
    cout<<area(12)<<endl<<area(2,3)<<endl<<area(3,4,5)<<endl<<endl;
    return 0;
}
float area(float r){
    return (PI*r*r);
}
float area(float h,float a){
    return(a*h/2);
}
float area(float a,float b,float c){
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

