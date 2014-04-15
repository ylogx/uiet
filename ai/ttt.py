#!/usr/bin/python
import sys;

def initboard():
    board = [];
    board = range(1,10); #multi
#     for i in range(3):
#         for j in range(3):
#     board = [ 8, 3, 4, 1, 5, 9, 6, 7, 2 ];
    return board;

def isblank(board, pos):
    # pos is 1:9
    return isinstance(board[pos-1],int);

def displayboard(board,verbose=False):
    for i in range(1,10):
        if verbose == False and isblank(board,i):
            print ' ',;
        else:
            print board[i-1],;
        if  i != 9:
            if i%3 == 0: print '\n---------\n',;
            else: print '|',;
    print '\n',;

def checkwin(board, piece):

    for i in range(3):
        if (board[3*i] == piece and board[3*i+1] == piece and board[3*i+2] == piece) or (board[i] == piece and board[i+1*3] == piece and board[i+2*3] == piece):
            return piece;      # piece wins

    if (board[5-1]==piece and ((board[1-1]==piece and board[9-1]==piece) or (board[3-1]==piece and board[7-1]==piece))):
      return piece;         # piece wins

    for i in range(9):
        if isblank(board,i+1):
            return board[i];          #there are still blank squares, game is not yet done

    return ' ';     # Tie

def human_move(board, piece):
    try:
        user = int(raw_input('Enter input:'));
    except ValueError:
        print 'Not integer';
    # if isinstance(user,int):
    #     if user <=9 and user >0:
    if not go(board,piece,user):
        human_move(board,piece);
    #         board[user] = piece;
    #         return board;
    #     else:
    #         print "Out of bound !";
    # else:
    #     print 'Integer expected <1-9> !';

def possible_win_simple(board, piece):
    print 'Possiblity check for ',piece;
    # return 1,9 value for direct use by go function
    # ROWS
    for f in [0,3,6]:
        if (board[f] == piece and board[f+1] == piece):
            if isblank(board,f+2+1): return f+2+1;
        if (board[f] == piece and board[f+2] == piece):
            if isblank(board,f+1+1): return f+1+1;
        if (board[f+1] == piece and board[f+2] == piece):
            if isblank(board,f+1): return f+1;
    # COLUMNS
    for f in [0,1,2]:
        if (board[f] == piece and board[f+1*3] == piece):
            if isblank(board,f+2*3+1): return f+2*3+1;
        if (board[f] == piece and board[f+2*3] == piece):
            if isblank(board,f+1*3+1): return f+1*3+1;
        if (board[f+1] == piece and board[f+2*3] == piece):
            if isblank(board,f+1): return f+1;
#     for row in range(3):
#         for col in range(3):
#             if (board[3*row + col] == piece and board[3*row + col+1] == piece):
#                 print 'hererr';
#                 return 3*row + col+2+1;
#             if (board[3*row + col] == piece and board[3*row + col+2] == piece):
#                 return 3*row + col+1+1;
#             if (board[3*row + col+1] == piece and board[3*row + col+2] == piece):
#                 return 3*row + col+1;
    # DIAGONAL
    if board[5-1] == piece:
        if board[1-1] == piece:
            if isblank(board,9): return 9;
        if board[9-1] == piece:
            if isblank(board,1): return 1;
        if board[3-1] == piece:
            if isblank(board,7): return 7;
        if board[7-1] == piece:
            if isblank(board,3): return 3;
    print "Error in possible_win_simple"
    return 0;

