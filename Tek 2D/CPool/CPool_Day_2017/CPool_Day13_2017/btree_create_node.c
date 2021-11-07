/*
** EPITECH PROJECT, 2017
** btree_create_node.c
** File description:
** btree create node
*/

#include "./include/btree.h"
#include <stdlib.h>

btree_t *btree_create_node(void *item)
{
	btree_t *bt = malloc(sizeof(btree_t*));
	bt->item = item;
	bt->left = NULL;
	bt->right = NULL;
	return (bt);
}
