/*
 * canteen.cpp -> declarations.h
 *
 * Copyright 2013 Shubham Chaudhary <shubhamchaudhary92@gmail.com>
 *      Rishabh <>
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
 *      * New: class item, class student
 *      * Modified: -
 *  2013-03-13  Shubham Chaudhary <UE113090>
 *      * New: -
 *      * Modified: class student: added input output function
 *
 *
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

#ifndef DECLARATIONS
#define DECLARATIONS

#include "definitions.cpp"


//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//****Class Definitions******

//Information about a particular food item
class item{
    private:
        float cost;   //cost of food item
    public:
        item(float); //Constructor
        void updateCost(float);
        float outputCost(){ return cost; }
};

//Information about student
class student{
    private:
        int rollNo;
        char name[40];
        //char fName[20],lName[20];     //TODO make name class with default constructor only first name
        char dept[20];
        //Dept dept;    //TODO
        //long long phoneNo;    //XXX
        char phoneNo[15];
    public:
        student(){ }    //empty constructor
        //student(char nameIn[],char deptIn[],int rollIn,int phoneIn); //TODO make another constructor to copy input
        void inputInfo();    //DONE
        void outputInfo();
        void updateInfo();      //TODO
};

//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif  //end of #ifndef declarations

/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
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

