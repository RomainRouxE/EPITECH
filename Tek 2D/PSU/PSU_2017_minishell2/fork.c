/*
** EPITECH PROJECT, 2017
** fork.c
** File description:
** fork minishell1
*/

#include "struct.h"

int builtin(char **arg, char **env, t_sh *sb)
{
	if (my_strcmp(arg[0], "env") == 0)
		my_aff_env(env);
	else if (my_strcmp(arg[0], "cd") == 0)
		my_cd(arg);
	else if (my_strcmp(arg[0], "exit") == 0)
		my_exit(sb);
	else if (my_strcmp(arg[0], "unsetenv") == 0)
		my_unsetenv(sb, arg);
	else
		return (1);
	return (0);
}

void my_execute(t_sh *sb, char **user_command, char **env)
{
	int i = 0;
	char *str;

	while (sb->path[i]) {
		str = strcat(sb->path[i], "/");
		str = strcat(str, user_command[0]);
		execve(str, user_command, env);
		i++;
	}
	my_putstr("Command not found\n");
	exit (1);
}

void execute(char **user_command, char **env, t_sh *sb)
{
	pid_t pid;
	int i;
	int status;
	char *str;
	int n;

	n = builtin(user_command, env, sb);
	if (n != 0) {
		pid = fork();
		if (pid == -1) {
			my_putstr("Error during fork\n");
			exit(-1);
		}
		if (pid == 0)
			my_execute(sb, user_command, env);
		else
			wait(&status);
	}
}

int recup(t_sh *sb, char **env)
{
	char **user_command;
	int ret;

	clean_buffer(sb->buff);
	sb->buff[ret - 1] = '\0';
	my_putstr(">");
	while (ret = read(0, sb->buff, 4096)) {
		sb->buff[ret - 1] = 0;
		user_command = my_str_to_wordtab(sb->buff, ' ');
		if (my_strlen(sb->buff) != 0)
			execute(user_command, env, sb);
		clean_buffer(sb->buff);
		my_putstr(">");
	}
}

void clean_buffer(char *buff)
{
	int i = 0;

	while (buff[i]) {
		buff[i] = 0;
		i++;
	}
}
