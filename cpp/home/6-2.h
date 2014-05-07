/* Header file
 * Balagurusamy Prob. 6.2: make a string class
 *          Shubham Chaudhary
 */
#include<iostream>
using namespace std;
//class String{};     //forward declaration
class String{
    private:
        int size;
        char *data;
    public:
        String();           //empty string constructor
        String(char *);     //given string constructor
        String(String &);   //copy constructor
        void display();
};
inline String::String(){
    size=0;
    data=new char[size+1];
}
String::String(char *in){
    for(int i=0;in[i]!='\0';i++)    //to find size, so that mem can be allocated
        size=i;
    data=new char[size+1];
    for(int i=0;i<size+1;i++)           //copy input data
        data[i]=in[i];
}
String::String(String &ref){
    size=ref.size;
    data=ref.data;
}
void String::display(){
    for(int i=0;i<=size+1;i++)
        cout<<data[i];
}
