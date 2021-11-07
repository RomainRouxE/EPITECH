/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main minishell1
*/

#include "struct.h"

int my_env_len(char **env)
{
	int i = 0;

	while (env[i])
		i++;
	return (i++);
}

int full_env(t_sh *sb, char **env)
{
	int i = 0;
	int n = my_env_len(env);

	if ((sb->en = malloc(n * sizeof(char*))) == NULL) {
		my_putstr("Malloc failed\n");
		exit(-1);
	}
	while (env[i]) {
		sb->en[i] = my_strdup(env[i]);
		i++;
	}
	sb->en[i + 1] = 0;
}

void my_getpath(t_sh *sb)
{
	int i = 0;

	while (my_strncmp(sb->en[i], "PATH=", 5) != 0)
		i++;
	sb->path = my_str_to_wordtab(sb->en[i], ':');
}

void handle_signal(int signal)
{
	my_putstr("\n");
}

int main(int ac, char **av, char **env)
{
	t_sh sb;

	signal(SIGINT, handle_signal);
	if ((sb.buff = malloc(sizeof(char) * 4096)) == NULL)
		return (0);
	if (*env) {
		full_env(&sb, env);
		my_getpath(&sb);
		sb.path[0] = &sb.path[0][5];
		recup(&sb, env);
	}
	return (0);
}
