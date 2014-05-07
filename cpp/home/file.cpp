#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout<<"Enter Name: ";
    char name[20];
    cin>>name;
    cout<<"Enter Age: ";
    int age;
    cin>>age;
    ofstream fout("file1.txt",ios::app);
    fout<<name<<'\n'<<age<<'\n';
    fout.close();
    ifstream fin("file1.txt");
    char fname[20];
    int fage;
    while (!fin.eof()){    //(fin.eof()) {
        //fin.get(fname);
        fin>>fname;
        cout<<fname<<'\t';
        fin>>fage;
        cout<<fage<<endl;
    }
    return 0;
}

