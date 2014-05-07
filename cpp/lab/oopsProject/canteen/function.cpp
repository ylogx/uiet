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
 *  2013-03-29  Shubham Chaudhary <UE113090>
 *      * New: created the file, added welcome, menu_display
 *  2013-03-29 : Rishabh Gupta <UE113080>
 *       > New: menu_input(),     // labels preferred over loops in case of wrong enteries.
 *       > Modified : menu_display(),menu_input()
 *  2013-03-29  Shubham Chaudhary <UE113090>
 *      * Modified: Function menu_input(): used loops instead of goto.
 *  2013-04-13  Shubham Chaudhary  <shubhamchaudhary92@gmail.com>
 *      * Modified: menu_display for Stud class
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

#include "function.h"
#include<iomanip>
#include<ctime>  // to display time on top-right corner.
//#include<cstdlib>     //Why and what's the difference b/w cstdlib and stdlib.h
//#include<stdio.h>     //WHY?

using namespace std;

//!!!!!!!!!!!!!!!!!!! Start Editing Here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//======================================================================
//====================== Function Definitions ==========================
//======================================================================

//---menu to be displayed to user--
void menu_display(){
    //TODO include functionality that user inputs values using keyboard arrow keys instead of entering numbers.
    //TODO make a menu displayed to shopkeeper    // add an option to directly add a daily expenditure of a Student.
    welcome_message();
    char choice;
    bool inLoop=true;
    while (inLoop)
    {
        cout << endl;
        //cout << "############################################################";
    #ifdef LINUX
        //if(system("clear")) { cout<<"\n\n\n\n"; }    //DONE portability
        if(system("date")) { cout<<"\n\n"; }
    #endif
    #ifdef WINDOWS
        clrscr();         //not working
        system("clear");
    #endif
        cout << "\n##############################################################";
        cout << "\n#        'a'   --  add data for a new student                #"
                "\n#        'd'   --  display data for all stusents             #"
                "\n#        'w'   --  write all student data to disk            #"
                "\n#        'r'   --  read all student data from disk           #"
                "\n#        's'   --  search database by Roll No.               #"
                "\n#        'x'   --  exit                                      #";
        cout << "\n##############################################################";
        cout << "\nEnter selection: ";
        cin>>choice;
        switch(choice){
        //cout<<"in switch";
        case 'a': //add a student to database
            Stud::add(); break;
        case 'd': //display all students
            Stud::display(); break;
        case 'w': //write students from memory to file
            Stud::writeToDisk(); break;
        case 'r': //read all students from file
            Stud::readFromDisk(); break;
        case 's': //search by roll
            Stud::searchByRoll(); break;
        case 'x': inLoop=false; break; //exit program
        default: cout << "\nUnknown command";
        }//end switch
        //getchar();
        //if(system("clear")) { cout<<"\n\n\n\n"; }    //TODO portability
    }//end while
    exit_message();
    //menu_input(choice);

}
void welcome_message()    //*TODO  use thread sleep like functions too (needed at various places.)  */
{
    //DONE google ascii art and add one here
    ///XXX NOTE don't mess with even a single character here ! ! !
    cout<<"\n\n"
           "                 _____________________________________________          \n"
           "        ________|    _     _          ___  __   __            |_______   \n"
           "        \\       |   / '   / \\   |\\  |  |  |__  |__  |\\  |     |      /   \n"
           "         \\      |   \\_.  | - |  |  \\|  |  |__  |__  |  \\|     |     /    \n"
           "         /      |_____________________________________________|     \\    \n"
           "        /__________)                                        (________\\   \n";
    cout<<"\n\n================ W e l C o m e ===================\n\n"; //TODO cout<<(static_cast<string>(time_t()));
    cout<<"Easily Maintain Your canteen record here.."<<endl;  //DONE find a way to show time on top right corner.
    //TODO make it more vivid and detailed

    //Done display current date and time on top-right corner at all times.
}
void exit_message(){
    cout<<"\n\n================ T h a n k   Y o u ===================\n"; //TODO cout<<(static_cast<string>(time_t()));
    //DONE find a way to show time on top right corner.
    cout<<"\n"
          " __^__                                                              __^__  \n"
          "( ___ )------------------------------------------------------------( ___ ) \n"
          " | / |                                                              | \\ |  \n"
          " | / |             \"Thanks a lot for choosing us . . .\"             | \\ |  \n"
          " | / |                                                              | \\ |  \n"
          "(_____)------------------------------------------------------------(_____) \n" ;
    //TODO make it more vivid and detailed
    //TODO google ascii art and add one here
    //Done display current date and time on top-right corner at all times.
}

