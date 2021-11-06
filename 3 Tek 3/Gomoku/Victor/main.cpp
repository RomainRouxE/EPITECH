/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** main
*/

#include <iostream>
#include "game.hpp"

using namespace inst;

bool read_inst(std::vector<std::string> &cmd)
{
    std::string line;
    std::getline(std::cin, line);
    if (line == "")
        return false;
    size_t j = line.find(" ");
    if (j != 0)
        cmd.push_back(line.substr(0, j));
    size_t i = j+1;
    while (j != std::string::npos && i < line.size()) {
        j = line.find(",", i);
        if (i != j)
            cmd.push_back(line.substr(i, j-i));
        i = j+1;
        if (cmd.size() >= 4)
            break;
    }
    if (cmd.empty())
        return false;
    return true;
}

int main(int ac, char **av)
{
    if (ac > 1) {
        std::cerr << "no argument needed" << std::endl;
        return (84);
    }
    (void)av;
    game game_board;
    while (1) {
        std::vector<std::string> cmd;
        if (!read_inst(cmd))
            continue;
        if (cmd[0] == "START") {
            try {
                start(cmd, game_board);
            } catch (...) {
                return 84;
            }
        } else if (cmd[0] == "TURN")
            turn(cmd, game_board);
        else if (cmd[0] == "BEGIN")
            begin(game_board);
        else if (cmd[0] == "BOARD")
            board(game_board);
        else if (cmd[0] == "INFO") {
        } else if (cmd[0] == "END")
            break;
        else
            std::cout << "command not found" << std::endl;
        // unsigned short size = game_board.size();
        // for (unsigned short i = 0; i < size*size; i++)
        //     std::cout << game_board[i] << (i%size == size-1 ? "\n" : "\t");
    }
    return 0;
}
