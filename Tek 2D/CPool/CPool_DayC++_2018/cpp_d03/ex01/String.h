/*
** EPITECH PROJECT, 2018
** String.h
** File description:
** String.h
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include <string.h>

typedef struct String
{
	char *str;
	void (*assign_s)(struct String *this, struct String const *str);
	void (*assign_c)(struct String *this, char const *str);
} String;

void StringDestroy(String *this);
void StringInit(String *this, char const *s);

#endif
