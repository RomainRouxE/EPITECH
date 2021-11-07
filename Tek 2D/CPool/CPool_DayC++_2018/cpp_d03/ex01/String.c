/*
** EPITECH PROJECT, 2018
** String.c
** File description:
** String.c
*/

#include "String.h"

static void assign_s(String *this, String const *str)
{
	if ((str != NULL) && (this != NULL)) {
		StringDestroy(this);
		this->str = strdup(str->str);
	}
}

static void assign_c(String *this, char const *str)
{
	if (str && this) {
		StringDestroy(this);
		this->str = strdup(str);
	}
}

void StringInit(String *this, char const *s)
{
	if (this) {
		this->str = strdup(s);
		this->assign_s = &assign_s;
		this->assign_c = &assign_c;
	}
}

void StringDestroy(String *this)
{
	if (this && this->str)
		free(this->str);
}
