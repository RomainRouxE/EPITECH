/*
** EPITECH PROJECT, 2017
** order.c
** File description:
** order pushswap
*/

#include "my.h"

int is_order(t_list *l)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = l;
	tmp2 = l;
	while (tmp1) {
		tmp2 = tmp1;
		while (tmp2) {
			if (tmp1->nb > tmp2->nb)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int minimal(int bkp, t_list *l)
{
	int min;
	t_list *tmp;

	tmp = l;
	min = tmp->nb;
	while (tmp) {
		if (bkp > tmp->nb && min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	if (bkp == min)
		return (1);
	else
		return (0);
}
