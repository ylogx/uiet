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
 *  2013-04-13  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * New: included files Item.h, Stud.h, Student.h
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

#ifndef FUNCTION
#define FUNCTION

//#include "Item.h"
//#include "Student.h"
//#include "Stud.h"
//#include "Item.cpp"
//#include "Student.cpp"
//#include "Stud.cpp"

#include "class/Item.h"
#include "class/Student.h"
#include "class/Stud.h"
//#include "class/Item.cpp"
//#include "class/Student.cpp"
//#include "class/Stud.cpp"

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void menu_display();
void welcome_message();
void exit_message();
void bug_message();
void disk_message();

void menu_input(int);
void menu_display_windows();
//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//#include "function.cpp"
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

