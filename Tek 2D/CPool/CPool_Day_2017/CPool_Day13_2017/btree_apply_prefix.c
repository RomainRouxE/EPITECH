/*
** EPITECH PROJECT, 2017
** btree_apply_prefix.c
** File description:
** btree aply prefix
*/

#include "./include/btree.h"
#include <stdlib.h>

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
	if(root == NULL)
		return;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
