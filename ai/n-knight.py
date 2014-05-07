#!/usr/bin/python3 -tt
# Problem: n knights problem
#
# attack(board,i,j)
# boardplace_knight(board,i,j)
# check(board,i,j)
#

#Global Variable
# m = 0;
# n = 0;
ATTACKINGKNIGHT = -10001;
#Comparisons
COMP_ISBLANK = 6;
COMP_ISKNIGHT = 5;
COMP_B_COPY = 1; #?
COMP_B_GO = 7;
COMP_ATTACK = 8*COMP_ISKNIGHT + 8*COMP_B_GO;
COMP_PLACE_KNIGHT = COMP_B_COPY + COMP_ISBLANK + COMP_B_GO + COMP_ATTACK;

import sys,copy;
import threading;
class Board:
    count = 0;
    def __init__(self,m,n,orig=None):
        if orig:
            self.copy_constructor(m,n,orig);
#             print('Debug: Copied');
        else:
            self.initboard(m,n);
#             print('Debug: Initialized');

    def initboard(self,m,n):
        # board = [ [0 for x in range(m)] for x in range(n) ];
        self.m = m;
        self.n = n;
        self.board = [ [0]*m for x in range(n) ];
#         self.board = [ [0]*self.m for x in range(self.n) ];
        return self.board; # ???

    def copy_constructor(self,useless_m,useless_n,orig):
        '''Call as Board(to_copy.m,to_copy.n,to_copy) to get a new copy of to_copy'''
        # return copy.deepcopy(self);
        self.initboard(orig.m,orig.n);
        for i in range(orig.m):
            for j in range(orig.n):
                self.board[i][j] = orig.board[i][j];
        return self;

    def __str__(self):
        '''When converted to string'''
        output = '';
#         output += 'Board of size (%d,%d)'%(self.m,self.n);
        for i in range(self.m):
            output += '\n[ ';
            for j in range(self.n):
                val = str(self.board[i][j])
                if val == 'A':
                    val = '*';
                elif val == '0':
                    val = '?';
                output += val +' ';
            output += ']';
        return output;

    def isBlank(self,i,j,verbose=False):#pos):
        '''Returns True if board[i][j] is 0'''
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
            if verbose:
                print('Error: board limit');
            return False;
        if self.board[i][j] == 0:
            return True;
        return False;

    def isNotKnight(self,i,j,verbose=False):#pos):
        '''Returns True if board[i][j] != 'K', maybe 'A' or 0'''
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
            if verbose:
                print('Error: board limit');
            return False;
#         if self.board[i][j] == 0:
        if self.board[i][j] != 'K':
            return True;
        return False;

    def isKnight(self,i,j):
        '''Returns True if there's a knight at i,j'''
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
#             print('Error Can\'t go above board limit');
            return False;
        if self.board[i][j] == 'K':
            return True;
        return False;


    def go(self,i,j,place,verbose=True):
        '''Places place there if i,j is blank and '''
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
            if verbose:
                print('Error Can\'t go above board limit');
            return False;
#         verbose = True;
        if self.isBlank(i,j,verbose):
            # print('Place %s at %d %d'%(place,i,j));
            self.board[i][j] = place;
            return True;
        else:
            if verbose:
                print('ERROR: Can\'t place %s at (%d,%d). Already occupied as: '%(place,i,j),self.board[i][j]);
            return False;

    def get(self,i,j,verbose=True):
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
            if verbose:
                print('Error: Illegal board access for getting (%d,%d)'%(i,j));
            return None;
        return self.board[i][j];

    def set(self,i,j,value,verbose=True):
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
            if verbose:
                print('Error: Illegal board access for setting (%d,%d)'%(i,j));
            return None;
        self.board[i][j] = value;
        return value;   # return self.board[i][j];

def attack(board,i,j,verbosity=False):
    ''' i,j is the position where knight is'''
    #Left Up
#     if board.isBlank(i-2,j-1):
    if board.isKnight(i-2,j-1): return ATTACKINGKNIGHT;
    board.go(i-2,j-1,'A',verbosity);
    #Left Down
    if board.isKnight(i-2,j+1): return ATTACKINGKNIGHT;
    board.go(i-2,j+1,'A',verbosity);
    #Right Up
    if board.isKnight(i+2,j-1): return ATTACKINGKNIGHT;
    board.go(i+2,j-1,'A',verbosity);
    #Right Down
    if board.isKnight(i+2,j+1): return ATTACKINGKNIGHT;
    board.go(i+2,j+1,'A',verbosity);
    #Up Left
    if board.isKnight(i-1,j-2): return ATTACKINGKNIGHT;
    board.go(i-1,j-2,'A',verbosity);
    #Up Right
    if board.isKnight(i+1,j-2): return ATTACKINGKNIGHT;
    board.go(i+1,j-2,'A',verbosity);
    #Down Left
    if board.isKnight(i-1,j+2): return ATTACKINGKNIGHT;
    board.go(i-1,j+2,'A',verbosity);
    #Down Right
    if board.isKnight(i+1,j+2): return ATTACKINGKNIGHT;
    board.go(i+1,j+2,'A',verbosity);
