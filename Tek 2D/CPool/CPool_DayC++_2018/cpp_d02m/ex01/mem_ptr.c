/*
** EPITECH PROJECT, 2018
** mem_ptr.c
** File description:
** mem_ptr.c
*/

#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if (len1 || len2) {
		*res = malloc(len1 + len2 + 1);
		memset(*res, 0,len1 + len2 + 1);
		strcpy(*res, str1);
		strcat(*res, str2);
	}
	else
		*res = NULL;
}

void add_str_struct(str_op_t  *str_op)
{
	add_str(str_op->str1, str_op->str2, &str_op->res);
}
