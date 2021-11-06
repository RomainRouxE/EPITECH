import sys
import random
from alpha_ai import *

my_about = str('name="AlphaBrain", version="0.5", author="Tommik", country="USA"')
max_score = 100000 
min_score = -100000

class Brain:
    def __init__(self):
        self.to_send = False
        self.the_board = 0
        self.stop = False
        self.answer = ''
        self.words_list = []
        self.received = ''
        self.cmd = ''
        self.board_size = 0
        self.x_cord = -1
        self.y_cord = -1
        self.new_cords = []
        self.info = ''
        self.value = ''
        self.time_turn = -1
        self.match = -1
        self.mem = -1
        self.left = -1
        self.game_type = -1
        self.rule = -1,
        self.evaluate = [-1,-1]
        self.folder = ''
        self.turn = 0
        self.CMDS = {'START' : self.handle_start,
        'TURN'  : self.handle_turn,
        'BEGIN\n' : self.handle_begin,
        'BOARD\n' : self.handle_board,
        'END\n'   : self.handle_end,
        'ABOUT\n' : self.handle_about,
        'INFO'  : self.handle_info
        }
        self.INFOS = { 'timeout_turn' : self.set_turn,
        'timeout_match' : self.set_match,
        'max_memory'    : self.set_mem,
        'time_left'     : self.set_time,
        'game_type'     : self.set_game,
        'rule'          : self.set_rule,
        'evaluate'      : self.set_mouse,
        'folder'        : self.set_folder
        }

    #def debug(self, str_debug):
    #    file = open('/home/tommik/gomoku/out.txt', 'a')
    #    file.write(str_debug)
    #    file.close()
    
    def set_turn(self):
        self.time_turn = int(self.value)

    def set_match(self):
        self.match = int(self.value)

    def set_mem(self):
        self.mem = int(self.value)

    def set_time(self):
        self.left = int(self.value)

    def set_game(self):
        self.game_type = int(self.value)

    def set_rule(self):
        self.rule = int(self.value)
    
    def set_mouse(self):
        self.values_tmp = self.value.split(',')
        self.evaluate[0] = self.values_tmp[0]
        self.evaluate[1] = self.values_tmp[1]

    def set_folder(self):
        self.folder = self.value

    def handle_start(self):
        if len(self.words_list) > 2 or int(self.words_list[1]) > 100:
            self.answer = 'ERROR size to big'
        else:
            self.answer = 'OK'
            self.board_size = int(self.words_list[1])
            self.the_board = [[3 for i in range(self.board_size)] for j in range(self.board_size)]
        self.to_send = True

    def handle_about(self):
        print(my_about)
 
    def update_board(self, cords):
        cords = cords.split(',')
        x = int(cords[0])
        y = int(cords[1])
        player = int(cords[2].split('\n')[0])
        self.the_board[x][y] =  player

    def handle_begin(self):
        self.best_ai()
        self.to_send = True

    def handle_end(self):
        self.stop = True

    def handle_info(self):
        if len(self.words_list) < 3:
            self.answer = "Error"
            self.to_send = True
        self.info = self.words_list[1]
        self.value = self.words_list[2]
        self.INFOS[self.info]()

    def handle_board(self):
        tmp_recv = ""
        while tmp_recv != "DONE\n":
            tmp_recv = sys.stdin.readline()
            if tmp_recv != "DONE\n":
                self.update_board(tmp_recv)


    def handle_turn(self):
        new_cords = self.words_list[1].split(',')
        self.x_cord = int(new_cords[0])
        self.y_cord = int(new_cords[1])
        self.the_board[self.x_cord][self.y_cord] = 2
        self.best_ai()
        self.to_send = True

    def handle_received(self):
        self.cmd = self.words_list[0]
        self.CMDS[self.cmd]()

    def best_ai(self):
        if self.turn == 0 and self.the_board[9][9] == 3:
            next_x, next_y = 9,9
            self.turn = 1
        else:
            next_x, next_y = alpha_launch(self.the_board, max_score, min_score, self.board_size)
        self.answer = str(next_x) + ',' + str(next_y)
        self.the_board[next_x][next_y] = 1

    def loop(self):
        while self.stop == False:
            self.received = sys.stdin.readline()
            self.words_list = self.received.split(' ')
            self.handle_received()
            if self.to_send == True:
                print(self.answer)
                sys.stdout.flush()
                self.to_send = False

random.seed(7)
my_brain = Brain()
my_brain.loop()