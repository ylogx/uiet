#include <stdio.h>
#include <stdlib.h>
//# Problem: n knights problem

//#Global Variable
#define MAX 10
#define True 1
#define False 0

#define KNIGHT 1
#define ATTACK 2
#define BLANK 0

#define ATTACKINGKNIGHT -10101

//COMP_ISBLANK = 6;
//COMP_ISKNIGHT = 5;
//COMP_B_COPY = 1; #?
//COMP_B_GO = 7;
//COMP_ATTACK = 8*COMP_ISKNIGHT + 8*COMP_B_GO;
//COMP_PLACE_KNIGHT = COMP_B_COPY + COMP_ISBLANK + COMP_B_GO + COMP_ATTACK;

typedef struct Board{
    int m,n;
    int b[MAX][MAX];
    int found_count,iterations,comparisons;
    int Attacking;
} Board;

Board initboard(int m,int n){
    Board board;
    board.m = m;
    board.n = n;
    int i,j;
    for (i=0;i<m;++i){
        for (j=0;j<n;++j){
            board.b[i][j] = BLANK;
        }
    }
    board.Attacking = 0;
    return board;
}

void print_board(Board board){
    int i,j;
    printf("\n-----");
    for (i =0;i<board.m;++i){
        printf("\n[ ");
        for (j =0;j<board.n;++j){
            if (board.b[i][j] == KNIGHT){
                printf("K ");
            } else if (board.b[i][j] == ATTACK){
                printf("* ");
            } else if (board.b[i][j] == BLANK){
                printf("? ");
            }
        }
        printf("]");
        // Right Image
        printf("\t[ ");
        for (j=board.n-1;j>=0;--j){
            if (board.b[i][j] == KNIGHT){
                printf("K ");
            } else if (board.b[i][j] == ATTACK){
                printf("* ");
            } else if (board.b[i][j] == BLANK){
                printf("? ");
            }
        }
        printf("]");
    }
    printf("\n");
    for (i=board.m-1;i>=0;--i){
        printf("\n[ ");
        for (j =0;j<board.n;++j){
            if (board.b[i][j] == KNIGHT){
                printf("K ");
            } else if (board.b[i][j] == ATTACK){
                printf("* ");
            } else if (board.b[i][j] == BLANK){
                printf("? ");
            }
        }
        printf("]");
        // Right Image
        printf("\t[ ");
        for (j=board.n-1;j>=0;--j){
            if (board.b[i][j] == KNIGHT){
                printf("K ");
            } else if (board.b[i][j] == ATTACK){
                printf("* ");
            } else if (board.b[i][j] == BLANK){
                printf("? ");
            }
        }
        printf("]");
    }
    printf("\n");
//     printf("\n-----");
}

int isBlank(Board board,int i,int j){//,int verbose){
//        '''Returns True if board[i][j] is 0'''
    if (i>board.m-1 || j>board.n-1 || i<0 || j<0){
//         if (verbose)
        printf("ERROR: Board Limit");
        return False;
    }
    if(board.b[i][j] == BLANK)
        return True;
    return False;
}

int isKnight(Board board,int i,int j){
//        '''Returns True if there's a knight at i,j'''
    if (i>board.m-1 || j>board.n-1 || i<0 || j<0){
//         printf("Error: Can't go above board limit\n");
        return False;
    }
    if (board.b[i][j] == KNIGHT)
        return True;
    return False;
}


int go(Board *board,int i,int j,int place){
//        '''Places place there if i,j is blank and '''
    if (i>board->m-1 || j>board->n-1 || i<0 || j<0){
        //printf("Error: Can't go above board limit\n");
        return False;
    }
//     if (isBlank(*board,i,j)){
    if (board->b[i][j] == BLANK){    //Because we've already checked
        board->b[i][j] = place;
        return True;
    }else{
//         printf("ERROR: Can\'t place %d at (%d,%d). Already occupied as: %d",place,i,j,board->b[i][j]);
        return False;
    }
}

