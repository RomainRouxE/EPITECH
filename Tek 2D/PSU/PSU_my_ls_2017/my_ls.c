/*
** EPITECH PROJECT, 2017
** my_ls.c
** File description:
** my_ls
*/

#include "my_ls.h"

int set_present(t_par *tpar, char x)
{
	int i = 0;
	int pres = 0;

	while (i < SIZE_ARG) {
		if (tpar->targ[i].c == x) {
			tpar->targ[i].ispresent = 1;
			pres = 1;
		}
		i += 1;
	}
	if (pres == 0)
		return (1);
	return (0);
}

int fill_dir_arg(t_par *tpar, char *str)
{
	int i;

	if (str[0] == '-') {
		i = 1;
		while (str[i])
			if (set_present(tpar, str[i++]) == 1) {
				my_putstr_err("my_ls: invalid option -- '");
				my_putchar_err(str[i - 1]);
				my_putstr_err("'\n");
				return (1);
			}
	}
	else
		if (add_dir_to_end_list(tpar, str) == 1)
			return (2);
	return (0);
}

void conf_arg(t_par *tpar, char *param)
{
	int i = -1;

	tpar->tdir->path = my_strdup("root");
	tpar->tdir->root = '1';
	tpar->tdir->next = tpar->tdir;
	tpar->tdir->prev = tpar->tdir;
	tpar->nbpath = 0;
	while (param[++i]) {
		tpar->targ[i].c = param[i];
		tpar->targ[i].ispresent = 0;
	}
}

int fill_args(int ac, char **av, t_par *tpar)
{
	int i = 0;

	conf_arg(tpar, ARGS);
	if (ac > 1)
		while (++i < ac)
			if (fill_dir_arg(tpar, av[i]) > 0)
				return (1);
	if (tpar->nbpath == 0) {
		if (fill_dir_arg(tpar, ".") > 0)
			return (1);
		tpar->nbpath = 1;
	}
	if (tpar->nbpath > 1)
		my_ls_tri(tpar->tdir);
	return (0);
}

int main(int ac, char **av)
{
	t_par tpar;

	if ((tpar.tdir = malloc(sizeof(t_dir))) == NULL)
		return (1);
	if (fill_args(ac, av, &tpar) > 0)
		return (1);
	launch_ls(&tpar);
	free_t_dir_main(tpar.tdir);
	return (0);
}
