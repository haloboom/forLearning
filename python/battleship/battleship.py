from random import randint

def getrow(rang):
    return randint(1,rang)
    
def getcol(rang):
    return randint(1,rang)
    
def init_board(board,row,col):
    for i in range(row):
        board.append(["O"]*col)

def print_board(board):
    for row in board:
        print " ".join(row)

def turn_run(turn):
    row = input("Enter Row: ")
    col = input("Enter Col: ")
    print "Drawing Board..."
    board=[]
    init_board(board,row,col)
    print_board(board)
    shiprow = getrow(row)
    shipcol = getcol(col)
    guess_row=0
    guess_col=0
    for i in range(1,turn+1):
        print "Turn:",i," ...Start!"
        guess_row = input("Guess Row: ")
        guess_col = input("Guess Col: ")
        if guess_row>row or guess_col>col:
            print "Bad Guess! ...Over Flow!"
        elif board[guess_row-1][guess_col-1] is 'X':
            print "You already explored that."
        elif guess_row is shiprow and guess_col is shipcol:
            print "You Win!"
            break
        else:
            print "Oops,you missed my battaleship."
            board[guess_row-1][guess_col-1]='X'
            print_board(board)
    print "Game Over","Ship_row:",shiprow,"Ship_col:",shipcol

if __name__ == "__main__":
    turn_run(2)
