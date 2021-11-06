/*
** EPITECH PROJECT, 2017
** operation.c
** File description:
** operation pushswap
*/

#include "my.h"

t_list *pa(t_list *lb, t_list **la, int v)
{
	if (lb) {
		if (v == 1)
			my_putstr("pa");
		else
			my_putstr(" pa");
		return (fill_one(la, lb->nb));
	}
	return (NULL);
}

t_list *pb(t_list *la, t_list **lb)
{
	if (la) {
		my_putstr("pb");
		return (fill_one(lb, la->nb));
	}
	return (NULL);
}

void *ra(t_list *la)
{
	t_list *tmp;
	t_list *first;
	t_list *bkp;

	tmp = la;
	bkp = la;
	first = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	la = bkp->next;
	first->next = NULL;
	my_putstr("ra");
	return (la);
}
