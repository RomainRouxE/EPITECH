/*
** EPITECH PROJECT, 2018
** func_ptr.C
** File description:
** func_ptr.c
*/

#include "func_ptr.h"

void print_normal(char *str)
{
	printf("%s\n", str);
}

void print_reverse(char *str)
{
	char *x = strdup(str);
	int len = strlen(x);
	int i = 0;

	if (x) {
		while (i < len / 2) {
			x[i] = str[len - i - 1];
			x[len - i - 1] = str[i];
			i++;
		}
	}
	print_normal(x);
	free(x);
}

void print_upper(char *str)
{
	char *x = strdup(str);
	int len = strlen(x);
	int i = 0;

	if (x) {
		while (i < len) {
			x[i] = toupper(x[i]);
			i++;
		}
	}
	print_normal(x);
	free(x);
}

void print_42(char *str)
{
	char *save = str;

	str = save;
	print_normal("42");
}

void do_action(action_t action, char *str)
{
	t_action_func list[] = {
		{PRINT_NORMAL, &print_normal},
		{PRINT_REVERSE, &print_reverse},
		{PRINT_UPPER, &print_upper},
		{PRINT_42, &print_42},
	};
	int i = 0;

	while (i < 4) {
		if (action == list[i].action) {
			(*list[i].func)(str);
			return;
		}
		i++;
	}
}
