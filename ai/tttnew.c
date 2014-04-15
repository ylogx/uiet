/*
 *  Tic-Tac-Toe
 *  Shubham Chaudhary
 *  CSE AI: 6th Sem
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define PLAYER1 'x'
#define PLAYER2 'o'
#define BLANK   '-'

enum {LOSS = -1, TIE, WIN};
#define CONTINUE 5 // arbitrary

char **initboard(char *board[]) {
   int i,j;

   for (i=0; i<3; i++)
      for (j=0; j<3; j++)
         board[i][j]=BLANK;

   return board;
}

void displayboard(char *board[]) {
   int i,j;

   printf("\n");
   for (i=0; i<3; i++) {
      for (j=0; j<3; j++)
         printf(" %c ",board[i][j]);
      printf("\n");
   }
   printf("\n");
}

char checkwin(char *board[],char piece) {
   int i,j;

   for (i=0; i<3; i++)
      if ((board[i][0]==piece && board[i][1]==piece && board[i][2]==piece) || (board[0][i]==piece && board[1][i]==piece && board[2][i]==piece))
         return piece;        // piece wins

   if (board[1][1]==piece && ((board[0][0]==piece && board[2][2]==piece) || (board[0][2]==piece && board[2][0]==piece)))
      return piece;         // piece wins

   for (i=0; i<3; i++)
      for (j=0; j<3; j++)
         if (board[i][j]==BLANK)
            return BLANK;          //there are still blank squares, game is not yet done

   return ' '; /* Tie */
}

char **human_move(char **board,char piece) {
   int x,y,valid;
   int move;

   valid=0;
   do {
      printf("\nEnter your move (x y): ");
//       scanf("%i %i",&x,&y);
      scanf("%d",&move);
      x = (move -1) / 3 +1;
      y = (move -1) % 3 +1;
      if (x<4 && x>0 && y>0 && y<4)
         if (board[x-1][y-1]==BLANK)
            valid=1;

      if (!valid) {
         printf("\nINVALID MOVE. TRY AGAIN.\n");
         displayboard(board);
      }
   } while (!valid);

   board[x-1][y-1]=piece;

   return board;
}

int score(char **board, char piece1, char piece2) {
   char winner = checkwin(board, piece1);
   if (winner == piece1)
      return WIN;
   else if (winner == ' ')
      return TIE;
   else if (checkwin(board, piece2) == piece2)
      return LOSS;
   else
      return CONTINUE;
}

int minimax(char **board, char piece1, char piece2, int alpha, int beta, int turn) {
//     if (turn >= 0)
    {
       int util = score(board, piece1, piece2);
       if (util != CONTINUE) // leaf node
          return util;

       int i, j;
       for (i = 0; i < 3; i++)
          for (j = 0; j < 3; j++)
             if (board[i][j] == BLANK) {
                board[i][j] = piece1; // try out a square
                int score = - minimax(board, piece2, piece1, -beta, -alpha, -turn);
                if (score > beta) // a new maximum
                   beta = score;
                board[i][j] = BLANK; // return square to its original state
                if (beta >= alpha)
                   return beta;
                   /* stop expanding because the parent will choose the min of its
                      children and this is higher than the parent's current min */
             }
       return beta;
//     }else {
//        int util = score(board, piece1, piece2);
//        if (util != CONTINUE) // leaf node
//           return util;
//
//        int i, j;
//        for (i = 0; i < 3; i++)
//           for (j = 0; j < 3; j++)
//              if (board[i][j] == BLANK) {
//                 board[i][j] = piece2; // try out a square
//                 int score = minimax(board, piece1, piece2, alpha, beta,-turn);
//                 if (score < beta) // a new minimum
//                    beta = score;
//                 board[i][j] = BLANK; // return square to its original state
//                 if (beta <= alpha)
//                    return beta;
//              }
//        return beta;
    }
}

int computer_move(char **board, char piece1, char piece2) {
   int i, j;
   int bestValue = INT_MIN;
   int bestMoves[9][2], bestLen = 0; // randomizes equal-valued moves

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
         if (board[i][j] == BLANK) {
            board[i][j] = piece1; // try out a square
//             int score = min(board, piece1, piece2, INT_MIN, INT_MAX);
            int score = minimax(board, piece1, piece2, INT_MIN, INT_MAX, -1);
            if (score > bestValue) { // new maximum
               bestValue = score;
               bestLen = 1; // reset number of ties
               bestMoves[0][0] = i; // store move
               bestMoves[0][1] = j; // store move
            }
            else if (score == bestValue) { // move tie
               bestMoves[bestLen][0] = i; // store move
               bestMoves[bestLen][1] = j; // store move
               bestLen++;
            }
            board[i][j] = BLANK; // return square to its original state
         }
   // choose a random move from the best moves
   bestLen = rand() % bestLen;
   i = bestMoves[bestLen][0];
   j = bestMoves[bestLen][1];

   board[i][j] = piece1;

   return 1; //this means the computer made a move (computer always has to make a move, no need to change this line)
}

int main()
{
   srand((time(0)));

   int i,j;
   char again[2],winner,**board,agin='y';

   board=(char**)malloc(sizeof(char*)*3);
   for (i=0; i<3; i++)
      board[i]=(char*)malloc(sizeof(char)*3);

    do {
        board=initboard(board);
        char first = 'y';
        printf("Play first? ");
        scanf("%c",&first);
        displayboard(board);
        if (first == 'y'){
            do {
                board=human_move(board,PLAYER1);
                displayboard(board);
                winner=checkwin(board,PLAYER1);
                if (winner!=PLAYER1 && winner!=' ') {
                   if (computer_move(board,PLAYER2,PLAYER1))
                       winner=checkwin(board,PLAYER2);
                   else
                       printf("\nComputer passed\n");
                   displayboard(board);
                }
            } while (winner==BLANK);
        }else{
            do{
                if (computer_move(board,PLAYER2,PLAYER1))
                   winner=checkwin(board,PLAYER2);
               else
                   printf("\nComputer passed\n");
               displayboard(board);
               if (winner!=PLAYER2 && winner!=' ') {
                    board=human_move(board,PLAYER1);
                    winner=checkwin(board,PLAYER1);
                    displayboard(board);
               }
            }while (winner == BLANK);
        }

        if (winner!=' ')
            printf("THE WINNER IS %c!\n",winner);
        else
            printf("IT'S A TIE.\n");

        printf("\nPlay again (y)?: ");
        scanf("%s",again);
        getchar();
    } while(again[0]=='y');
//         getchar();
//         scanf("%c",&agin);
//     } while(agin=='y');

    //Free Allocated Space
    for (i=0; i<3; i++)
        free(board[i]);
    free(board);

   printf("\nThank you for playing.\n\n");
   return 0;
}
