/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main Eval_Expr.c
*/

#include "include/my.h"

int main(int ac,char **av)
{
        if (ac == 2) {
                my_put_nbr(eval_expr(av[1]));
                my_putchar('\n');
                return (0);
        }
        return (84);
}
