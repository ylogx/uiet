#include<iostream>
using namespace std;
int main(){
  const float factor=2.54;
  float x,in,cm;
  char ch=0;
  cout<<"Enter Length(2.54 i OR 2.12 c for inch and cm respv.): ";
  cin>>x;
  cin>>ch;
  switch(ch){
  case 'i':
    in=x;
    cm=x*factor;
    break;
  case 'c':
    cm=x;
    in=x/factor;
    break;
  default:
    cout<<"\nWish youy knew how to count ! ! !";
    in=cm=0;
    break;
  }
  cout<<"\nInch: "<<in<<"\tCm: "<<cm;
  return 0;
}
