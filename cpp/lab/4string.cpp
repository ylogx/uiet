/**
  *     Name:   Shubham Chaudhary
  *     Lab:    OOPS
  *     Date:   Feb 4, 2013
  *     Roll:   UE113090
  *     Program:To perform certain operations on strings using C++
  **/
#include<iostream>
#include<stdio.h>
using namespace std;
//*****Prototype*****
void strInput(char*);
void strInputGet(char*);
void display(char*);
int strLength(char* ptr);
char* strConcat(char*ptr1,char*ptr2);
void strCopy(char* src,char* des);
void strReverse(char* src,char* des);
void strUpper(char* src,char* des);
void strLower(char* src,char* des);
int strCompare(char* ptr1,char* ptr2);
//****************
//******main******
int main(){
    char arr[200];
    int choice;
        cout<<"\n0. Exit\n"
            <<"1. Input\n"
            <<"2. Output\n"
            <<"3. Concatenate\n"
            <<"4. Length\n"
            <<"5. String Copy\n"
            <<"6. To Upper Case\n"
            <<"7. To Lower Case\n"
            <<"8. String Reverse\n"
            <<"9. String Compare\n";
    do{
        cout<<"\nEnter Operation: ";
        cin>>choice;
        switch(choice){
            //int input,data,index;
            char str2[200];
            case 0: break;
            case 1:
                //cout<<"\nEnter Index";
                //cin>>index;
                //strInput(arr[index]);
                cout<<"\nEnter String: ";
                strInputGet(arr);
                break;
            case 2: display(arr); break;
            case 3:
                cout<<"\nInput second Array: ";
                strInputGet(str2);
                //char *out;
                //out=strConcat(arr,str2);
                //display(out);
                //cout<<"\nstr2 is: ";
                //display(str2);
                display(strConcat(arr,str2));
                break;
            case 4: cout<<"\nLength of String is: "<<strLength(arr); break;
            case 5:
                strCopy(arr,str2);
                display(str2);
                break;
            case 6:
                strUpper(arr,str2);
                cout<<"\nUpper Case String: ";
                display(str2);
                break;
            case 7:
                strLower(arr,str2);
                cout<<"\nLower Case String: ";
                display(str2);
                break;
            case 8:
                strReverse(arr,str2);
                display(str2);
                break;
            case 9:
                cout<<"\nInput second Array: ";
                strInputGet(str2);
                cout<<"String Compare returned: "<<strCompare(arr,str2);
                break;
        }
    }while(choice);
    return 0;
}
void strInput(char *ptr){
    char in='e';
    for(int i=0;in!='\n';i++){
        cout<<"\nInside for loop of strInput: Enter in: ";
        cin>>in;
        if(in=='\n'){
            ptr[i]='\0';
            return;
        }
        else{
            ptr[i]=in;
        }
    }
}
void strInputGet(char *ptr){
    char in;
    getchar();  //To remove trailing newline after 1 for opertation
    for(int i=0;in!='\n';i++){
        //cout<<"\nInside for loop of strInput: Enter in: ";
        in=getchar();
        if(in=='\n'){
            ptr[i]='\0';
            return;
        }
        else{
            ptr[i]=in;
        }
    }
}
void display(char* ptr){
    cout<<"\nArray is : ";
    for(int i=0;ptr[i]!='\0';i++){
        cout<<ptr[i];
    }
}
int strLength(char* ptr){
    //for(int length=0,i=0;ptr[i]!='\0';i++,length++);
    int length=0;
    for(int i=0;ptr[i]!='\0';i++,length++);
    return length;
}
char* strConcat(char*ptr1,char*ptr2){
    int  len,l1,l2;
    l1=strLength(ptr1);
    l2=strLength(ptr2);
    int i;
    len=l1+l2;
    char out[len];
    for(i=0;i<l1;i++){
        out[i]=ptr1[i];
    }
    /*for(int i=l1;i<len;i++){
        out[i]=ptr2[i];
    }}*/
    for(int j=0;j<l2;j++){
        out[i+j]=ptr2[j];
    
    out[len]='\0';
    //cout<<"\nOut is: ";
    //display(out);
    return out;
}
void strCopy(char* src,char* des){
    int len=strLength(src);
    for(int i=0;i<=len;i++){    //NOTE <= to copy NULL
        des[i]=src[i];
    }
}
void strReverse(char* src,char* des){
    int len=strLength(src);
    for(int i=len-1;i>=0;i--){
        des[len-1-i]=src[i];
    }
    des[len]='\0';
}
void strUpper(char* src,char* des){
    int len=strLength(src);
    for(int i=0;i<len;i++){
        if(src[i]>=97 && src[i]<=122){    //i.e lower
            des[i]=src[i]-32;
        }
        else{
            des[i]=src[i];
        }
    }
    des[len]='\0';
}
void strLower(char* src,char* des){
    int len=strLength(src);
    for(int i=0;i<len;i++){
        if(src[i]>=65 && src[i]<=90){    //i.e lower
            des[i]=src[i]+32;
        }
        else{
            des[i]=src[i];
        }
    }
    des[len]='\0';
}
int strCompare(char* ptr1,char* ptr2){
    int max,l1,l2;
    l1=strLength(ptr1);
    l2=strLength(ptr2);
    max = (l1>l2) ? l1 : l2 ;
    for(int i=0;i<max;i++){
        if(ptr1[i]!=ptr2[i]){
            return(ptr1[i]-ptr2[i]);
        }
    }
    return 0;
}


/* * * * * * O U T P U T * * * * * * *
0. Exit
1. Input
2. Output
3. Concatenate
4. Length
5. String Copy
6. To Upper Case
7. To Lower Case
8. String Reverse
9. String Compare

Enter Operation: 1

Enter String: asdfGHjklZZaAzZ

Enter Operation: 2

Array is : asdfGHjklZZaAzZ
Enter Operation: 3

Input second Array: qwertyui

Array is : asdfGHjklZZaAzZqwertyui
Enter Operation: 4

Length of String is: 15
Enter Operation: 5

Array is : asdfGHjklZZaAzZ
Enter Operation: 6

Upper Case String: 
Array is : ASDFGHJKLZZAAZZ
Enter Operation: 7

Lower Case String: 
Array is : asdfghjklzzaazz
Enter Operation: 8

Array is : ZzAaZZlkjHGfdsa
Enter Operation: 9

Input second Array: asdfh
String Compare returned: -33
Enter Operation: 0

* * * * * * * * * * * * * * * * * * */
