//==========================================>> Project2
<<==================================================================
// This program gives the user a choice to display the game board with
//point values on each space, the tiles left after
// assigning random tiles to the 2 players and the tiles players have.
//
// History            Date            Resp. Eng.               Modification
//                  09/12/2011       Madhu Midha                2nd attempt
//==========================================================================================================================
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>


//Constants
const int row = 15;
const int column = 15;
const int color = 5;
const int leftLetters = 100;
const int numPlayers = 2;
const int numPlayerTiles = 7;

//Structures
struct tile
{
        char letter;
        int pointValue;
} ;

struct player
{
        char name[30];
        tile hand[numPlayerTiles];
        int numTiles;
        int pointTotal;
};

struct board
{
        char color[5];
        char premiumValue[15];

        bool status;
        tile placed;
};

//Prototypes
void loadBoard(board gameBoard[row][column]);
void assignTiles(tile boneyard[leftLetters], player user[numPlayers]);
void displayBoard (board gameBoard[row][column]);
void leftOver ( tile boneyard[leftLetters] );
void playerHand ( player user[numPlayers]);
void strcpy( char string1[], char string2[]);


//============================================>> Main
<<================================================================
//This function calls 2 functions initially to load the board and
assign tiles to the players, then gives the user
//to choose 1 of the 4 options and calls function according to the choice made.
//
// History             Date             Resp. Eng.               Modification
//                   09/12/2011        Madhu Midha                 initial
//Input:
//      Enters 1 of 4 choices
//Output:
//      Displays the board, boneyard, players hand according to the choice.
//=======================================================================================================================
int main()
{

        tile boneyard[leftLetters];
        player user[numPlayers];
        board gameBoard[row][column];

        int choice=0;

        //Call loadBoard
        loadBoard( gameBoard );

        //Call assignTiles
        assignTiles( boneyard, user);

        cout << "Welcome to Scrabble." << endl;

        //Loop until choice is not equal to 4
        while ( choice !=4)
        {

        //Display the main menu
        cout <<" Main Menu" << endl << endl;
        cout <<"1. Display the Game Board" << endl;
        cout <<"2. Display the boneyard" << endl;
        cout <<"3. Display the player Tiles." << endl;
        cout <<"4. Quit " << endl;
        cout <<"5. Enter your choice" << endl;

        //Enter the choice
        cin >> choice;

        if ( choice ==1)
        {
                displayBoard (gameBoard);
        }

        else if ( choice ==2)
        {
                leftOver(boneyard);
        }
        else if ( choice==3)
        {
                playerHand (user);
        }

        else if ( choice ==4)
        {
                cout << "Thanks for playing." << endl;
        }
        //If choice made is not from 1-4
        else
        {
                cout <<"Invalid Choice. Please choose again" << endl;
                cin >> choice;
        }
        }
        return 0;
}
//============================================>>Load
Board<<============================================
//This function reads in the color from an input file and stores it to
the structure, it also assigns
//string according to the scrabble rules.
//
//History           Date               Resp. Eng.            Modification
//                09/14/2011           Madhu Midha            2nd attempt
//Input:
//     This program reads in the colors form input file.
//Output:
//     Stores the colors and strings to the structures.
//======================================================================================================
void loadBoard( board gameBoard[row][column])
{
        //Input file stream variable
        ifstream fin;
        //bool endLoop = false;
        //Open the input file
        fin.open("scrabbleboard.txt");

        char red[] ="Triple Word";
        char navy[] = "Triple Letter";
        char pink[] = "Double Word";
        char blue[] = "Double Letter";



        //If file not found
        if (!fin)
        {
                cout <<"File doesnot exist" << endl;
        }

        else
        {
        for( int i=0; i< row; i++)
        {
                for ( int j =0; j< column; j++)
                {

                        fin >> gameBoard[i][j].color;

                //Copy strings to the other
                if(gameBoard[i][j].color[0] == 'r')
                {strcpy( gameBoard[i][j].premiumValue, red);

                }

                if (gameBoard[i][j].color[0] == 'p')
                { strcpy( gameBoard[i][j].premiumValue, pink);

                }

                if(gameBoard[i][j].color[0] == 'b')
                {
                        strcpy( gameBoard[i][j].premiumValue, blue);
                }

                if(gameBoard[i][j].color[0] == 'n')
                {
                        strcpy( gameBoard[i][j].premiumValue, navy);
                }

                if (gameBoard[i][j].color[0] == 'g')
                {
                        gameBoard[i][j].premiumValue[0] = '\0';
                }
                }


        }
                //Close the file
        }   fin.close();

}
//=============================================>> string copy
<<===========================================================
//This function copies one string to other
//
//History             Date               Resp. Eng.
Modification
//
//Input:
//      Recieves in the string 1 and string 2
//==========================================================================================================================
void strcpy ( char string1[], char string2[])
{
          //Define Variables
        int i=0;


          //Loop until there is a null character
       while ( string2[i] != '\0')
           {
                   string1[i] = string2[i];
                   i++;
           }

           return;
  }

