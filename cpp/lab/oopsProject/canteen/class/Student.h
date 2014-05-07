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
 *      * New: class Item, class Student
 *      * Modified: -
 *  2013-03-13  Shubham Chaudhary <UE113090>
 *      * New: -
 *      * Modified: class Student: added input output function
 *   2013-03-29 Rishabh Gupta <UE113080>
 *      > New : Student class : Bill data member.
 *      > Modified : Student class: ctors and data-members.,inputInfo()
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

#ifndef STUDENT_H
#define STUDENT_H

//#include "Student.cpp"


//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//****Class Definitions******

//Information about student
class Student  // used to hold temp values between database transactions.
{          // declare functions as static
    private:  // update variable names in member functions too.
        int rollNo;
        char name[40];  //TODO use string class object instead.
        //char fName[20],lName[20];     //TODO make name class with default constructor only first name
        char dept[20];
        //Dept dept;    //TODO
        char phoneNo[11]; //TODO 10 max chars entered with bound checking.
        int bill;  // stores total bill till now.
        bool isStored;  //true if student info is stored, false otherwise
    public:
        Student(){ isStored=false; bill=0; }    //empty constructor
        //TODO : rollNo(0),name[0](0),dept[0](0),phoneNo[0](0) // initialised values. first element of each assigned to 0 .
        //student(char )
        //student(char nameIn[],char deptIn[],int rollIn,int phoneIn); //TODO make another constructor to copy input
        void inputInfo();
        void inputInfo(char);    //DONE
        void outputInfo();
        void updateInfo();      //TODO
        void saveToFile(Student);
        void searchByRoll();
        void store();
        void retrieve();
};

/*
//Information about Student
class Student  // used to hold temp values between database transactions.
{
    private:
        int rollNo;
        char name[40];  //TODO use string class object instead.
        //char fName[20],lName[20];     //TODO make name class with default constructor only first name
        char dept[20];
        //Dept dept;    //TODO
        //long long phoneNo;    //XXX
        char phoneNo[10]; //TODO 10 max chars entered with bound checking.
        int bill;  // stores total bill till now.
    public:
        Student()//TODO : rollNo(0),name[0](0),dept[0](0),phoneNo[0](0) // initialised values. first element of each assigned to 0 .
        { }    //empty constructor
        //Student(char )
        //Student(char nameIn[],char deptIn[],int rollIn,int phoneIn); //TODO make another constructor to copy input
        void inputInfo(char);    //DONE
        void inputInfo();       //I don't think we really need to call it with a character, it's clumsy that way
        void outputInfo();
        void updateInfo();      //TODO
};
*/
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
 
