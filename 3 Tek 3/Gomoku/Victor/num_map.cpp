/*
** EPITECH PROJECT, 2021
** num_map
** File description:
** num_map
*/

#include <array>
#include "game.hpp"



void check_max(game &board, short sign, short d, short x,
               short y, short &bpsbl)
{
    std::array<short, 5> psbl{1, 1, 1, 1, 1};
    short dx = d&1;
    short dy = (d&-2)/2;
    short size = board.size();
    short p1;
    short p2;
    short xi;
    short yi;
    for (short i = 1; i < 5; i++) {
        xi = dx*i;
        yi = dy*i;
        if (x+xi < size && y+yi >= 0 && y+yi < size)
            p1 = board.pos(x+xi, y+yi).value()*sign;
        if (x-xi >= 0 && y-yi >= 0 && y-yi < size)
            p2 = board.pos(x-xi, y-yi).value()*sign;
        if (p1 != 0 || p2 != 0) {
            if (psbl[0] >= 0 && p2 != 0)
                psbl[0] = p2 < 0 ? -1 : psbl[0]+1;
            if (psbl[1] >= 0 && i <= 3)
                psbl[1] = ((-(i<=1)&p1)|p2) < 0 ? -1 : psbl[1]+(i<=1&&p1)+(p2!=0);
            if (psbl[2] >= 0 && i <= 2)
                psbl[2] = (p1|p2) < 0 ? -1 : psbl[2]+1+(p1&&p2);
            if (psbl[3] >= 0 && i <= 3)
                psbl[3] = (p1|(-(i<=1)&p2)) < 0 ? -1 : psbl[3]+(p1!=0)+(i<=1&&p2);
            if (psbl[4] >= 0 && p1 != 0)
                psbl[4] = p1 < 0 ? -1 : psbl[4]+1;
        }
    }
    short max = MAX(psbl[0], MAX(psbl[1], MAX(psbl[2], MAX(psbl[3], psbl[4]))));
    if (max > bpsbl) {
        bpsbl = max;
        board.pos(x, y).toward(d);
    }
}

short check_pos(game &board, short x, short y, short p)
{
    short sign = p == 1 ? 1 : -1;
    p = 1;
    check_max(board, sign, 1, x, y, p);
    check_max(board, sign, 3, x, y, p);
    check_max(board, sign, 2, x, y, p);
    check_max(board, sign, -1, x, y, p);
    return p*sign;
}
