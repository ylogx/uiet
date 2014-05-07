/*
 * Header file for 6-3.cpp - Balagurusamy
 */
#include<iostream>
//#include<string>
using namespace std;
//***prototype***
int strlen(char*);
void strcpy(char*,char*);

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
