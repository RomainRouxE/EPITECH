/*
** EPITECH PROJECT, 2017
** built.c
** File description:
** built minishell1
*/

#include "struct.h"

int my_unsetenv(t_sh *sb, char **arg)
{
	int i = 0;

	if (arg[1] == NULL)
		return (-1);
	while (sb->en[i]) {
		if (my_strcmp(sb->en[i], arg[1]) == 0) {
			i += 1;
			while (sb->en[i]) {
				sb->en[i - 1] = sb->en[i];
				i++;
			}
			sb->en[i - 1] = NULL;
			return (1);
		}
		i++;
	}
}

void my_cd(char **arg)
{
	(arg[1] == NULL) ? chdir("/home/") : 0;
	if ((chdir(arg[1])) == -1 && arg[1]) {
		my_putstr("bash: cd: ");
		my_putstr(arg[1]);
		my_putstr(": No such file or directory\n");
	}
	else
		chdir(arg[1]);
}

void my_exit(t_sh *sb)
{
	exit(1);
}

void my_aff_env(char **env)
{
	int i = 0;

	while (env[i]) {
		my_putstr(env[i]);
		my_putchar('\n');
		i++;
	}
}
