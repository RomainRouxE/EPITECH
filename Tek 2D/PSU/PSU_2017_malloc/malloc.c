/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "malloc.h"

void show_alloc_mem(void)
{
	head_t *header;

	printf("break : %p\n", sbrk(0));
	header = (head_t *)start;
	while (header) {
		printf("%p - %p : %lu bytes\n",
		       (void *)(header + sizeof(head_t)),
		       (void *)(header + sizeof(head_t) + header->size),
		       header->size);
		header = header->next;
	}
}

static void *alloc(head_t *x, size_t size)
{
	head_t *y;

	if (x->size > size + sizeof(head_t)) {
		y = (head_t *)((size_t)(x) + sizeof(head_t) + size);
		y->size = x->size - (sizeof(head_t) + size);
		y->is_free = 1;
		y->next = x->next;
		x->next = y;
		x->size = size;
	}
	x->is_free = 0;
	return ((void *)((size_t)x + sizeof(head_t)));
}

void *malloc(size_t size)
{
	head_t *x;
	head_t *prev;

	if (!size)
		return (NULL);
	x = (head_t *)start;
	prev = NULL;
	while (x) {
		if (x->is_free && x->size >= size)
			return (alloc(x, size));
		prev = x;
		x = x->next;
	}
	if (!start)
		start = (size_t)(sbrk(0));
	if (!(x = sbrk(((size_t)((size + sizeof(head_t))
				 / BLOC) + 1) * BLOC)))
		return (NULL);
	x->size = ((size_t)((size + sizeof(head_t)) / BLOC) + 1) * BLOC	- sizeof(head_t);
	x->next = NULL;
	if (prev)
		prev->next = x;
	return (alloc(x, size));
}

void free(void *ptr)
{
	head_t *header;

	header = (head_t *) start;
	while (header && header->ptr != ptr)
		header = header->next;
	if (header == NULL)
		ptr = NULL;
	else if (header->ptr == ptr) {
		ptr = memset(ptr, 0, header->size);
		header->free = 1;
	}
	else
		ptr = NULL;
}

void *realloc(void *ptr, size_t size)
{
	void *tmp;
	head_t *header;

	tmp = NULL;       
	header = (head_t *)start;
	if (header == NULL)
		return (NULL);
	while (header) {
		if (ptr == (void *)(header) + (sizeof(head_t)))
	                break;
		header = header->next;
	}
	if (ptr && !(header = malloc(size)))
		return (NULL);
	else if (!(tmp = malloc(size)))
		return (NULL);
	if (ptr)
		free(ptr);
	return (tmp);
}

void *calloc(size_t n, size_t size)
{
	void *ptr;

	if ((ptr = malloc(n * size)) == NULL)
		return (NULL);
	else
		memset(ptr, 0, n * size);
	return (ptr);
}