//def attack(board,i,j,verbosity=False):
int attack(Board *board,int i,int j){
//    ''' i,j is the position where knight is'''
//    #Left Up
//#     if board.isBlank(i-2,j-1):
//    if board.isKnight(i-2,j-1): return ATTACKINGKNIGHT;
//    board.go(i-2,j-1,'A',verbosity);
    if (isKnight(*board,i-2,j-1)) return ATTACKINGKNIGHT;
    go(board,i-2,j-1,ATTACK);
//    #Left Down
    if (isKnight(*board,i-2,j+1)) return ATTACKINGKNIGHT;
    go(board,i-2,j+1,ATTACK);
//    if board.isKnight(i-2,j+1): return ATTACKINGKNIGHT;
//    board.go(i-2,j+1,'A',verbosity);
//    #Right Up
    if (isKnight(*board,i+2,j-1)) return ATTACKINGKNIGHT;
    go(board,i+2,j-1,ATTACK);
//    if board.isKnight(i+2,j-1): return ATTACKINGKNIGHT;
//    board.go(i+2,j-1,'A',verbosity);
//    #Right Down
    if (isKnight(*board,i+2,j+1)) return ATTACKINGKNIGHT;
    go(board,i+2,j+1,ATTACK);
//    if board.isKnight(i+2,j+1): return ATTACKINGKNIGHT;
//    board.go(i+2,j+1,'A',verbosity);
//    #Up Left
    if (isKnight(*board,i-1,j-2)) return ATTACKINGKNIGHT;
    go(board,i-1,j-2,ATTACK);
//    if board.isKnight(i-1,j-2): return ATTACKINGKNIGHT;
//    board.go(i-1,j-2,'A',verbosity);
//    #Up Right
    if (isKnight(*board,i+1,j-2)) return ATTACKINGKNIGHT;
    go(board,i+1,j-2,ATTACK);
//    if board.isKnight(i+1,j-2): return ATTACKINGKNIGHT;
//    board.go(i+1,j-2,'A',verbosity);
//    #Down Left
    if (isKnight(*board,i-1,j+2)) return ATTACKINGKNIGHT;
    go(board,i-1,j+2,ATTACK);
//    if board.isKnight(i-1,j+2): return ATTACKINGKNIGHT;
//    board.go(i-1,j+2,'A',verbosity);
//    #Down Right
    if (isKnight(*board,i+1,j+2)) return ATTACKINGKNIGHT;
    go(board,i+1,j+2,ATTACK);
//    if board.isKnight(i+1,j+2): return ATTACKINGKNIGHT;
//    board.go(i+1,j+2,'A',verbosity);
//#     print('After attacking %d,%d'%(i,j),board);
//    #TODO: If attacking knight return original board
//    return board;
    return 0; //Attacking default
}
//
//def place_knight(board,i,j,verbosity=False):
Board place_knight(Board board,int i,int j){
//    new_board = Board(board.m,board.n,board);
    Board new_board = board;
//#     print('    new_board: ',new_board);
//    if new_board.isBlank(i,j):
    if (isBlank(new_board,i,j)){
//        new_board.go(i,j,'K');
        go(&new_board,i,j,KNIGHT);
//         printf("The after placing knight:"); print_board(new_board);
//        #new attacked position
//         int attackSituation = attack(&new_board,i,j);
//         new_board.Attacking = attackSituation;
        new_board.Attacking = attack(&new_board,i,j);
        return new_board;
//        return attack(new_board,i,j);
    }else{
        printf("Error placing Knight at %d,%d",i,j);
    }
}

/*'''param(k): No of knights to be placed'''*/
int n_knight(Board board,int st_i,int st_j,int k){
    int ret = 0;
    if (k==0){
//#         print('Done! No more knights need to be placed.');
//        print(unique(board),board);
        print_board(board);
        //TODO: Return in structure;
        return 1;
    }else{
        int i,j;
        for (i=st_i;i<board.m;++i){
            for (j=st_j;j<board.n;++j){
//                iterations += 1;
                Board backup = board;
//                comparisons += COMP_ISBLANK;
                if (isBlank(board,i,j)){
//                    comparisons += COMP_PLACE_KNIGHT;
                    Board new_board = place_knight(board,i,j);
//                     printf("After placing knight at %d,%d:",i,j); print_board(new_board);
//                    comparisons += 1;
                    if (new_board.Attacking != ATTACKINGKNIGHT){
//#                         print('Going in new_board',new_board);
                        ret += n_knight(new_board,i,j,k-1);
                        new_board.Attacking = 0; //reset
//                        found_count += ret_found_count;
//                        iterations += ret_iterations;
//                        comparisons += ret_comparisons;
                    }else{
                        printf("Found attackingknight at (%d,%d)",i,j);
                    }
                    //  #Renew board as original
                    board = backup;
                }//end isBlank
                st_j=0;
            }//end for j
        }//end for i
    }//end else
//    return (found_count, iterations,comparisons);
    return ret;
}

//def unique(board):
//    unique_board_value = 0;
//    for i in range(board.m):
//        for j in range(board.n):
//            if board.board[i][j] == 'K':
//                unique_board_value += 3*( i*board.m + j + 1 );
//#                 print(i,j,i*board.m + j + 1);
//#             elif board.board[i][j] == 'A':
//#                 unique_board_value += 5*( 3*i + j + 1 );
//    return unique_board_value;

int main(int argc,char *argv[]){
    int m,n,k;
    if (argc == 4){
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        k = atoi(argv[3]);
    }else if (argc == 3){
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        printf("Enter k: "); scanf("%d",&k);
    }else{
        printf("Enter m: "); scanf("%d",&m);
        printf("Enter n: "); scanf("%d",&n);
        printf("Enter k: "); scanf("%d",&k);
    }
    Board board = initboard(m,n);
    int found_count = 0,iterations = 0,comparisons = 0;

    found_count = n_knight(board,0,0,k);
    printf("%d possible configurations found with %d iterations and %d comparisons",found_count,iterations,comparisons);

    return(0);
}

