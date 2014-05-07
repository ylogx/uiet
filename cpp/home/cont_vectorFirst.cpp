#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> array;
    bool flag=1;
    //cout<<flag;
    while(flag){
        register int choice;
        cin>>choice;
        switch(choice){
            case 1:
                int in;
                cin>>in;
                array.push_back(in);
                break;
            case 2:
                for(register int i=0;i<array.size();i++){
                    cout<<i<<" is "<<array[i]<<"\t";
                }
                break;
            case 3:
                flag=false;
                break;
        }
    }
}
