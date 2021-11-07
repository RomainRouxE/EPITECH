/*
** EPITECH PROJECT, 2017
** btree_apply_suffix.c
** File description:
** btree apply suffix
*/

#include "./include/btree.h"
#include <stdlib.h>

void btree_apply_infix(btree_t *root, int (*applyf)(void *))
{
 	if(root == NULL)
		return;
	btree_apply_infix(root->left, applyf);
        btree_apply_infix(root->right, applyf);
	applyf(root->item);
}
