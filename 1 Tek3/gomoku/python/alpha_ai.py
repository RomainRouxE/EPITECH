from copy import deepcopy
from operator import itemgetter
import time
max_depth = 4
max_score = 100000 
min_score = -100000

class Game:
    def __init__(self, board_size, the_board):
        self.board_size = board_size
        self.board = the_board

def border_value(cord, offset, board_size):
    if cord + offset > board_size:
        return board_size
    else:
        return cord + offset

def evaluation(board, board_size):
    for i in range(board_size):
        for j in range(board_size):
            if board[i][j] == 1 or board[i][j] == 2:
                if j + 5 < board_size:
                    for z in range(j, j + 5):
                        if board[i][z] != board[i][j]:              
                            break
                        elif z == j + 4:
                            return board[i][j]
                for z in range(i, border_value(i, j, board_size)):
                    if board[z][j] != board[i][j]:
                        break
                    elif z == i + 4:
                        return board[i][j]
                if i + 5 < board_size and j + 5 < board_size:
                    for z, y in zip(range(i, border_value(i, 5,board_size)), range(j, border_value(j, 5, board_size))):
                        if board[z][y] != board[i][j]:
                            break
                        elif z == i + 4:
                            return board[z][y]
                if i - 4 > -1 and j - 1 > -2:
                    for z, y in zip(range(i,i - 5, -1), range(j, border_value(j, 5, board_size))):
                        if board[z][y] != board[i][j]:
                            break
                        elif y == j + 4:
                            return board[i][j]
    return 0            

def scoring(the_game, depth, maximize):
    res = evaluation(the_game.board, the_game.board_size)
    if res == 0 or res == 3:
        return 0
    elif maximize == False:
        return min_score/depth
    else:
        return max_score/depth

def create_board(the_game, move, maximize):
    child_game = Game(the_game.board_size, deepcopy(the_game.board))
    evil_game = Game(the_game.board_size, deepcopy(the_game.board))
    if maximize == True:
        child_game.board[move[0]][move[1]] = 1
        evil_game.board[move[0]][move[1]] = 2
    else:
        child_game.board[move[0]][move[1]] = 2
        evil_game.board[move[0]][move[1]] = 1
    return child_game, evil_game

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

def score_right(game, i, j, point):
    if j + 1 > game.board_size - 1 or game.board[i][j+1] == 3:
        return point + 0
    elif game.board[i][j+1] == 1:
        return point + 2
    else:
        return point + 1

def score_left(game, i, j, point):
    if j - 1 < 0 or game.board[i][j - 1] == 3:
        return point + 0
    elif game.board[i][j-1] == 1:
        return point + 2
    else:
        return point + 1

def score_up(game, i, j, point):
    if i - 1 < 0 or game.board[i-1][j] == 3:
        return point + 0
    elif game.board[i-1][j] == 1:
        return point + 2
    else:
        return point + 1

def score_down(game, i, j, point):
    if i + 1 > game.board_size - 1 or game.board[i+1][j] == 3:
        return point + 0
    elif game.board[i+1][j] == 1:
        return point + 2
    else:
        return point + 1

def score_right_up(game, i, j, point):
    if j + 1 > game.board_size - 1 or i + 1 > game.board_size - 1 or game.board[i+1][j+1] == 3:
        return point + 0
    elif game.board[i][j+1] == 1:
        return point + 2
    else:
        return point + 1

def score_left_up(game, i, j, point):
    if i - 1 < 0 or j - 1 < 0 or game.board[i - 1][j - 1] == 3:
        return point + 0
    elif game.board[i][j-1] == 1:
        return point + 2
    else:
        return point + 1

def score_down_left(game, i, j, point):
    if i + 1 > game.board_size - 1 or j - 1 < 0 or game.board[i+1][j-1] == 3:
        return point + 0
    elif game.board[i-1][j] == 1:
        return point + 2
    else:
        return point + 1

def score_down_right(game, i, j, point):
    if i + 1 > game.board_size - 1 or j + 1 > game.board_size - 1 or game.board[i+1][j+1] == 3:
        return point + 0
    elif game.board[i+1][j] == 1:
        return point + 2
    else:
        return point + 1


def possible_move(the_game):
    moves = []
    for i in range(the_game.board_size):
        for j in range(the_game.board_size):
            if the_game.board[i][j] == 3:
                moves.append([i, j, score_case(the_game, i, j)])
    moves = sorted(moves, key=itemgetter(2), reverse = True)
    return moves

def print_board(the_board, board_size):
    for i in range(board_size):
        print(the_board[i])

def alphabeta(the_game, depth, alpha, beta, maximize, old_move, start):
    moves = possible_move(the_game)
    if len(moves) == 0 or depth >= max_depth:
        return None, 0
    
    best_score = None
    best_cords = None
    for move in moves:
        child_game, evil_board = create_board(the_game, move, maximize)
        if depth == 1:
            old_move = move
        if scoring(child_game, depth, maximize) != 0 or scoring(evil_board, depth, maximize) != 0:
            return old_move, scoring(child_game, depth, maximize)
        cords, score = alphabeta(child_game, depth + 1, alpha, beta, not maximize, old_move, start)
        if best_score == None:
            best_cords, best_score = cords, score
        elif maximize and score > best_score:
            best_score, best_cords = score, cords
        elif not maximize and score < best_score:
            best_score, best_cords = score, cords
        alpha, beta = apply_alpha(alpha, beta, score, maximize)
        if (time.time() - start) * 1000 > 4890:
           return best_cords, best_score
    return best_cords, best_score


def alpha_launch(the_board, max_score, min_score, board_size):
    the_game = Game(board_size, the_board)
    res = alphabeta(the_game, 1, max_score, min_score, True, None, time.time())
    if res[0] == None:
        moves = possible_move(the_game)
        return moves[0][0], moves[0][1]
    else:
        return res[0][0], res[0][1]
