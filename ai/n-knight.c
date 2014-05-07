#include <pthread.h>
#include<signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//# Problem: n knights problem

//Function Declaration/Prototype
void  INThandler(int sig);

//#Global Variable
int found_count = 0;
long iterations = 0,comparisons = 0;
clock_t start, end;
double cpu_time_used;
#define MAX 9
#define False 0
#define True 1

#define ATTACK '*'
#define BLANK '?'
#define KNIGHT 'K'

#define ATTACKINGKNIGHT 'a'

//COMP_ISBLANK = 6;
//COMP_ISKNIGHT = 5;
//COMP_B_COPY = 1; #?
//COMP_B_GO = 7;
//COMP_ATTACK = 8*COMP_ISKNIGHT + 8*COMP_B_GO;
//COMP_PLACE_KNIGHT = COMP_B_COPY + COMP_ISBLANK + COMP_B_GO + COMP_ATTACK;

int board_m,board_n;
char board_Attacking;
typedef struct Board{
//     int m,n;
    char b[MAX][MAX];
//     char **b;
    //int found_count;    //,iterations,comparisons;
} Board;

void print_board(Board board);
Board initboard(int m,int n){
    Board board;
    board_m = m;
    board_n = n;
    int i,j;
//     board.b= (char **)malloc(m*sizeof(char *));
    for (i=0;i<m;++i){
//         board.b[i]= (char *)malloc(n*sizeof(char));
        for (j=0;j<n;++j){
            board.b[i][j] = BLANK;
        }
    }
    board_Attacking = 0;
    return board;
}

void print_board(Board board){
    int i,j;
//     printf("\n");//"-----");
    for (i =0;i<board_m;++i){
//         putchar('\n'); putchar('['); putchar(' ');
//         fputs("\n[ ",stdout);
         fwrite("\n[ ",1,3,stdout);
        for (j =0;j<board_n;++j){
            putchar(board.b[i][j]);
//             fwrite(&(board.b[i][j]),1,1,stdout);
//             putchar(' ');
            fwrite(" ",1,1,stdout);
        }
//         putchar(']');
        fwrite("]",1,1,stdout);
        // Right Image
//         printf("\t[ ");
//         for (j=board.n-1;j>=0;--j){
//             if (board.b[i][j] == KNIGHT){
//                 printf("K ");
//             } else if (board.b[i][j] == ATTACK){
//                 printf("* ");
//             } else if (board.b[i][j] == BLANK){
//                 printf("? ");
//             }
//         }
//         printf("]");
    }
/*
    printf("\n");
    for (i=board.m-1;i>=0;--i){
        printf("\n[ ");
        or (j =0;j<board.n;++j){
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
//         printf("\t[ ");
//         for (j=board.n-1;j>=0;--j){
//             if (board.b[i][j] == KNIGHT){
//                 printf("K ");
//             } else if (board.b[i][j] == ATTACK){
//                 printf("* ");
//             } else if (board.b[i][j] == BLANK){
//                 printf("? ");
//             }
//         }
//         printf("]");
    }
*/
//     printf("\n");
    fwrite("\n",1,1,stdout);
//     printf("\n-----");
}

int isBlank(Board board,int i,int j){//,int verbose){
//        '''Returns True if board[i][j] is 0'''
    /*
    if (i>board_m-1 || j>board_n-1 || i<0 || j<0){
//         if (verbose)
        printf("ERROR: Board Limit");
        return False;
    }
    */
    if(board.b[i][j] == BLANK)
        return True;
    return False;
//     return board.b[i][j] == BLANK ? True : False;
}

int isKnight(Board board,int i,int j){
//        '''Returns True if there's a knight at i,j'''
    if (i>board_m-1 || j>board_n-1 || i<0 || j<0){
//         printf("Error: Can't go above board limit\n");
        return False;
    }
    if (board.b[i][j] == KNIGHT)
        return True;
    return False;
}


int go(Board *board,int i,int j,int place){
//        '''Places place there if i,j is blank and '''
//     if (i>board->m-1 || j>board->n-1 || i<0 || j<0){
    if (i>board_m-1 || j>board_n-1 || i<0 || j<0){
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
        board_Attacking = attack(&new_board,i,j);
        return new_board;
//        return attack(new_board,i,j);
    }else{
        printf("Error placing Knight at %d,%d",i,j);
    }
}
/*
// Threading
struct expand_arg{
    Board board;
    int st_i,st_j,k;
    int *ret;
};

int n_knight(Board board,int st_i,int st_j,int k);
void expand_tree(Board board,int i, int j,int k,int *ret){
//    comparisons += COMP_ISBLANK;
    }//end isBlank
}

#define NUM_THREADS 10
void thread_function(void *args){
    struct expand_arg *actualargs = args;
    return expand_tree(actualargs->board,actualargs->st_i,actualargs->st_j,actualargs->k,actualargs->ret);
    pthread_exit(0);
}
*/

