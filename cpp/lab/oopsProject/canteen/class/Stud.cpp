/*
 * main.cpp -> Stud.cpp
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
 *      * Modified: Stud::inputInfo(), Stud::inputInfo(char)
 *  2013-04-13  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * New:  Moved class to new file,
 *              Added License, Header, ChangeLog, ifdef etc.
 *              static var-> n, arrayofpointer
 *              static fun-> add,display,readFromDisk,writeToDisk
 *              fun-> getData, putData, store, retrieve
 *              var-> isStored
 *      * Modified: Stud(),
 *  2013-04-14  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * New:  searchByRoll(),
 *      * Modified:
 *  2013-04-19  Shubham Chaudhary  <UE113090>
 *      * New:
 *      * Modified: readFromDisk, writeToDisk, putData
 *              Removed all possible read-write errors
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

#include "Stud.h"

using namespace std;

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//static variables
int Stud::n; //current number of employees, init 0
Stud* Stud::arrap[MAXSTUD]; //array of ptrs to emps
//-------------- Class: Stud -------------------
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
Stud::~Stud(){
    for(int i=0;i<=n;i++){
        delete arrap[i];
    }
}

//add student to list in memory
void Stud::add()
{
    //cout<<"\t\t in add()";
    arrap[n]=new Stud;
    arrap[n++]->getData(); //get student data from user
}
//--------------------------------------------------------------//display all students
void Stud::display()
{
    for(int j=0; j<n; j++){
        cout << (j+1) << ":" ; //display number
        arrap[j]->putData(); //display Stud data
        cout << endl;
    }
}
//--------------------------------------------------------------//write all current memory objects to file
void Stud::writeToDisk()
{
    int size;
    cout << "Writing " << n << " Students to disk.\n";
    disk_message();
    ofstream ouf; //open ofstream in binary
    //ouf.open("data/Stud.DAT", ios::app | ios::binary);
    ouf.open("data/Stud.DAT", ios::trunc | ios::binary);
    if(!ouf){ cout << "\nCan't open file\n"; return; }
    for(int j=0; j<n; j++){ //for every Stud object
        size=sizeof(Stud);
        //write student object to file
        ouf.write( (char*)(arrap[j]), size );
        if(!ouf){ cout << "\nERROR: Can't write to file\n"; return; }
    }
}
//--------------------------------------------------------------//read data for all students from file into memory
void Stud::readFromDisk()
{
    int size; //size of employee object
    disk_message();
    ifstream inf; //open ifstream in binary
    //Stud temparrap[MAXSTUD];
    inf.open("data/Stud.DAT", ios::binary);
    if(!inf){ cout << "\nCan't open file\n"; return; }
    //inf.seekg(0);
    for(int i=0;i<n;i++){
        delete arrap[i];
    }
    n = 0; //no students in memory yet
    while(inf)
    {
        size=sizeof(Stud);  //!XXX
        arrap[n]=new Stud;
        inf.read( reinterpret_cast<char*>(arrap[n]), size );
        if(n==0 && !inf) //error but not eof
        { cout << "\nCan't read data from file\n"; bug_message(); return; }
        //arrap[n]->putData(); //display();
        n++;
    }//end while
    delete arrap[n--];  //empty no data in this record
    cout << "Read " << n << " students\n";
    //Stud::display();
}
void Stud::getData(){
    cout<<endl<<setw(22)<<"Enter Roll #: ";
    cin>>rollNo;
    cout<<setw(22)<<"Enter Name: ";
    //cin>>name;  //DONE gets(name);  //XXX
    getchar();
    cin.get(name,MAXNAME);
    cout<<setw(22)<<"Enter Phone #: ";
    cin>>phoneNo;   //long
    cout<<setw(22)<<"Enter Department: "; //TODO default deptif nothing entered
    getchar();
    cin.get(dept,MAXNAME);
    cout<<"Is there an existing bill ? <y/n>: ";
    char ch;
    cin>>ch;
    if(ch == 'y' || ch == 'Y'){
        cout<<setw(22)<<"Enter present bill : "; cin>>bill;
    }
}
void Stud::getData(char ch)
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
void Stud::putData()
{
    cout<<endl;
    cout<<setw(11)<<"Roll # : \t"<<rollNo<<"\n"
        <<setw(11)<<"Name : \t"<<name<<"\n"
        <<setw(11)<<"Department : \t"<<dept<<"\n"
        <<setw(11)<<"Phone # : \t"<<phoneNo<<"\n"
        <<setw(11)<<"Pending Bill : Rs.\t"<<bill<<endl;
}
void Stud::searchByRoll(){
    cout<<"\nEnter Roll #: ";
    int rollKey;
    cin>>rollKey;
    //get current count of student data
    int nCount=Stud::n;
    bool found=false;
    int i;
    for(i=0;(i<nCount) && (!found);i++){
        if(arrap[i]->rollNo == rollKey){
            found=true;
        }//end if
    }//end for
    if(found){
        //--i;
        cout<<'\n'<<" Found :)\n"<<i<<":";
        arrap[--i]->putData();  //compensating extra loop
        //arrap[i]->putData();  //compensating extra loop
    }
    else{
        cout<<"\nSorry student not found in database :(";
    }
}


void Stud::store(){ //old method
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
    fout.write(reinterpret_cast<char*>(this),sizeof(Stud));
    cout<<"\nstore(): Stored the information";
    fout.close();
}
void Stud::retrieve(){  //old method
    if(1){//(!isStored){
        ifstream fin("info.dat",ios::binary);
        fin.read(reinterpret_cast<char*>(this),sizeof(Stud));
        fin.close();
    }
    cout<<"\nRetreived Info:";
    this->putData();
}

void Stud::saveToFile(Stud s)
{
    start :
    ofstream fout;  // change extension to .dat
    fout.open("data.txt");
    if(!fout){
        char choice;
        choice=s.n;   //no use here, just to avoid my compiler warning
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
//--------------------- end of class Stud --------------------------


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
