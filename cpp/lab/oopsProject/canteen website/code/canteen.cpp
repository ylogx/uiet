/*
 * canteen.cpp
 *
 * Copyright 2013
 *      Shubham Chaudhary <UE113090>
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
 *  2013-03-07  Shubham Chaudhary  <UE113090>
 *      * New:  Added License, Header, ChangeLog,
 *              main function,
 *      * Modified: -
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

#include <stdio.h>
#include <stdlib.h>

//#include "declarations.h"
#include "definitions.cpp"

using namespace std;

//****Function Prototype*****



//******MAIN*****
/*
 * name: main
 * @param none
 * @return int: 0- successful, 1- exit by programmer, rand- other error
 *
 */
int main (int argc, char* argv[]){

    #ifdef LINUX
    system("clear");    //TODO portability
    #endif
    #ifdef WINDOWS
    clrscr();
    #endif


//!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    welcome();
    //menu();
    //testing class item
    item egg(5);
    cout<<"Cost of egg is: "<<egg.outputCost()<<endl;
    egg.updateCost(7.50);
    cout<<"Updated Cost of egg is: "<<egg.outputCost()<<endl;
    //testing class student
    student nalayak;
    nalayak.inputInfo();
    nalayak.outputInfo();


//!!!!!!!!!!!!!!!!!!!! End Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    #ifdef WINDOWS
    getch();
    #endif
    return (0);
}



/*

//=========================FORMATS============================
Follow these formats when make any change to the documents.

    * Tab size: 4 spaces
    * Mark a //TODO flag if something needs to be changed
    * Mark a //XXX flag if something may cause error in future

--------------------------------------------------------------
CHANGELOG ENTRY FORMAT:

Date    Name    <Roll#>

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
