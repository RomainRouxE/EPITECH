/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** tools
*/

#include "server.h"

bool prefix(const char *pre, const char *str)
{
	return strncmp(pre, str, strlen(pre)) == 0;
}
