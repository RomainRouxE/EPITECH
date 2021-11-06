/*
** EPITECH PROJECT, 2021
** header
** File description:
** header
*/

#pragma once
#define MAX(x,y) (x > y ? x : y)

#include <vector>
#include <string>

class cell
{
public:
    cell() = default;
    ~cell() = default;
    cell &operator=(cell &);
    void toward(short);
    void value(short);
    short toward();
    short value();
private:
    short val = 0;
    short dir = 0;
};

class game
{
public:
    game() = default;
    game(short);
    ~game();
    game &operator=(const game &);
    cell &operator[](const int);
    short size();
    cell &pos(const short, const short);
    void turn(short, short, short);
private:
    cell* grid;
    short sz = 0;
};
short check_pos(game &, short, short, short);
namespace inst {
    void start(std::vector<std::string> &, game &);
    void turn(std::vector<std::string> &, game &);
    void begin(game &);
    void board(game &);
    void info(std::vector<std::string> &);
    //bool end(std::vector<std::string> &);
}
