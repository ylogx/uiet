#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile("frdbuf.cpp");
    cout<<infile.rdbuf();
    cout<<endl;
    return 0;
}
