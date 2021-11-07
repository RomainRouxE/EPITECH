/*
** EPITECH PROJECT, 2018
** my_malloc.h
** File description:
** my_malloc.h
*/

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void show_alloc_mem(void) ;

#define BLOC 131072

static size_t start = 0;

typedef struct __attribute__((packed)) s_head
{
	int free;
	struct s_head *next;
	size_t size;
	void *ptr;
	unsigned char is_free;
} head_t;

#endif
