/*
** EPITECH PROJECT, 2021
** game
** File description:
** game
*/

#include <stdexcept>
#include <iostream>
//#include "game.hpp"
#include "ai.hpp"
#include "getnbr.hpp"

cell &cell::operator=(cell &c)
{
    val = c.val;
    dir = c.dir;
    return *this;
}

void cell::toward(short d)
{
    dir = d;
}

void cell::value(short v)
{
    val = v;
}

short cell::toward()
{
    return dir;
}

short cell::value()
{
    return val;
}

game::game(short size)
{
    try {
        sz = size;
        grid = new cell[sz*sz];
    } catch (...) {
        throw;
    }
}

game::~game()
{
    if (sz != 0)
        delete[] grid;
}

game &game::operator=(const game &game)
{
    int size = (int)game.sz;
    if (sz != game.sz) {
        if (sz != 0)
            delete[] grid;
        try {
            grid = new cell[size*size];
        } catch (...) {
            throw;
        }
    }
    for (int i = 0; i < size*size; i++)
        grid[i] = game.grid[i];
    sz = game.sz;
    return *this;
}

cell &game::operator[](const int x)
{
    return grid[x];
}

short game::size()
{
    return sz;
}

cell &game::pos(const short x, const short y)
{
    return grid[x+y*sz];
}

void game::turn(short x, short y, short p)
{
    if (grid[x+y*sz].value() != 0)
        throw std::runtime_error("cell not free");
    this->grid[x+y*sz].value(p);
}

void inst::start(std::vector<std::string> &cmd, game &game_board)
{
    short size;
    try {
        size = getnbr<short>(cmd[1].c_str());
    } catch (std::out_of_range &e) {
        std::cerr << "Error: start: unsupported size." << std::endl;
        return;
    } catch (std::exception &e) {
        std::cerr << e.what();
        return;
    }
    if (size < 0) {
        std::cerr << "Error: start: negative grid size." << std::endl;
        return;
    } else if (size < 5) {
        std::cerr << "Error: start: grid size is too small." << std::endl;
        return;
    }
    try {
        game board(size);
        game_board = board;
    } catch (...) {
        std::cerr << "Memory error: couldn't create the board." << std::endl;
        throw;
    }
}

void inst::turn(std::vector<std::string> &cmd, game &board)
{
    short size = board.size();
    if (size == 0) {
        std::cerr << "Error: turn: you have to run START intruction first." << std::endl;
        return;
    }
    short x;
    short y;
    try {
        x = getnbr<short>(cmd[1].c_str())-1;
        y = getnbr<short>(cmd[2].c_str())-1;
    } catch (std::exception &e) {
        std::cerr << "Error: turn: the coordinates have to be numbers"
                  << " between 1 and " << size << std::endl;
        return;
    }
    if (x >= size || x < 0 || y >= size || y < 0) {
        std::cout << "Error: turn: the coordinates have to be numbers"
                  << " between 1 and " << size << std::endl;
        return;
    }
    if (board.pos(x, y).value() != 0) {
        std::cerr << "Error: turn: that cell isn't free, you can't play here" << std::endl;
        return;
    }
    board.turn(x, y, check_pos(board, x, y, 2));
    ai_plays(board);
}

void inst::begin(game &board)
{
    if (board.size() == 0) {
        std::cerr << "Error: begin: you have to run START intruction first." << std::endl;
        return;
    }
    short p = (board.size()+1)/2;
    try {
        board.turn(p-1, p-1, 1);
    } catch (std::exception &e) {
        std::cerr << "Error: begin: you cannot call BEGIN intruction"
                  << " during the match." << std::endl;
        return;
    }
    std::cout << p << "," << p << std::endl;
}

void parse_move(std::string &line, game &board)
{
    size_t i;
    size_t j;
    if ((i = line.find(",")) == std::string::npos ||
        (j = line.find(",", i+1)) == std::string::npos) {
        std::cout << "Error: board: you have to enter coordinates (x, y)"
                  << " and a player number (1|2)" << std::endl;
        return;
    }
    short size = board.size();
    short x;
    short y;
    short p;
    try {
        x = getnbr<short>(line.substr(0, i).c_str())-1;
        y = getnbr<short>(line.substr(i+1, j-i-1).c_str())-1;
        p = getnbr<short>(line.substr(j+1).c_str());
    } catch (...) {
        std::cout << "Error: board: the coordinates have to be numbers"
                  << " between 1 and " << size
                  << " and the player number has to be 1 or 2"
                  << std::endl;
        return;
    }
    if (x >= size || x < 0 || y >= size || y < 0 || (p != 1 && p!= 2)) {
        std::cout << "Error: board: the coordinates have to be numbers"
                  << " between 1 and " << size
                  << " and the player number has to be 1 or 2"
                  << std::endl;
        return;
    }
    if (board.pos(x, y).value() != 0) {
        std::cerr << "Error: turn: that cell isn't free, you can't play here" << std::endl;
        return;
    }
    board.turn(x, y, check_pos(board, x, y, p));
}

void inst::board(game &board)
{
    if (board.size() == 0) {
        std::cerr << "Error: board: you have to run START intruction first." << std::endl;
        return;
    }
    std::string line;
    while (1) {
        std::getline(std::cin, line);
        if (line == "") {
            std::cout << "Error: board: empty line."
                      << " you have to enter coordinates (x, y)"
                      << " and a player number (1|2)" << std::endl;
        } else if (line == "DONE")
            return;
        else 
            parse_move(line, board);
    }
    ai_plays(board);
}
