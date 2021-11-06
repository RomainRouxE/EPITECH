/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int nb;
	int i;
	struct s_list *next;
} t_list;

void fill(t_list **l, int nb);
t_list *fill_one(t_list **l, int nb);
void pushswap(t_list *la, t_list *lb, int v);
int is_order(t_list *l);
int minimal(int bkp, t_list *l);
t_list *pb(t_list *la, t_list **lb);
t_list *pa(t_list *lb, t_list **la, int v);
void *ra(t_list *la);
int my_atoi(const char *str);
int my_strcmp(const char *s1, const char *s2);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);

#endif