def possible_win_multi(board, piece):
    ### return 1,9 value for direct use by go function
    #print 'Possiblity check for ',piece;
    value = [];
    # ROWS
    for i in range(9):
        if board[i] == 'x':
            value.append(3);
        elif board[i] == 'o':
            value.append(5);
        else:
            value.append(2);
    win_value = 50;     # for 'o'
    if piece == 'x':
        win_value = 18;
    for f in [0,3,6]:
        if value[f] * value[f+1] * value[f+2] == win_value:
            if isblank(board,f+2+1): return f+2+1;
            if isblank(board,f+1+1): return f+1+1;
            if isblank(board,f+1): return f+1;
    # COLUMNS
    for f in [0,1,2]:
        if value[f] * value[f+1*3] * value[f+2*3] == win_value:
            if isblank(board,f+2*3+1): return f+2*3+1;
            if isblank(board,f+1*3+1): return f+1*3+1;
            if isblank(board,f+1): return f+1;
    # DIAGONAL
    if board[5-1] == piece:
        if board[1-1] == piece:
            if isblank(board,9): return 9;
        if board[9-1] == piece:
            if isblank(board,1): return 1;
        if board[3-1] == piece:
            if isblank(board,7): return 7;
        if board[7-1] == piece:
            if isblank(board,3): return 3;
    print "Error in possible_win_multi"
    return 0;

def backsum(sum):
    ### utility for possible_win_magic
    magic = [ 8, 3, 4, 1, 5, 9, 6, 7, 2 ];
    for i in range (9):
        if sum == magic[i]:
            return i+1;
    print "Error in backsum";

def possible_win_magic(board, piece):
    magic = [ 8, 3, 4, 1, 5, 9, 6, 7, 2 ];
    status = []; #[ 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
    pown = [];  #[ 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
    for i in range(9):
        print "i: ",i;
        if board[i] == piece:
            status.append(magic[i]);
            pown.append(i+1);   #all squares owned by piece
    print "status:",status;
    print "pown:",pown;
    for i in range(len(pown)-1):
        j = i+1;
        print "status[",i,"]",status[i];
        print "status[",j,"]",status[j];
        sum = 15 - (status[i] + status[j]);
        if sum >= 0 and sum <= 9:
            print "Found sum:",sum,"backsum:",backsum(sum);
            if isblank(board, backsum(sum)):
                return backsum(sum);
        #ignore otherwise


    if board[1] == piece and board[3] == piece:
        return 0+1;
    if board[1] == piece and  board[5] == piece:
        return 2+1;
    if board[7] == piece and  board[3] == piece:
        return 6+1;
    if board[7] == piece and  board[5] == piece:
        return 8+1;

    print "Error in possible_win_magic";
    return 0;

def possible_win(board, piece):
    ### return 1,9 value for direct use by go function
    if str(sys.argv[1]) == 'simple':
        print "Doing it simple";
        return possible_win_simple(board, piece);
    if str(sys.argv[1]) == 'multi':
        print "Doing it multi";
        return possible_win_multi(board, piece);
    if str(sys.argv[1]) == 'magic':
        print "Doing it magic";
        return possible_win_magic(board, piece);
    return possible_win_magic(board, piece);
    return 1;

def go(board, piece, n):
    # checks
    if n >9 and n <=0:
        print "Error: Can't go to",n;
        return False;
    if not isblank(board,n):
        print 'Error: Board already set at ',n,'to the value:',board[n-1];
        return False;
    board[n-1] = piece;
    #print 'Board (i.e.',n-1,')',n,'set to',piece;
    return True;

def make_center(board):
    if isblank(board,5): return 5;
    elif isblank(board, 2): return 2;
    elif isblank(board, 4): return 4;
    elif isblank(board, 6): return 6;
    elif isblank(board, 8): return 8;
    print "Error: Can't make center";

def make_blank(board):
    for i in range(1,10):
        if isblank(board,i): return i;
    print "Error: Can't make blank"

def get_turn(board):
    count = 0;
    for i in range(1,10):
        if not isblank(board,i):
            count += 1;
#     print 'Turn:',count+1;
    return count+1;

