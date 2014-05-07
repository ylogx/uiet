#include <iostream>

using namespace std;

int main(){
    int x;
    auto y="bla";
    auto functor = [x](int y) { return y*x; };

    cout << functor(34);
    return 0;
}
