/*
** EPITECH PROJECT, 2017
** fill.c
** File description:
** fill pushswap
*/

#include "my.h"

void fill(t_list **l, int nb)
{
	t_list *tmp;
	t_list *new;

	tmp = NULL;
	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return;
	new->nb = nb;
	new->next = NULL;
	tmp = *l;
	if (!tmp)
		*l = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list *fill_one(t_list **l, int nb)
{
	t_list *new;

	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->nb = nb;
	new->next = *l;
	return (new);
	free(new);
}
