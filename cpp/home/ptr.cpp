#include<iostream>
using namespace std;
int main(){
    int a[5]={1,2,3,4,5};
    int *p=a;
    cout<<p+1<<endl<<a[1];
    return 0;
}
