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
counter = 0;

import sys;
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
                output += str(self.board[i][j])+' ';
            output += ']';
        return output;

    def isBlank(self,i,j,verbose=True):#pos):
        if i>self.m-1 or j>self.n-1 or i<0 or j<0:
            if verbose:
                print('Error: board limit');
            return False;
        if self.board[i][j] == 0:
            return True;
        return False;

    def isKnight(self,i,j):
        if i>self.m-1 or j>self.n-1:
#             print('Error Can\'t go above board limit');
            return False;
        if self.board[i][j] == 'K':
            return True;
        return False;


    def go(self,i,j,place,verbose=True):
#         if i>self.m-1 or j>self.n-1:
#             if verbose:
#                 print('Error Can\'t go above board limit');
#             return False;
        if self.isBlank(i,j,verbose):
            # print('Place %s at %d %d'%(place,i,j));
            self.board[i][j] = place;
            return True;
        else:
            if verbose:
                print('ERROR: Can\'t place %s at (%d,%d). Already occupied as: '%(place,i,j),self.board[i][j]);
            return False;

def attack(board,i,j):
    ''' i,j is the position where knight is'''
    #Left Up
#     if board.isBlank(i-2,j-1):
    if board.isKnight(i-2,j-1): return ATTACKINGKNIGHT;
    board.go(i-2,j-1,'A',False);
    #Left Down
    if board.isKnight(i-2,j+1): return ATTACKINGKNIGHT;
    board.go(i-2,j+1,'A',False);
    #Right Up
    if board.isKnight(i+2,j-1): return ATTACKINGKNIGHT;
    board.go(i+2,j-1,'A',False);
    #Right Down
    if board.isKnight(i+2,j+1): return ATTACKINGKNIGHT;
    board.go(i+2,j+1,'A',False);
    #Up Left
    if board.isKnight(i-1,j-2): return ATTACKINGKNIGHT;
    board.go(i-1,j-2,'A',False);
    #Up Right
    if board.isKnight(i+1,j-2): return ATTACKINGKNIGHT;
    board.go(i+1,j-2,'A',False);
    #Down Left
    if board.isKnight(i-1,j+2): return ATTACKINGKNIGHT;
    board.go(i-1,j+2,'A',False);
    #Down Right
    if board.isKnight(i+1,j+2): return ATTACKINGKNIGHT;
    board.go(i+1,j+2,'A',False);
#     print('After attacking %d,%d'%(i,j),board);
    #TODO: If attacking knight return original board
    return board;

def place_knight(board,i,j):
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

def n_knight_stub(board,st_i,st_j,k):
    ret = 0;
    if k==0:
        print('Done! No more knights need to be placed.');
        print(board);
        return 1;
    else:
        for i in range(st_i,board.m):
            for j in range(st_j,board.n):
                #print('Backed up:',unique(board));
                backup = Board(board.m,board.n,board);
                if board.isBlank(i,j):      #check(board[i][j]):
                    new_board = place_knight(board,i,j);
                    if new_board != ATTACKINGKNIGHT:
                        ret += n_knight(new_board,i,j,k-1);
                    #TODO Renew board as original
                    board = backup;
                    #print('Recovered:',unique(board));

#             j=0;
    return ret;

def n_knight(board,st_i,st_j,k):
    '''param(k): No of knights to be placed'''
#     print('Calling with:',st_i, st_j, k);
#     print(board, st_i, st_j, k);
    return n_knight_stub(board,st_i,st_j,k);

def unique(board):
    unique_board_value = 0;
    for i in range(board.m):
        for j in range(board.n):
            if board.board[i][j] == 'K':
                unique_board_value += 3*( i*3 + j + 1 );
#             elif board.board[i][j] == 'A':
#                 unique_board_value += 5*( 3*i + j + 1 );
    return unique_board_value;

def main(argv):
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
    counter = n_knight(board,0,0,k);
    print('%d possible configurations found'%counter);

if __name__ == '__main__':
    try:
        main(sys.argv[1:]);
    except KeyboardInterrupt:
        print('Gracefully Exiting because you asked me to do so');
