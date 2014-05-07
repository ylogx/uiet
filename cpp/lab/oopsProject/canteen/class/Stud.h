/*
 * main.cpp -> declarations.h
 *
 * Copyright 2013 Shubham Chaudhary <shubhamchaudhary92@gmail.com>
 *                Rishabh Gupta <2012rish@gmail.com>
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
 *  2013-03-07  Shubham Chaudhary <UE113090>
 *      * New:  Added License, Header, ChangeLog, ifdef etc.
 *              class Stud
 *      * Modified: -
 *  2013-03-13  Shubham Chaudhary <UE113090>
 *      * New: -
 *      * Modified: class Student: added input output function
 *   2013-03-29 Rishabh Gupta <UE113080>
 *      > New : Student class : Bill data member.
 *      > Modified : Student class: ctors and data-members.,inputInfo()
 *  2013-04-13  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * New:  Moved class to new file,
 *              Added License, Header, ChangeLog, ifdef etc.
 *              static var-> n, arrayofpointer
 *              static fun-> add,display,readFromDisk,writeToDisk
 *              fun-> getData, putData, store, retrieve
 *              var-> isStored
 *      * Modified: Stud(),
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

#ifndef STUD_H
#define STUD_H

//#include "Student.cpp"


//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//****Class Definitions******
// performs file I/O on employee objects
// handles different sized objects
#include <fstream> //for file-stream functions
#include <iostream>
#include <typeinfo> //for typeid()
using namespace std;
#include <stdlib.h> //for exit()


#include "../function.h"   //for bug, disk_messages etc.
const int MAXNAME = 32; //maximum length of last names  //TODO extern
const int MAXSTUD = 100; //maximum number of employees

////////////////////////////////////////////////////////////////
class Stud //employee class
{
private:  // update variable names in member functions too.
    int rollNo;
    char name[MAXNAME];  //TODO use string class object instead.
    //char fName[20],lName[20];     //TODO make name class with default constructor only first name
    char dept[MAXNAME];
    //Dept dept;    //TODO
    char phoneNo[11]; //TODO 10 max chars entered with bound checking.
    int bill;  // stores total bill till now.
    bool isStored;  //true if student info is stored, false otherwise
protected:
    static int n; //current number of studs
    static Stud* arrap[]; //array of ptrs to Studs
public:
    static void add();          //add a new student
    static void display();      //display all student's info
    static void readFromDisk(); //read from disk file
    static void writeToDisk();  //write to disk file
    static void searchByRoll();
    Stud(){ isStored=false; bill=0; }    //empty constructor
    ~Stud();
    //TODO : rollNo(0),name[0](0),dept[0](0),phoneNo[0](0) // initialised values. first element of each assigned to 0 .
    //Stud(char )
    //Stud(char nameIn[],char deptIn[],int rollIn,int phoneIn); //TODO make another constructor to copy input
    //virtual void getData();
    void getData();
    void getData(char);    //DONE
    void putData();
    void updateInfo();      //TODO
    void saveToFile(Stud);
    void store();
    void retrieve();
};
////static variables
//int Stud::n; //current number of employees
//Stud* Stud::arrap[MAXEM]; //array of ptrs to emps
//--------------------------------------------------------------


//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif  //end of #ifndef declarations

/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
    -> use   ///TODO for high priority tasks
    * Mark a //XXX flag if something may cause error in future

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