/*'''param(k): No of knights to be placed'''*/
int n_knight(Board board,int st_i,int st_j,int k){
    int ret = 0;
    if (k==0){
        print_board(board);
        found_count += 1;   //Global
//         printf("Found: %d\n",found_count);
        return 1;
    }else{
        int i,j;
        for (i=st_i;i<board_m;++i){
            for (j=st_j;j<board_n;++j){
                ++iterations;
//                 struct expand_arg myarg; //myarg.board = board; //myarg.st_j = j;
//                 pthread_t helper; //pthread_create(&helper,NULL,thread_function,&myarg);
//                 expand_tree(board,i,j,k,&ret);
                 //    comparisons += COMP_ISBLANK;
                //Expand Tree
                Board backup = board;

                //Look Ahead
                int place_left = 0, ii, jj,bj=j;
//                 int place_left = (board_m-i)*board_n + (board_n-j) + board_m;
                for (ii=i;ii<board_m;++ii){
                    for(jj=bj;jj<board_n;++jj){
                        ++iterations;
                        if (isBlank(board,ii,jj)){
                            ++place_left;
                        }
                    }
                    bj = 0;
                }
                if (k > place_left){
//                     printf(".");//%d %dCan't place this much knights after in this board situation\n",k,can_not_place);
                    return ret;
                }
                if (isBlank(board,i,j)){
            //        comparisons += COMP_PLACE_KNIGHT;
                    Board new_board = place_knight(board,i,j);
            //        comparisons += 1;
                    //#Going in new_board
                    if (board_Attacking != ATTACKINGKNIGHT){
            //             *ret += n_knight(new_board,i,j,k-1);
                        board_Attacking = 0; //reset
                        n_knight(new_board,i,j,k-1);
                    }else{
                        printf("Found attackingknight at (%d,%d)",i,j);
                    }
                }//end isBlank

                board = backup; // #Renew board as original
                st_j=0;
            }//end for j
        }//end for i
    }//end else
    return ret;
}

void  INThandler(int sig) {
    float cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    if (cpu_time_used > 60){
        int cpu_time_used_min = cpu_time_used/60;
        float cpu_time_used_sec = cpu_time_used - cpu_time_used_min*60;
        printf("\nOuch! I ran for %d minutes and %2.2f seconds, a totol of %f seconds, did %ld iterations and you killed me :(\n",cpu_time_used_min,cpu_time_used_sec,cpu_time_used,iterations);
    }else{
        printf("\nOuch! I ran for %f seconds, did %ld iterations and you killed me :(\n",cpu_time_used,iterations);
    }
    exit(0);

    char  c;
    signal(sig, SIG_IGN);
    printf("OUCH, did you hit Ctrl-C?\n");
    printf("I've been running for %f seconds\n",((double) (clock() - start)) / CLOCKS_PER_SEC);
    printf("Do you really want to quit? [y/n] ");
    c = getchar();
    if (c == 'y' || c == 'Y')
         exit(0);
    else
         signal(SIGINT, INThandler);
    getchar(); // Get new line character
}

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
    if (k > m*n/2 + 1){
        printf("Can't place %d knights on a %d*%d board\n",k,m,n);
        return(0);
    }
    signal(SIGINT, INThandler);
    Board board = initboard(m,n);

//     int found_count = 0,iterations = 0,comparisons = 0;


    start = clock();
     /* Measure the time taken */
    n_knight(board,0,0,k);
//     found_count = n_knight(board,0,0,k);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (cpu_time_used > 60){
        int cpu_time_used_min = cpu_time_used/60;
        float cpu_time_used_sec = cpu_time_used - cpu_time_used_min*60;
        printf("\nTime: %d minutes and %2.2f seconds, a totol of %f seconds.\n",cpu_time_used_min,cpu_time_used_sec,cpu_time_used);
//     }else{
//         printf("\nTime: %f seconds.\n",cpu_time_used);
    }

    printf("%d possible configurations found with %ld iterations and %ld comparisons in %f seconds\n",found_count,iterations,comparisons,cpu_time_used);
//     if (cpu_time_used > 60){
//         int cpu_time_used_min = cpu_time_used/60;
//         float cpu_time_used_sec = cpu_time_used - cpu_time_used_min*60;
//         printf("%dminutes and %f seconds\n",cpu_time_used_min,cpu_time_used_sec);
//     }
//
    return(0);
}