#     print('After attacking %d,%d'%(i,j),board);
    #TODO: If attacking knight return original board
    return board;

def place_knight(board,i,j,verbosity=False):
    new_board = Board(board.m,board.n,board);
#     print('    new_board: ',new_board);
    if new_board.isBlank(i,j):
        new_board.go(i,j,'K');
        #new attacked position
        return attack(new_board,i,j);
#         attack(new_board,i,j);
#         return new_board;
    else:
        print('Error placing Knight at %d, %d'%(i,j));

# def n_knight_stub(board,st_i,st_j,k):
def n_knight(board,st_i,st_j,k):
    '''param(k): No of knights to be placed'''
#     found_count,iterations = 0,0;
    found_count,iterations,comparisons = 0,0,0;
    if k==0:
#         print('Done! No more knights need to be placed.');
        print(unique(board),board);
        return (1,iterations,comparisons+1);
    else:
#         max_value = (board.m-1)*3 + board.n-1 + 1
#         st_value = st_i*3+st_j+1;
#         for val in range(st_value,max_value):
#                 i = int((val-1)/3);
#                 j = (val-1)%3;
        for i in range(st_i,board.m):
            for j in range(st_j,board.n):
                iterations += 1;
                can_not_place = board.m*(board.n - j + 1) + board.m-i;
                if k > can_not_place :
                    return (0,iterations,comparisons+1);
                #print('Backed up:',unique(board));
                backup = Board(board.m,board.n,board);
#                 backup = copy.deepcopy(board);
                comparisons += COMP_ISBLANK;
                if board.isBlank(i,j):      #check(board[i][j]):
                    comparisons += COMP_PLACE_KNIGHT;
                    new_board = place_knight(board,i,j);
                    comparisons += 1;
                    if new_board != ATTACKINGKNIGHT:
#                         print('Going in new_board',new_board);
#                         found_count += n_knight(new_board,i,j,k-1);
#                         (ret_found_count,ret_iterations) = n_knight(new_board,i,j,k-1);
                        (ret_found_count,ret_iterations,ret_comparisons) = n_knight(new_board,i,j,k-1);
                        found_count += ret_found_count;
                        iterations += ret_iterations;
                        comparisons += ret_comparisons;
#                     else:
#                         print('Found attackingknight at (%d,%d):'%(i,j),board);
                    #Renew board as original
                    board = backup;
                    #print('Recovered:',unique(board));
#                 else:
#                     print('<%d,%d> '%(i,j),end='');
            st_j=0;
    return (found_count, iterations,comparisons);

# def n_knight(board,st_i,st_j,k):
#     '''param(k): No of knights to be placed'''
#     print('Calling with:',st_i, st_j, k);
#     print(board, st_i, st_j, k);
#     return n_knight_stub(board,st_i,st_j,k);

def unique(board):
    unique_board_value = 0;
    for i in range(board.m):
        for j in range(board.n):
            if board.board[i][j] == 'K':
                unique_board_value += 3*( i*board.m + j + 1 );
#                 print(i,j,i*board.m + j + 1);
#             elif board.board[i][j] == 'A':
#                 unique_board_value += 5*( 3*i + j + 1 );
    return unique_board_value;

def main(argv):
    argc = len(argv);
    if argc == 3:
        m = int(argv[0]);
        n = int(argv[1]);
        k = int(argv[2]);
    elif argc == 2:
        m = int(argv[0]);
        n = int(argv[1]);
        k = int(input('Enter number of knights to be placed k: '));
    else:
        m = int(input('Enter m: '));
        n = int(input('Enter n: '));
        k = int(input('Enter number of knights to be placed k: '));
    # n_knight(board,0,0,3);
    # board = initboard(m,n);
#     board = Board();
#     board.initboard(m,n);
    board = Board(m,n);
#     m=0; n=0; k=3;
#     n_knight(board,m,n,k);
    found_count,iterations,comparisons = n_knight(board,0,0,k);
    print('%d possible configurations found with %d iterations and %d comparisons'%(found_count,iterations,comparisons));

if __name__ == '__main__':
    try:
        main(sys.argv[1:]);
    except KeyboardInterrupt:
        print('Gracefully Exiting because you asked me to do so');
