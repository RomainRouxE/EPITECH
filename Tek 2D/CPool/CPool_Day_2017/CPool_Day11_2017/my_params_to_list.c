/*
** EPITECH PROJECT, 2017
** my_params_to_list.c
** File description:
** task01
*/

#include "./include/mylist.h"
#include <stdlib.h>

int my_put_in_list(linked_list_t **list, void *data)
{
	linked_list_t *element;

	element = malloc(sizeof(*element));
	element->data = data;
	element->next = *list;
	*list = element;
	return (0);
}

linked_list_t *my_params_to_list(int ac, char const * const *av)
{
	linked_list_t *list;
	list = NULL;
	int count = 0;

	while(count < ac) {
		my_put_in_list(&list, (void *)av[count]);
		count++;
	}
	return (list);
}
