#include<iostream>
#include<time.h>
using namespace std;
int main(){
    time_t t;
    std::cout<<endl;
    time(&t);
    timer_t t2;
    tm t3;
    cout<<"string is: "<<asctime(&t3);
    return 0;
}