//===================================================>>AssignTiles<<=================================================
//This function reads in the tiles and their point values from an
input file and assigns them to structures
//It then assigns random characters to 2 players
//
// History               Date                Resp. Eng.
    Modification
//                     09/14/2011           Madhu Midha
      2nd attempt
//Input:
//     Reads in the letters and point values form input file
//
//Output:
//     Assigns the letters and point values to structs and assigns
random tiles to players
//====================================================================================================================
void assignTiles(tile boneyard[leftLetters], player user[numPlayers])
{
        int noTileValue = 0;
        int randomPlayer = 0;

        int i = 0;
        ifstream fin;
        //Open the input file
        fin.open("letters.txt");
        //IF file not found
        if(!fin)
        {
                cout <<"File doesn't exits" << endl;
        }

        //Read in the letters and their point values
        for ( i=0; i<leftLetters; i++)
        {
                fin >> boneyard[i].letter >> boneyard[i].pointValue;
        }
        //Close the file
        fin.close();
        srand(randomPlayer); //Seed the random number generator


        //Assign random letters from 100 tiles to players
        for (i =0; i < numPlayers; i++)
        {

                for ( int j=0; j< numPlayerTiles; j++)
                {

                        randomPlayer = rand ()% 100;

                        user[i].hand[j].letter = boneyard[randomPlayer].letter;
                        user[i].hand[j].pointValue = boneyard[randomPlayer].pointValue;

            boneyard[randomPlayer].letter = '\0';
                        boneyard[randomPlayer].pointValue = 0;
                        if ( boneyard[randomPlayer].letter == '\0' &&
boneyard[randomPlayer].pointValue == 0)
                        {
                                boneyard[randomPlayer].letter ='X';

                                boneyard[randomPlayer].pointValue = 0;
                        }
                }
        }

}
//===================================================>>Display
Board<<============================================
//This program reads in displays the game board with thier values at each square
//
//History           Date             Resp. Eng.                 Modification
//                 09/12/2011       Madhu Midha                   initial
//Input:
//       Receives in the gameBoard with no. of rows and columns
//Output:
//       Displays the game board to the screen
//=================================================================================================================
void displayBoard ( board gameBoard[row][column])
{
        cout << gameBoard[0][0].premiumValue;

        //Display the Game Board and their premium value
        for ( int i=0; i < row; i++)
        {
                for ( int j=0; j< column; j++)
                { cout << setw(15)  << gameBoard[i][j].premiumValue << " ";



                } cout << endl;
        } cout << endl << endl;
}

//=============================================>>Left
Over<<=====================================================
//This program recieves the boneyard and user arrays and displays the
letter and their point values to the screen
//
//History            Date               Resp. Eng.                Modification
//                  09/13/2011         Madhu Midha                  initial
//Input:
//     Receives in the boneyard and user arras.
//Output
//     Displays the left tiles after they have been assigned to the
players and their point values
//===============================================================================================================

void leftOver( tile boneyard[leftLetters])
{
        int i;

        //Display until all left tiles are displayed
        for ( i=0; i< leftLetters; i++)
        {

                  cout << setw(4)  << boneyard[i].letter << boneyard[i].pointValue << "  ";

        if ( (i+1)%10 == 0)
          { cout << endl;}

        }
        cout << endl << endl;
}
//==========================================>>Player
Hand<<==========================================
//This program receives in the user array and asks the user the name
of the players and displays the
//tiles they got through random numbers
//
//History              Date                Resp. Eng.               Modification
//                    09/13/2011          Madhu Midha                 initial
//Input:
//     Keyboard: Enters the name of the 2 players
//Output:
//     Displays the letters and their point values that players got
out to the screen
//-===================================================================================================
void playerHand ( player user[numPlayers])
{

        //Ask and promp for the 1st player's name
        cout << "Enter the name of 1st player" << endl;
        cin >> user[0].name;

        //Ask and prompt for the 2nd player's name
        cout << "Enter the name of 2nd Player" << endl;
        cin >> user[1].name;

        cout << endl << endl;

        //Loop until all tiles from all players have been displayed
        for ( int i=0; i < numPlayers; i++)
        {
                cout << "Name : " << user[i].name << endl;
                for ( int j=0; j < numPlayerTiles; j++)
                {

                        cout << user[i].hand[j].letter << " " << user[i].hand[j].pointValue << endl;
                }
        }
        cout << endl << endl;
}
