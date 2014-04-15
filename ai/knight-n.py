#!/usr/bin/python2 -tt
# Problem: n knights problem
#
# attack(board,i,j)
# boardplace(board,i,j)
# check(board,i,j)
#

def initboard(board,m,n):
    # board = list(n*list(m));
    board = [ [0 for x in range(m)] for x in range(n) ];
    print board;

def check(board,i,j):
    if board[i][j] == 0:
        return True;
    return False;

def go(board,i,j,place):
    if isBlank(board,i,j):
        board[i][j] = place;
    else:
        print 'ERROR: Can\'t place %1 at (%2,%3). Already occupied as: %4'.format(place,i,j,board[i][j]);

def attack(board,i,j):
    print 'attack';
    if isBlank(board,i,j):
        go(board,i,j,'A');



def place(board,i,j):
    new_board = list(board);
    if board[i][j] == 0:
        new_board[i][j] = 'K';
        #new attacked position
        attack(board,i,j);
    else:
        print 'Error placing at %1, %2'.format(i,j);

def xyz(board,st_i,st_j,k):
    if k==0:
        display(board);
        return;
    else:
        for i in range(st_i,m-1):
            for j in range(st_j,n-1):
                if check(board[i][j]):
                    new_board = place(board,i,j);
                xyz(new_board,i,j,k-1);
            j=0;

def main(argv):
    m = int(raw_input('Enter m: '));
    n = int(raw_input('Enter n: '));
    k = int(raw_input('Enter number of knights to be placed k: '));
    # xyz(board,0,0,3);
    initboard(board,m,n);
    m=0; n=0; k=3;
    xyz(board,m,n,k);

if __name__ == '__main__':
    main(sys.argv[1:]);
