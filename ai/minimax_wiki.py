#!/usr/bin/python
import sys;

class Situation:
    ''' This class's object will be returned by minimax to return the value for itself and path for outside world '''
    def __init__(self,bestValue):
        self.bestValue = bestValue;
        print 'Initialized Situation.bestValue to ',bestValue;
        self.path = [];
    def bestMove(self):
        ''' Return Int: first move on the best path '''
        if self.path:
            return path[0];
        else:
            print 'error getting the best move from current Situation';

### Board will be int whenever it is empty, otherwise it will be a char 'x' or 'o'
def initboard():
    board = [];
    board = range(1,10); #multi
    return board;

def isblank(board, pos):
    ''' :Return Int: pos is 1:9 '''
    return isinstance(board[pos-1],int);

def opposite(piece):
    if piece == 'x':
        print 'DEBUG: o opposite of ',piece;
        return 'o';
    print 'DEBUG: x opposite of ',piece;
    return 'x';

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
    """ Check board if there is a win for the piece
    :param piece: check win situation of piece
    :return piece name(i.e. the passed 'x'/'o') if wins other wise return the value in first blank square( a number usually)
    """
    for i in range(3):
        if (board[3*i] == piece and board[3*i+1] == piece and board[3*i+2] == piece) or (board[i] == piece and board[i+1*3] == piece and board[i+2*3] == piece):
            return piece;      # piece wins
    if (board[5-1]==piece and ((board[1-1]==piece and board[9-1]==piece) or (board[3-1]==piece and board[7-1]==piece))):
      return piece;         # piece wins
    for i in range(9):
        if isblank(board,i+1):
            return board[i];          #there are still blank squares, game is not yet done
    return ' ';     # Tie

def possible_win(board, piece):
    """ :Return Int: 1,9 value for direct use by go function """
    return NotImplementedError;

def score(board,piece,depth):
    """ :Return Int: 1-10 """
    if not depth:
        depth = 0;
    if checkwin(board,piece) == piece:
        return 10-depth;
    elif checkwin(board, opposite(piece)) == opposite(piece):
        return depth-10;
    else:
        return 0;

def moves(board,piece):
    ''' :Return List: Int list with all possible moves '''
    list = [];
    for i in range(1,10):
        if isblank(board,i):
            list.append(i);
    print "Possible moves for ",piece,": ",list;
    return list;

def getChildBoard(board, piece, child):
    retBoard = board[:]; # list(board): new copy of list
    # retBoard = [];
    # for i in range(0,9):
    #     #print 'DEBUG: appending ',board[i],'to ',retBoard;
    #     retBoard.append(board[i]);
    #print 'DEBUG: Parent Board',retBoard;
    value = go(retBoard,piece,child)
    print 'DEBUG: Child Board',retBoard;
    print 'DEBUG: Board: ',board;
    if not value: #i.e False
        print "Error in getting child board";
    return retBoard;

# function minimax(node, depth, maximizingPlayer)
def minimax(board, piece, depth):
    # if depth = 0 or node is a terminal node
    if depth == 0 or checkwin(board,piece) == piece or checkwin(board,piece) == ' ' :  #Win or Tie
        # return the heuristic value of node
        sys.exit(1);
        return Situation(score(board, piece, depth));
    # if maximizingPlayer
    if piece == 'o': # 'o' is the computer
        # bestValue := -INFINITY
        #bestValue = - sys.maxint - 1;
        currentSitu = Situation(- sys.maxint - 1);
        childList = moves(board,piece);
        # for each child of node
        for child in childList:
            # val := minimax(child, depth - 1, FALSE))
            childboard = getChildBoard(board, piece, child);
            val = minimax(childboard, opposite(piece), depth - 1);
            # bestValue := max(bestValue, val);
            if currentSitu.bestValue < val.bestValue:
                currentSitu.bestValue = val.bestValue;
                for i in val.path:
                    currentSitu.path.append(i);
            #bestValue = max(bestValue, val.bestValue);
        # return bestValue
        return currentSitu;
    # else
    else:
        # bestValue := +INFINITY
        #bestValue = sys.maxint - 1;
        currentSitu = Situation( sys.maxint - 1);
        childList = moves(board,opposite(piece));
        # for each child of node
        for child in childList:
            # val := minimax(child, depth - 1, TRUE))
            childboard = getChildBoard(board, opposite(piece), child);
            print 'depht: ',depth;
            val = minimax(childboard, opposite(piece), depth - 1);
            # bestValue := min(bestValue, val);
            if currentSitu.bestValue > val.bestValue:
                currentSitu.bestValue = val.bestValue;
                for i in val.path:
                    currentSitu.path.append(i);
            #bestValue = min(bestValue, val);
        # return bestValue
        return currentSitu;
    return NotImplementedError;

def computer_move(board, piece1, piece2):
    # minimax(origin, depth, TRUE)
    situation = minimax(board,piece1,8);
    go(board, piece1, situation.path[0]);
    return 1;

def human_move(board, piece):
    try:
        user = int(raw_input('Enter input:'));
    except ValueError:
        print 'Not integer';
    if not go(board,piece,user):
        human_move(board,piece);

def main(argv):
    player1 = 'x'
    player2 = 'o'   #computer
    winner = 0;
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
