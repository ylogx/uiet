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
//***Header***
int strlen(char*);
void strcpy(char*,char*);

//********************************
//**************Header************
//********************************

class books{
    private:
        char *author,*title,*pub,*pos;
        float price;
        int copies;
    public:
        books();  //constructor
        books(char *tit,char*aut,char*pb,char*po,float pr,int cop);
        books(books&);  //copy constructor
        ~books();   //destructor
        void addBook();
        void delBook();
        void search();
        void display();
};
books::books(){
    char empty[7]="empty";
    title=new char[10];
    strcpy(title,empty);
    author=new char[10];
    strcpy(author,empty);
    pub=new char[10];
    strcpy(pub,empty);
    pos=new char[10];
    strcpy(pos,empty);
    price=0;
    copies=0;
}

books::books(char *tit,char*aut,char*pb,char*po,float pr,int cop){

//    title=new char[strlen(tit)];
//    author=new char[strlen(aut)];
//    pub=new char[strlen(pb)];
//    pos=new char[strlen(po)];

    int length;
    length=strlen(tit);
    title=new char[length+1];   //+1 for '\0'
    strcpy(title,tit);
    length=strlen(aut);
    author=new char[length+1];
    strcpy(author,aut);
    length=strlen(pb);
    pub=new char[length+1];
    strcpy(pub,pb);
    length=strlen(po);
    pos=new char[length+1];
    strcpy(pos,po);
    price=pr;
    copies=cop;

}

int strlen(char*in){
    int i;
    for(i=0;in[i]!='\0';i++);
    return i;
}
void strcpy(char *src,char* des){
    int i;
    for(i=0;src[i]!='\0';i++)
        des[i]=src[i];
    des[i]='\0';
}
books::books(books &ref){
    ref.copies+=1;
}
books::~books(){
    delete author;
    delete title;
    delete pub;
    delete pos;
}
void books::display(){
   cout<<"\nTitle: "<<title;
   cout<<"\nAuthor: "<<author;
   cout<<"\nPublisher: "<<pub;
   cout<<"\nRack Posititon: "<<pos;
   cout<<"\nPrice: "<<price;
   cout<<"\nCopies: "<<copies;
}

//**************************
//***********MAIN***********
//**************************
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
void books::addBook(){
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
    //test.display();
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

