#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> array(10);
    bool flag=1;
    //cout<<flag;
    while(flag){
        int choice;
        cin>>choice;
        switch(choice){
            case 1: //insert
                int in;
                cin>>in;
                array(0).push_back(in);
                break;
            case 2: //display
                for(register int i=0;i<array.size();i++){
                    cout<<i<<" is "<<array(0)[i]<<"\t";
                }
                break;
            case 3: //exit
                flag=false;
                break;
            case 4: //delete
                break;
        }
    }
}
