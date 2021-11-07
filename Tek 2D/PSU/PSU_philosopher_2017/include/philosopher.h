/*
** EPITECH PROJECT, 2018
** philosopher.h
** File description:
** philosopher.h
*/

#ifndef PHILOSOPHE_H_
#define PHILOSOPHE_H_

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef struct s_values
{
	int nb_philo;
	int rice;
} values_t;

typedef struct s_philo
{
	int rice;
	int state;
	int id;
	struct s_philo *hand;
	pthread_mutex_t mutex;
	values_t *val;
} philo_t;

void *state(void *arg);
void rest(philo_t *philo);
int is_num(char *str);
void action(philo_t *philo);

#endif
