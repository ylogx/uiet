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
 *  2013-03-29 : Rishabh Gupta <UE113080>
 *       > New: menu_input(),     // labels preferred over loops in case of wrong enteries.
 *       > Modified : menu_display(),menu_input(),Student::outputInfo() : added manipulators.
 *  2013-03-29  Shubham Chaudhary <UE113090>
 *      * Modified: Function menu_input(): used loops instead of goto.
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


#include<iomanip>
#include<ctime>  // to display time on top-right corner.
//#include<cstdlib>     //Why and what's the difference b/w cstdlib and stdlib.h
//#include<stdio.h>     //WHY?

using namespace std;

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//======================================================================
//====================== Function Definitions ==========================
//======================================================================

void welcome()
{
    cout<<"\n\n================ W e l C o m e ===================\n\n"; //TODO cout<<(static_cast<string>(time_t()));
    cout<<"Easily Maintain Your canteen record here.."<<endl;
    //TODO make it more vivid and detailed
    //TODO google ascii art and add one here
    //TODO display current date and time on top-right corner at all times.
}
//---menu to be displayed to user--
void menu_display(){
    //TODO include functionality that user inputs values using keyboard arrow keys instead of entering numbers.
    //TODO make a menu displayed to shopkeeper    // add an option to directly add a daily expenditure of a Student.
    cout<<endl<<"1. Add new customer.\n"
            <<"2. View Customer details\n"
            <<"3. Change rates of a Quantity"<<endl;
    // add more options.

}
//----------------------end of menu()------------------
// user inputs values according to menu displayed.
void menu_input(){
    char option='0';
    int choice;
    bool validInput=false;
    //start:
    while(!validInput){
        cout<<'\n'<<"Choose what to do: "; ///TIP: don't use endl when not necessary, it slows the program
        //fflush(stdin);    ///TIP: You don't need that, c++ does that automatically
        //TODO  use try-catch block to prevent program crash from alphabet enteries. else //XXX
        cin>>option;
        if(option<'1' || option > '3'){   // bounds checking.
            cout<<"Invalid choice! Retry: \n";
            validInput=false;
            //goto start; // goto works good here as to jump directly instead of loop.
            ///TIP: google this -> Go To Statement Considered Harmful - Edsger W. Dijkstra
        }else{
            validInput=true;
        }
    }
    //now we've a valid option
    switch(option){ ///TODO XXX REMOVE goto statements and also use proper function notations
          case '1':{  // this brace is important. do not DELETE.
                  Student s;  // uses no-arg ctor to manually assign initial values to data-members.
                  char ch;
                  cout<<endl<<"Enter Billing information too? y/n:";    //TODO ask this in input function instead
                  cin>>ch;
                  //s.inputInfo(ch);  //TODO is bound checking for ch required here?
                  //TODO use inputInfo() here

                 // s.outputInfo();//testing manipulators.
         repeat : cout<<endl<<endl<<"Save information?  y/n :"; //XXX
                  cin>>ch;
                  if(ch == 'y' || ch == 'Y') { /*TODO make a func which saves this object data in a text file at a dir.  */  break; }
                  else if( ch=='n' || ch == 'N') { cout<<endl<<"Information not saved!"<<endl; break;     }
                  else {goto repeat;}   //XXX
                  break;
                  }
          case '2':
         again : cout<<endl<<"Search by roll no? press r"<<endl<<"Search by phoneNumber? press p"<<"   ";
                  char ch; cin>>ch;
                  if(ch=='r' || ch =='R') {  /*TODO call a func to search database by rollno and return values by copying them into a Student object  */}
                  else if (ch =='p' || ch == 'P' ) {}
                  else { goto again; } break;
          case '3':  cout<<endl<<"Select Quantity to change price of:"<<endl;
              //TODO call a func to display Items and take specific input.

    }
}
//----------------------------end of input()--------------



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
