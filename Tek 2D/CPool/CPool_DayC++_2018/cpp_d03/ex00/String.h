/*
** EPITECH PROJECT, 2018
** String.h
** File description:
** String.h
*/

#ifndef STRING_H_
#define STRING_H_

#include <string.h>
#include <stdlib.h>

typedef struct String
{
	char *str;
} String;

void StringInit(String *this, const char *s);
void StringDestroy(String *this);

#endif