def computer_move_multi(board, piece1, piece2):
    turn = get_turn(board);
    if turn == 1:
        go(board,piece1,5);
    elif turn == 2:
        if isblank(board,5):
            go(board,piece1,5);
        else:
            go(board,piece1,1);
    elif turn == 3:
        if isblank(board,9):
            go(board,piece1,9);
        else:
            go(board,piece1,3);
    elif turn == 4:
        if possible_win(board,piece2) != 0:
            print 'pos(1): ',possible_win(board,piece2);
            go(board,piece1,possible_win(board,piece2));    # Block
        else:
            go(board,piece1,make_center(board));
    elif turn == 5:
        if possible_win(board,piece1) != 0:
            go(board,piece1,possible_win(board,piece1));    # Win
        elif possible_win(board,piece2) != 0:
            go(board,piece1,possible_win(board,piece2));    # Block
        elif isblank(board,7):
            go(board,piece1,7);     # Fork
        else:
            go(board,piece1,3);     # Fork
    elif turn == 6:
        if possible_win(board,piece2) != 0:
            go(board,piece1,possible_win(board,piece2));   # Block
        elif possible_win(board,piece1) != 0:
            go(board,piece1,possible_win(board,piece1));   # Win
        else:
            go(board,piece1,make_center(board));
    elif turn == 7:
        print 'pos (1): ', possible_win(board,piece1);
        if possible_win(board,piece1) != 0:
            go(board,piece1,possible_win(board,piece1));    # Win
        elif possible_win(board,piece2) != 0:
            go(board,piece1,possible_win(board,piece2));    # Block
        else:
            go(board,piece1,make_blank(board));
    elif turn == 8:
        if possible_win(board,piece2) != 0:
            go(board,piece1,possible_win(board,piece2));    # Block
        elif possible_win(board,piece1) != 0:
            go(board,piece1,possible_win(board,piece1));    # Win
        else:
            go(board,piece1,make_blank(board));
    elif turn == 9:
        if possible_win(board,piece1) != 0:
            go(board,piece1,possible_win(board,piece1));    # Win
        elif possible_win(board,piece2) != 0:
            go(board,piece1,possible_win(board,piece2));    # Block
        else:
            go(board,piece1,make_blank(board));
    return 1;

def computer_move(board, piece1, piece2):
    return computer_move_multi(board, piece1, piece2);

def main(argv):
    player1 = 'x'
    player2 = 'o'   #computer
    winner = 0;
#     board = initboard();
#     displayboard(board);
#     while isinstance(winner,int):
#         human_move(board,player1);
#         displayboard(board);
#         winner = checkwin(board,player1);
#         if winner != player1 and winner != ' ':
#             print 'Here ------';
#             if computer_move(board,player2,player1):
#                 winner = checkwin(board,player2);
#             else:
#                 print 'Computer passed the turn';
#             displayboard(board);
#     if winner != ' ':
#         print 'Winner is: ',winner;
#     else:
#         print "It's a tie!";
#
#     print 'Thanks for playing.';
    again = 'y';
    while again == 'y':# or again == '\n':
        board = initboard();
        winner = 0;
        displayboard(board,True);
        first = raw_input('Play first<y/n>?: ');
        if first == 'y':
            #winner = ' ';
            while isinstance(winner,int):
                human_move(board,player1);
                displayboard(board);
                winner = checkwin(board,player1);
                if winner != player1 and winner != ' ':
                    if computer_move(board,player2,player1):
                        print 'Computer moved this';
                        winner = checkwin(board,player2);
                    else:
                        print 'Computer passed the turn';
                    displayboard(board);
        else:
            #winner = ' ';
#             while isinstance(winner,int):
#                 if computer_move(board,player2,player1):
#                     print 'Computer moved this';
#                     winner = checkwin(board,player2);
#                 else:
#                     print 'Computer passed the turn';
#                 displayboard(board);
#                 if winner != player2 and winner != ' ':
#                     human_move(board,player1);
#                     displayboard(board);
#                 winner = checkwin(board,player1);
            while isinstance(winner,int):
                if computer_move(board,player1,player2):
                    print 'Computer moved this';
                    winner = checkwin(board,player1);
                    #print 'Winner: ',winner;
                else:
                    print 'Computer passed the turn';
                displayboard(board);
                if winner != player1 and winner != ' ':
                    human_move(board,player2);
                    displayboard(board);
                    winner = checkwin(board,player2);
        if winner != ' ':
            print 'Winner is: ',winner;
        else:
            print "It's a tie!";

        print 'Thanks for playing.';

        again = raw_input('Play again <y/n>?: ');

if __name__ == '__main__':
    main(sys.argv[1:]);
