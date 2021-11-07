/*
** EPITECH PROJECT, 2018
** String.c
** File description:
** String.c
*/

#include "String.h"

void StringInit(String *this, const char *s)
{
	if (this && s)
		this->str = strdup(s);
}

void StringDestroy(String *this)
{
	if (this && this->str)
		free(this->str);
}
