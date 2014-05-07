/*
 * canteen.cpp -> definitions.cpp
 *
 * Copyright 2013 Shubham Chaudhary <UE113090>
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
 *      * New: item::updateCost, item::item, welcome(),
 *      * Modified: -
 *  2013-03-13  Shubham Chaudhary <UE113090>
 *      * New: -
 *      * Modified: student::inputInfo, student::inputInfo
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

#ifndef DEFINITIONS
#define DEFINITIONS
#include "declarations.h"

using namespace std;

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//======================================================================
//====================== Function Definitions ==========================
//======================================================================

void welcome(){
    cout<<"\n\n================ W e l C o m e ===================\n\n";
    //TODO make it more vivid and detailed
    //TODO google ascii art and add one here
}

void menu(){
    //TODO make a menu displayed to shopkeeper
}

//**********************************************************************
//*********************** Class releated *******************************
//**********************************************************************

//-------------- Class: item -------------------
item::item(float input){   //constructor
    cost=input;
}
void item::updateCost(float input){
    char choice;
    cout<<"Are you sure you want to change the cost of this item from "<<cost<<" to "<<input<<" ? <y/n>: ";
    cin>>choice;
    if(choice=='y'){
        cost=input;
    }
    else{
        cout<<"No changes made !\n";
    }
}
//--------------------- end of class item --------------------------

//-------------- Class: student -------------------
void student::inputInfo(){
    cout<<endl<<"Enter Roll #: \t";
    cin>>rollNo;
    cout<<"Enter Name: \t";
    cin>>name;  //TODO gets(name);  //XXX
    cout<<"Enter Phone #: \t";
    cin>>phoneNo;   //long
    cout<<"Enter Department: \t"; //TODO default deptif nothing entered
    cin>>dept;
}
void student::outputInfo(){
    cout<<endl;
    cout<<"Roll #      :   "<<rollNo<<"\n"
        <<"Name        :   "<<name<<"\n"
        <<"Department  :   "<<dept<<"\n"
        <<"Phone #     :   "<<phoneNo<<endl;
}
//--------------------- end of class student --------------------------


//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif  //of #ifndef definitions

/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
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
