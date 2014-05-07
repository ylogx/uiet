// overload_array.cpp
// overloading the c++ array subscript operator []
#include <iostream>
#include <stdlib.h>

using namespace std;

class myArray {
    private:
      int size;
      int a[10];
    public:
      int& operator[] (int x) {
          return a[x];
      }
      void print_array();   // I included this just to show the operator[] works!   
};

void myArray::print_array()
{
    for (int j=0; j < 10; j++)
        cout << "array[" << j << "] = " << a[j] << "\n";
}

int main(int argc, char *argv[])
{
    // create an instance of the myArray class    
    myArray instance;

    // load instance.a[] with integers
        // NOTE: here we use instance[i] NOT instance.a[i]   
        // instance.a[] wouldn't work as "int a[]" in the myArray class
        // is defined as PRIVATE!!!!!  
    for (int i=0; i < 10; i++)
        instance[i] = i; 

    // show that our operator worked by printing out the array values
    // using the myArray member function myArray::print_array()
    instance.print_array();

    cout << "\n\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
