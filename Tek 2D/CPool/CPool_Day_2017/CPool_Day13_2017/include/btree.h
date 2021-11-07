/*
** EPITECH PROJECT, 2017
** btree.h
** File description:
** btree
*/

#ifndef MY_BTREE
#define MY_BTREE

typedef struct btree
{
	struct btree *left;
	struct btree *right;
	void *item;
} btree_t;

#endif
