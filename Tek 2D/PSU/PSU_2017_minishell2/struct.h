/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct.h
*/

#ifndef MY_SH__
#define MY_SH__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct  s_sh
{
  char **en;
  char **path;
  char *buff;
}               t_sh;

char *my_strdup(char *);
char *my_nstrdup(char *);
void *xmalloc(unsigned int);
char **my_str_to_wordtab(char *, char);
void clean_buffer(char *buff);
char *my_search(t_sh *sb, char *command);
int my_unsetenv(t_sh *sb, char **arg);
void my_cd(char **arg);
void my_exit(t_sh *sb);
void my_aff_env(char **env);
int builtin(char **arg, char **env, t_sh *sb);
void my_execute(t_sh *sb, char **user_command, char **env);
void execute(char **user_command, char **env, t_sh *sb);
int recup(t_sh *sb, char **env);
int count_words(char *str, char separator);
char *my_put_in_tab(char *str, int *i, char separator);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcocat(char *str1, char *str2);
void my_putstr(char *str);
int my_strlen(char *str);
void my_putchar(char c);

#endif
