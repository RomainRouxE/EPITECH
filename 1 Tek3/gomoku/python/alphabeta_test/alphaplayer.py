from copy import deepcopy
from operator import itemgetter
import time
max_score = 100000 
min_score = -100000
max_depth = 3
board_size = 19
the_board = [[3 for i in range(0,board_size)] for j in range(0,board_size)]

def time_print(time1, time2, name):
    print '%s function took %0.3f ms' % (name, (time2-time1)*1000.0)

def print_board(board):
    for i in range(board_size):
        print(board[i])

def border_value(cord, offset):
    if cord + offset > board_size:
        return board_size
    else:
        return cord + offset

def evaluation(board):
    for i in range(board_size):
        for j in range(board_size):
            if board[i][j] != 3:
                if j + 5 < board_size:
                    for z in range(j, border_value(j, 5)):
                        if board[i][z] != board[i][j]:              
                            break
                        elif z == j + 4:
                            return board[i][j]
                for z in range(i, border_value(i, j)):
                    if board[z][j] != board[i][j]:
                        break
                    elif z == i + 4:
                        return board[i][j]
                if i + 5 < board_size and j + 5 < board_size:
                    for z, y in zip(range(i, border_value(i, 5)), range(j, border_value(j, 5))):
                        if board[z][y] != board[i][j]:
                            break
                        elif z == i + 4:
                            return board[z][y]
                if i - 4 > -1 and j - 1 > -2:
                    for z, y in zip(range(i,i - 5, -1), range(j, border_value(j, 5))):
                        if board[z][y] != board[i][j]:
                            break
                        elif y == j + 4:
                            return board[i][j]
    return 0            

def scoring(board, depth, maximize):
    res = evaluation(board)
    if res == 0 or res == 3:
        return 0
    elif maximize == False:
        return min_score/depth
    else:
        return max_score/depth

def update_board(actual_board, move, maximize):
    child_board = deepcopy(actual_board)
    if maximize == True:
        child_board[move[0]][move[1]] = 1
    else:
        child_board[move[0]][move[1]] = 2
    return child_board

def apply_alpha(alpha, beta, score, maximize):
    if maximize:
        return max(alpha, score), beta
    else:
        return alpha, min(beta, score)

def score_case(board, i, j):
    point = 0
    point = score_down(board, i, j, point)
    point = score_up(board, i, j, point)
    point = score_left(board, i, j, point)
    point = score_right(board, i, j, point)
    point = score_down_right(board, i, j, point)
    point = score_left_up(board, i, j, point)
    point = score_right_up(board, i, j, point)
    point = score_down_left(board, i, j, point)
    return point

def score_right(board, i, j, point):
    if j + 1 > board_size - 1 or board[i][j+1] == 3:
        return point + 0
    elif board[i][j+1] == 1:
        return point + 2
    else:
        return point + 1

def score_left(board, i, j, point):
    if j - 1 < 0 or board[i][j - 1] == 3:
        return point + 0
    elif board[i][j-1] == 1:
        return point + 2
    else:
        return point + 1

def score_up(board, i, j, point):
    if i - 1 < 0 or board[i-1][j] == 3:
        return point + 0
    elif board[i-1][j] == 1:
        return point + 2
    else:
        return point + 1

def score_down(board, i, j, point):
    if i + 1 > board_size - 1 or board[i+1][j] == 3:
        return point + 0
    elif board[i+1][j] == 1:
        return point + 2
    else:
        return point + 1

def score_right_up(board, i, j, point):
    if j + 1 > board_size - 1 or i + 1 > board_size - 1 or board[i+1][j+1] == 3:
        return point + 0
    elif board[i][j+1] == 1:
        return point + 2
    else:
        return point + 1

def score_left_up(board, i, j, point):
    if i - 1 < 0 or j - 1 < 0 or board[i - 1][j - 1] == 3:
        return point + 0
    elif board[i][j-1] == 1:
        return point + 2
    else:
        return point + 1

def score_down_left(board, i, j, point):
    if i + 1 > board_size - 1 or j - 1 < 0 or board[i+1][j-1] == 3:
        return point + 0
    elif board[i-1][j] == 1:
        return point + 2
    else:
        return point + 1

def score_down_right(board, i, j, point):
    if i + 1 > board_size - 1 or j + 1 > board_size - 1 or board[i+1][j+1] == 3:
        return point + 0
    elif board[i+1][j] == 1:
        return point + 2
    else:
        return point + 1


def possible_move(board):
    moves = []
    for i in range(board_size):
        for j in range(board_size):
            if board[i][j] == 3:
                moves.append([i, j, score_case(board, i, j)])
    moves = sorted(moves, key=itemgetter(2), reverse = True)
    return moves

def alphabeta(actual_board, depth, alpha, beta, maximize, old_move, start):
    moves = possible_move(actual_board)
    if len(moves) == 0 or depth >= max_depth:
        return None, 0
    
    best_score = None
    best_cords = None
    for move in moves:
        child_board = update_board(actual_board, move, maximize)
        if depth == 1:
            old_move = move
        time1 = time.time()
        if scoring(child_board, depth, maximize) != 0:
            print_board(child_board)
            return old_move, scoring(child_board, depth, maximize)
        cords, score = alphabeta(child_board, depth + 1, alpha, beta, not maximize, old_move, start)
        if best_score == None:
            best_cords, best_score = cords, score
        elif maximize and score > best_score:
            best_score, best_cords = score, cords
        elif not maximize and score < best_score:
            best_score, best_cords = score, cords
        alpha, beta = apply_alpha(alpha, beta, score, maximize)
        if (time.time() - start) * 1000 > 4900:
            print('timeoff')
            return best_cords, best_score
    return best_cords, best_score

the_board[8][0] = 1
the_board[7][1] = 1
the_board[6][2] = 1
the_board[5][3] = 1
the_board[4][4] = 3
#the_board[3][5] = 1
#time.sleep(5.0)
my_res = []
timea= time.time()
print('end', alphabeta(the_board, 1, max_score, min_score, True, None, time.time()))
timeb = time.time()
time_print(timea, timeb, 'all')