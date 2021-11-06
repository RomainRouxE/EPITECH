/*
** EPITECH PROJECT, 2017
** pushswap.c
** File description:
** pushwap
*/

#include "my.h"

static t_list *sort(t_list *lb, t_list *tmp, int v)
{
	while (lb) {
		tmp = pa(lb, &tmp, v);
		lb = lb->next;
	}
	return (tmp);
}

void pushswap(t_list *la, t_list *lb, int v)
{
	t_list *tmp;

	tmp = la;
	while (is_order(tmp) == -1) {
		if (minimal(tmp->nb, tmp) == 1)	{
			lb = pb(tmp, &lb);
			tmp = tmp->next;
		}
		else
			tmp = ra(tmp);
		if (is_order(tmp) == -1)
			my_putchar(' ');
	}
	tmp = sort(lb, tmp, v);
}
