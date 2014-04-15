/*
 *  ttt.c
 *  Tic-Tac-Toe - Artificial Intelligence
 *  06.03.2014 14:20:55
 *  Shubham Chaudhary <UE 113090>
 */

#include <stdio.h>
#include <stdlib.h>

#define PLAYER1 'x'
#define PLAYER2 'o'
#define BLANK   '-'

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
         return piece;      // piece wins

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

    valid=0;
    do {
      printf("\nEnter your move (x y): ");
      scanf("%i %i",&x,&y);
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

int val(char input){
    if(input == 'x')
        return 3;
    else if ( input == 'o' )
        return 5;
    return 2;
}

int possible_win_multi(char **board, char piece) {
    //2=BLANK 3=x 5=o;
    int i,j;
    int win_value = (piece == 'x') ? 18 : 50;
    //rows
    for(i=0;i<3;++i){
        if((val(board[i][0]) * val(board[i][1]) * val(board[i][2])) == win_value){
            //find ele;
            for(j=0;j<3;++j){
                if(board[i][j] == BLANK){
                    printf("returning: %d\n",(3*i +j + 1));
                    return (3*i +j + 1);
                }
            }
        }
    }
    //column
    for(i=0;i<3;++i){
        if((val(board[0][i]) * val(board[1][i]) * val(board[2][i])) == win_value){
            //find ele;
             for(j=0;j<3;++j){
                if(board[i][j] == BLANK){
                    printf("returning: %d\n",(3*i +j + 1));
                    return (3*i +j + 1);
                }
            }
        }
    }
    //diagonal
        if((val(board[0][0]) * val(board[1][1]) * val(board[2][2])) == win_value){
            //find ele;
             for(j=0;j<3;++j){
                if(board[j][j] == BLANK){
                    printf("returning: %d\n",(3*j +j + 1));
                    return (3*j +j + 1);
                }
            }
        }
        if((val(board[0][2]) * val(board[1][1]) * val(board[2][0])) == win_value){
            //find ele;
             for(j=0;j<3;++j){
                if(board[j][2-j] == BLANK){
                    printf("returning: %d\n",(3*j +(2-j) + 1));
                    return (3*j +(2-j) + 1);
                }
            }
        }
}

int possible_win_magic(char **board, char piece) {
    // Magic Square method
    int magic[3][3] = {
        { 8, 3, 4 },
        { 1, 5, 9 },
        { 6, 7, 2 }
    };
    int i,j,list[9]={0};
    printf("piece: %c\n",piece);

    for (i=0; i<3; i++) {
        for(j=0;j<3;j++){
             //list[i+j] = (board[i][j] == piece) ? magic[i][j] : 0 ;
             if (board[i][j] == piece)
                 list[i*3+j] = magic[i][j];
             else
                 list[i*3+j] = 0;
        }
    }

    printf("\nList: "); for (i=0; i<9; i++) { printf("#%d=%d\t",i,list[i]); } printf("\n");

    for (i=0; i<3; i++)
      if ((board[i][0]==piece && board[i][1]==piece && board[i][2]==piece) ||
              (board[0][i]==piece && board[1][i]==piece && board[2][i]==piece))
         return piece;      // piece wins

    if (board[1][1]==piece && ((board[0][0]==piece && board[2][2]==piece) ||
                (board[0][2]==piece && board[2][0]==piece)))
      return piece;         // piece wins

    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
         if (board[i][j]==BLANK)
            return BLANK;          //there are still blank squares, game is not yet done

    int value;

    // 0,1


    //for(i=0;i<9;++i){
    //   if (list[i] != 0) {
    //       int value = 15 - list[i] - list[i+1];
    //       if( value > 0 || value < 9 ) {
    //           for(i=0;i<3;i++)
    //               for(j=0;j<3;j++)
    //                   if(value == magic[i][j])
    //                       return (i*3+j+1);
    //           //return value;
    //       }
    //   }
    //}
    return 0; // can't win
}

int possible_win(char **board, char piece) {
    return possible_win_multi(board, piece);
    return possible_win_magic(board, piece);
}

void go(char **board, char piece, int n) {
    printf("--> going to: %d\n",n);
    --n;    //0based to 1 based
    board[n/3][n%3] = piece;
}

int get_turn(char **board,char piece1,char piece) {
    int count = 0,i,j;
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            if((board[i][j] != BLANK))
                count += 1;
    return count+1;
}

int make_center(char **board){
    if(board[1][1] == BLANK)
        return 5;
    else if(board[0][1] == BLANK)
        return 2;
    else if(board[1][0] == BLANK)
        return 4;
    else if(board[1][2] == BLANK)
        return 6;
    else if(board[2][1] == BLANK)
        return 8;
    printf("ERROR: Can't make_center\n");
    //return (make_blank(board));
}

int make_blank(char **board){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(board[i][j] == BLANK)
                return (i*3 + j + 1);
    printf("ERROR: Can't make_blank\n");
}

int computer_move_magic(char **board,char piece1,char piece2) {
    //magic squares
    int turn = get_turn(board,piece1,piece2);
    printf("Computer Move: %d\n",turn);
    int poss;
    switch(turn){
        case 1:
            go(board,piece1,1); break;
        case 2:
            if( board[1][1] == BLANK )
                go(board,piece1,5);
            else
                go(board,piece1,1);
            break;
        case 3:
            //go(board,piece1,(board[2][2] == BLANK) ? 9 : 3 );
            if( board[2][2] == BLANK )
                go(board,piece1,9);
            else
                go(board,piece1,3);
            break;
        case 4:
            printf("4: Possible returned: %d",possible_win(board,piece2));
            //checking opponent
            if(possible_win(board,piece2) != 0)
                go(board,piece1,possible_win(board,piece2)); //Win
            else
                go(board,piece1,make_center(board)); //Win
            printf("make_center: %d",make_center(board));
            break;
        case 5:
            if(possible_win(board,piece1) != 0)
                go(board,piece1,possible_win(board,piece1)); //Win
            else if(possible_win(board,piece2) != 0)
                go(board,piece1,possible_win(board,piece2)); //Block win
            else if( board[7/3][7%3] == BLANK )
                go(board,piece1,7);     //Fork
            else
                go(board,piece1,3);     //Fork
            break;
        case 6:
            printf("6: Possible piece2 returned: %d",possible_win(board,piece2));
            printf("6: Possible piece1 returned: %d",possible_win(board,piece1));
            if(possible_win(board,piece2) != 0)
                go(board,piece1,possible_win(board,piece2));
            else if(possible_win(board,piece1) != 0)
                go(board,piece1,possible_win(board,piece1));
            else
                go(board,piece1,make_center(board));
            break;
        case 7:
            if(possible_win(board,piece1) != 0)
                go(board,piece1,possible_win(board,piece1));
            else if(possible_win(board,piece2) != 0)
                go(board,piece1,possible_win(board,piece2));
            else
                go(board,piece1,make_blank(board));
            break;
        case 8:
            if(possible_win(board,piece2) != 0)
                go(board,piece1,possible_win(board,piece2));
            else if(possible_win(board,piece1) != 0)
                go(board,piece1,possible_win(board,piece1));
            else
                go(board,piece1,make_blank(board));
            break;
        case 9:
            if(possible_win(board,piece1) != 0)
                go(board,piece1,possible_win(board,piece1));
            else if(possible_win(board,piece2) != 0)
                go(board,piece1,possible_win(board,piece2));
            else
                go(board,piece1,make_blank(board));
            break;
    };

    return 1; //this means the computer made a move (computer always has to make a move, no need to change this line)
}

int computer_move(char **board,char piece1,char piece2) {
    return computer_move_magic(board, piece1, piece2);
}

int main() {
    int i,j;
    char again[2],winner,**board;

    board=(char**)malloc(sizeof(char*)*3);
    for (i=0; i<3; i++)
       board[i]=(char*)malloc(sizeof(char)*3);

    printf("\nWelcome to a game of Tic-Tac-Toe!\n");
    do {
        board=initboard(board);
        displayboard(board);
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

        if (winner!=' ')
            printf("THE WINNER IS %c!\n",winner);
        else
            printf("IT'S A TIE.\n");

        printf("\nPlay again (y)?: ");
        scanf("%s",again);
    } while(again[0]=='y');

    //Free Allocated Space
    for (i=0; i<3; i++)
        free(board[i]);
    free(board);

   printf("\nThank you for playing.\n\n");
   return 0;
}
