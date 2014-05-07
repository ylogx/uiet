/*
 * Balagurusamy 6.3 - Manange a book inventory
 */
#include<iostream>
#include<stdlib.h>
#include"6-3.h"
using namespace std;
//***Global Constants***
const int RACK_SIZE=10;
static int count=0;
books rack[RACK_SIZE];
books test;
//***Prototype***
void add();
void search();
void display();
void asciiArt();
//***Main***
int main(){
    system("clear");
    asciiArt();
    int choice;
    do{
        cout<<"\n*** W E L C O M E ***"
            <<"\n   1. Add New Book"
            <<"\n   2. Search a book"
            <<"\n   3. Display"
            <<"\n   5. Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1: add(); break;
            case 2: //search();
                    break;
            case 3: display(); break;
            case 5: break;
            default: cout<<"\nWish you knew how to count"; break;
        }
    }while(choice!=5);
    return 0;
}
void add(){
    char tit[10], aut[10], pub[10], pos[10];
    float pri;
    int cop;
    cout<<"\nEnter title,author,publisher,position,price,copies: ";
    cin>>tit>>aut>>pub>>pos>>pri>>cop;
    //books test(tit,aut,pub,pos,pri,cop);
    //cout<<tit<<aut<<pub<<pos<<pri<<cop;
    //books rack[count](tit,aut,pub,pos,pri,cop);
}
void display(){
    test.display();
    for(int i=0;i<count;i++){
        cout<<"Book # "<<i+1<<':'<<endl;
        rack[i].display();
    }
}
void asciiArt(){
    cout<<"\nWelcome"<<"\n           __________                                 \n         .'----------`.                              \n         | .--------. |                             \n         | |########| |       __________              \n         | |########| |      /__________\\             \n.--------| `--------' |------|    --=-- |-------------.\n|        `----,-.-----'      |o ======  |             | \n|       ______|_|_______     |__________|             | \n|      /  %%%%%%%%%%%%  \\                             | \n|     /  %%%%%%%%%%%%%%  \\                            | \n|     ^^^^^^^^^^^^^^^^^^^^                            | \n+-----------------------------------------------------+\n";
    char n;
    cin>>n;
}
