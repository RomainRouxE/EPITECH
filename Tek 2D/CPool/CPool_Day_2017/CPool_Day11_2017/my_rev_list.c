/*
** EPITECH PROJECT, 2017
** my_rev_list.c
** File description:
** my rev list
*/

#include <stdlib.h>
#include "./include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
	linked_list_t *list = *begin;
	linked_list_t *before = NULL;
	linked_list_t *after = NULL;

	while(list != NULL) {
		after = list->next;
		list->next = before;
		before = list;
		list = after;
	}
	*begin = before;
}