void bug_message(){
    cout<<"\n\n OOPS Bug here \n\n";
    cout<<"     \\__/    \n"
          "     (@@)    \n"
          "    //||\\\\   \n\n";
    cout<<"We are really sorry for the inconvinience  caused !";
}

void disk_message(){
    cout<<"\n"
          "              _____________       \n"
          "              |           |        \n"
          "              |           |        \n"
          "              |    (O)    |        \n"
          "              |    !|!    |        \n"
          "              |____!_!____|        \n"
          "                                   \n"
          " Performing Disk Operation. Don't close. \n";
}

//---menu to be displayed to user--
void menu_display_windows(){
    ///XXX not working in linux
    //TODO include functionality that user inputs values using keyboard arrow keys instead of entering numbers.
    //TODO make a menu displayed to shopkeeper
    // add an option to directly add a daily expenditure of a student.
    // add more options.
    // location 1 to 3.
    string str[3] = {"  Add new customer." , "  View Customer details" , "  Change rates of a Quantity"};
    int choice=-1,location=1;   str[0].insert(0,"*");
    do{
        cout<<endl<<"press Esc to exit & enter key to Select";
        for(int i=0;i<3;i++)
            cout<<endl<<str[i];
        choice = getchar();
        if(choice == 13){ menu_input(location); }
        if( 1){
            choice = getchar();
            if(choice == 80 && location!=3) // down
             {
                str[location-1].erase(0,1);
                str[location].insert(0,"*");
                location++;
             }
             else if(choice == 72 && location != 1)  //up
             {
                str[location-1].erase(0,1);
                location--;
                str[location-1].insert(0,"*");
             }
        }
        //system("cls");
        welcome_message();
        if(choice==0x1B)
            exit(0);
    }while(choice != 0x1B);  // for escape key
}
//----------------------end of menu()------------------
void menu_input(int option){
    //system("cls");
    welcome_message();
    switch(option){
        case 1:{  // this brace is important. do not DELETE.
                      Student s;  // uses no-arg ctor to manually assign initial values to data-members.
                      char ch;
                      cout<<endl<<"Enter Billing information too? y/n:";
                      cin>>ch;
                      s.inputInfo(ch);  //TODO is bound checking for ch required here?

                     // s.outputInfo();//testing manipulators.
                    repeat : cout<<endl<<endl<<"Save information?  y/n :";
                      cin>>ch;
                      if(ch == 'y' || ch == 'Y')
                       {  s.saveToFile(s);
                           /* make a func which saves this object data in a text file at a dir.  */  break; }
                      else if( ch=='n' || ch == 'N') { cout<<endl<<"Information not saved!"<<endl; break;     }
                      else {goto repeat;}
                      break;
                      }
              case 2:{
                     again : cout<<endl<<"Search by roll no? press r"<<endl<<"Search by phoneNumber? press p"<<"   ";
                      char ch; cin>>ch;
                      Student s;
                      if(ch=='r' || ch =='R') {   s.searchByRoll();    }
                      /*TODO call a func to search database by rollno and return values by copying them into a student object  */
                      else if (ch =='p' || ch == 'P' ) {}
                      else { goto again; } break;
                       }
              case 3:  cout<<endl<<"Select Quantity to change price of:"<<endl;
                  //TODO call a func to display items and take specific input.

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
