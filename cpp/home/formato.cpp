#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    ofstream outfile("fdata.txt");
    outfile<<'x'
            <<77
            <<' '
            <<6.02
            <<"Shubham"
            <<' '
            <<"Vivek";
    cout<<"mother fucker written";
    return 0;
}
