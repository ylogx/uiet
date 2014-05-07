/*
 * main.cpp -> definitions.cpp
 *
 * Copyright 2013 Shubham Chaudhary <UE113090>
 *                Rishabh Gupta <UE113080>
 *      Sachin Tehlan <UE113082>
 *      Upasana Sadana <>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

/*
 *  //__________________________________________
 *  //
 *  //============== Change Log ================
 *  //__________________________________________
 *
 *  2013-03-13  Shubham Chaudhary <UE113090>
 *      * New: -
 *      * Modified: Student::inputInfo(), Student::inputInfo(char)
 *
 */

#define LINUX
//#define WINDOWS
#ifdef LINUX
#include <iostream>
#endif
#ifdef WINDOWS
#include <iostream.h>
#include <conio.h>
#endif

#include <iomanip>
#include <fstream>

#include "Student.h"

using namespace std;

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//-------------- Class: Student -------------------

void Student::inputInfo(){
    cout<<endl<<setw(22)<<"Enter Roll #: \t";
    cin>>rollNo;
    cout<<setw(22)<<"Enter Name  :";
    cin>>name;  //TODO gets(name);  //XXX
    cout<<setw(22)<<"Enter Phone #   :";
    cin>>phoneNo;   //long
    cout<<setw(22)<<"Enter Department   :"; //TODO default deptif nothing entered
    cin>>dept;
    cout<<"Is there an existing bill: ";
    char ch;
    cin>>ch;
    if(ch == 'y' || ch == 'Y'){
        cout<<setw(22)<<"Enter present bill :"; cin>>bill;
    }
}
void Student::inputInfo(char ch)
{
    cout<<endl<<setw(22)<<"Enter Roll #  :";
    cin>>rollNo;
    cout<<setw(22)<<"Enter Name  :";
    cin>>name;  //TODO gets(name);  //XXX
    cout<<setw(22)<<"Enter Phone #   :";
    cin>>phoneNo;   //long
    cout<<setw(22)<<"Enter Department   :"; //TODO default deptif nothing entered
    cin>>dept;
    if(ch == 'y' || ch == 'Y')
    {
        cout<<setw(22)<<"Enter present bill :"; cin>>bill;
    }
}
void Student::outputInfo()
{
    cout<<endl;
    cout<<setw(11)<<"Roll #:"<<rollNo<<"\n"
        <<setw(11)<<"Name:"<<name<<"\n"
        <<setw(11)<<"Department:"<<dept<<"\n"
        <<setw(11)<<"Phone #:"<<phoneNo<<endl;
}
void Student::saveToFile(Student s)
{
    start :
    ofstream fout;  // change extension to .dat
    fout.open("data.txt");
    if(!fout){
        char choice;
        cout<<endl<<"data.txt file not found! Pls locate this file and retry..";
        cout<<endl<<"press c to retry or e to return & discard changes";
        cin>>choice;
        if(choice == 'c')
            goto start;
        else
            return;
    }
    fout.eof() ;
    fout<<rollNo<<'$';
    //fout<<write(name,40)<<write(dept,20)<<write(phoneNo,10)<<bill;
    fout<<name<<'$'<<dept<<'$'<<phoneNo<<'$'<<bill<<endl;
    fout.close();

    ifstream fin;
    fin.open("data.txt");

    char str[40]; char i[6];
    fin.getline(i,'$');
    fin.getline(str,'$');
    cout<<endl<<i<<"           "<<str;
}
void Student::searchByRoll()
{

}
void Student::store(){
    if(isStored){
        char again;
        cout<<"\nAlready stored ! BackUp Again ? <y/n>: ";
        cin>>again;
        if(again!='y'){
            cout<<"\nNot making backup again.";
            return;
        }//else go down
    }
    isStored=true;
    ofstream fout("info.dat",ios::binary);
    fout.write(reinterpret_cast<char*>(this),sizeof(Student));
    cout<<"\nstore(): Stored the information";
    fout.close();
}
void Student::retrieve(){
    if(1){//(!isStored){
        ifstream fin("info.dat",ios::binary);
        fin.read(reinterpret_cast<char*>(this),sizeof(Student));
        fin.close();
    }
    cout<<"\nRetreived Info:";
    this->outputInfo();
}

/*
void Student::inputInfo(char ch){
    cout<<endl<<"Enter Roll #: \t";
    cin>>rollNo;
    cout<<setw(22)<<"Enter Name  :";
    cin>>name;  //TODO gets(name);  //XXX
    cout<<setw(22)<<"Enter Phone #   :";
    cin>>phoneNo;   //long
    cout<<setw(22)<<"Enter Department   :"; //TODO default deptif nothing entered
    cin>>dept;
    if(ch == 'y' || ch == 'Y')
    {
        cout<<setw(22)<<"Enter present bill :"; cin>>bill;
    }
}
void Student::inputInfo(){
    cout<<endl<<"Enter Roll #: \t";
    cin>>rollNo;
    cout<<setw(22)<<"Enter Name  :";
    cin>>name;  //TODO gets(name);  //XXX
    cout<<setw(22)<<"Enter Phone #   :";
    cin>>phoneNo;   //long
    cout<<setw(22)<<"Enter Department   :"; //TODO default deptif nothing entered
    cin>>dept;
    cout<<"Is there an existing bill: ";
    char ch;
    cin>>ch;
    if(ch == 'y' || ch == 'Y'){
        cout<<setw(22)<<"Enter present bill :"; cin>>bill;
    }
}
void Student::outputInfo(){
    cout<<endl;
    cout<<"Roll #      :   "<<rollNo<<"\n"
        <<"Name        :   "<<name<<"\n"
        <<"Department  :   "<<dept<<"\n"
        <<"Phone #     :   "<<phoneNo<<endl;
}
//--------------------- end of class Student --------------------------
*/

//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
    -> use   ///TODO for high priority tasks
    * Mark a //XXX flag if something may cause problem somehow

--------------------------------------------------------------
CHANGELOG ENTRY FORMAT:

Date    Name    <email>

 * New:
 * Modified:
 * Removed:

--------------------------------------------------------------
*/

//------------------------------------------------------------
//FUNCTION DEFINITION FORMAT:
/*
 *
 * name:    name_of_function
 * @param   input parameters
 * @return  return type
 *
 */
//------------------------------------------------------------ 
