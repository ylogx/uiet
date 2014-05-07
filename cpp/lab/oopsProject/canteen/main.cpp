/*
 * main.cpp
 *
 * Copyright 2013
 *      Shubham Chaudhary <UE113090>
 *      Rishabh Gupta <UE113080>
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
 *  2013-03-29 : Rishabh Gupta <UE113080>
 *      > Modified : main()   // camel casing preferred.// function def first brace brought to new line.
 *  2013-04-14  Shubham Chaudhary  <UE113090>
 *      * New:  ->Changed the project hierarchy, file hierarchy
 *              ->folder class,data
 *              ->database files
 *      * Modified: -
 *
 */

#define LINUX
//#define WINDOWS
#ifdef LINUX
#include <iostream>
#endif
#ifdef WINDOWS
#include <iostream>
#include <conio.h>
#endif

////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>

#include "function.h"
////////////////////////////////////////////////////////////////////////////////

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

    if(argc!=1){
        cout<<"\nInvalid command line arguments ! ! !\n";
    }
    #ifdef LINUX
    if(system("clear")) { cout<<"\n\n\n\n"; }    //DONE portability
    if(system("date")) { cout<<"\n\n"; }
    #endif
    #ifdef WINDOWS
     clrscr();         //not working
     system("clear");
    #endif


//!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //welcome_message();          // after this user is asked for particular command.
    menu_display();     // menu displayed to user.
    //menu_input();       // this func takes input from user and operates as necessary.
    ///XXX do we really need 2 seperate functions for menu?

    //testing class Item
//    Item egg(5);
//    cout<<"Cost of egg is: "<<egg.outputCost()<<endl;
//    egg.updateCost(7.50);
//    cout<<"Updated Cost of egg is: "<<egg.outputCost()<<endl;
//    egg.store();
//    Item eggRet;
//    cout<<"asdf: "<<eggRet.outputCost()<<endl;
//    eggRet.retrieve();

    //testing store and retrieve
//    Student test1;
//    test1.inputInfo();
//    cout<<"\n***After Input***";
//    test1.outputInfo();
//    cout<<"\nStoring";
//    test1.store();
//    Student test2;
//    test2.retrieve();
//    Student test3;
//    cout<<"Test3: \n";
//    test3.outputInfo();

    //testing stud class
//    char choice;
//    while (1){
//        cout << "\n'a' -- add data for a new student"
//                "\n'd' -- display data for all stusents"
//                "\n'w' -- write all student data to disk"
//                "\n'r' -- read all student data from disk"
//                "\n'x' -- exit"
//                "\nEnter selection: ";
//        cin>>choice;
//        switch(choice){
//        //cout<<"in switch";
//        case 'a': //add a student to database
//            Stud::add(); break;
//        case 'd': //display all employees
//            Stud::display(); break;
//        case 'w': //write employees to file
//            Stud::writeToDisk(); break;
//        case 'r': //read all employees from file
//            Stud::readFromDisk(); break;
//        case 'x': exit(0); //exit program
//        default: cout << "\nUnknown command";
//        }//end switch
//    }//end while


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
    -> use   ///TODO for high priority tasks
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
