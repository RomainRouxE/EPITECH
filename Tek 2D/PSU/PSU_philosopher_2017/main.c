/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "extern.h"
#include "philosopher.h"

int clean(philo_t *philo)
{
	if (pthread_mutex_destroy(&philo->mutex) != 0)
		fprintf(stderr, "ERROR: Failed to destroy a mutex\n");
	free(philo);
	return (0);
}

int init(philo_t *philo)
{
	pthread_t threads[philo->val->nb_philo];
	int i = -1;

	(void)threads;
	while (++i != philo->val->nb_philo) {
		if (pthread_create(&threads[i], NULL, &state, &philo[i])) {
			fprintf(stderr, "ERROR: Thread creation failed\n");
			return (-1);
		}
	}
	i = -1;
	while (++i != philo->val->nb_philo)
		pthread_join(threads[i], NULL);
	clean(philo);
	return (0);
}

int fill_tab(values_t *values)
{
	philo_t	*philo;
	int i = -1;

	if (values->nb_philo < 2) {
		fprintf(stderr, "ERROR: insufisant number of philosopher\n");
		return (1);
	}
	if ((philo = malloc(sizeof(philo_t) * values->nb_philo)) == NULL)
		return (1);
	philo->val = values;
	while (++i != values->nb_philo) {
		philo[i].id = i;
		if (rand() % 2 == 0)
			philo[i].state = 0;
		else
			philo[i].state = 2;
		philo[i].rice = values->rice;
		philo[i].hand = &philo[i + 1];
		philo[i].mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	}
	philo[values->nb_philo - 1].hand = &philo[0];
	return (init(philo));
}

int check(values_t *value, int ac, char **av)
{
	int i = 0;

	while (++i != ac) {
		if (strcmp(av[i], "-p") == 0) {
			if ((value->nb_philo = is_num(av[++i])) == -1)
				return (fprintf(stderr, "Error: argument -p is invalid\n"));
		}
		else if (strcmp(av[i], "-e") == 0) {
			if ((value->rice = is_num(av[++i])) == -1)
				return (fprintf(stderr, "Error: argument -e is invalid\n"));
		}
		else
			return (fprintf(stderr, "USAGE: ./philo -p [nbr] -e [nbr]\n"));
	}
	return (1);
}

int main(int ac, char **av)
{
	values_t value;

	if (ac != 5)
		return (fprintf(stderr, "USAGE: ./philo -p [nbr] -e [nbr]\n"));
	if (check(&value, ac, av) != 1)
		return (0);
	RCFStartup(ac, av);
	if (fill_tab(&value) == 1)
		return (0);
	RCFCleanup();
	return (0);
}
