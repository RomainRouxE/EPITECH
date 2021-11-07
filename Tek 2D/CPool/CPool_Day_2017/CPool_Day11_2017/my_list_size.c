/*
** EPITECH PROJECT, 2017
** my_list_size.c
** File description:
** my list size
*/
#include "./include/mylist.h"
#include <unistd.h>

int my_list_size(linked_list_t const *begin)
{
	linked_list_t const *tmp;
	int	cnt = 0;
	tmp = begin;

	while(tmp != NULL) {
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}
