/*
** EPITECH PROJECT, 2017
** infinit.c
** File description:
** make an infinit addition
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/bistro-matic.h"

char	*verify(char *str)
{
	int i = 0;
	int is_neg = 0;

	for (i = 0; str[i+1] != '\0' && (str[i] == '0' || str[i] == '-'); i++){
		if (str[i] == '-')
			is_neg = 1;
	}
	if (is_neg == 0)
		return &str[i];
	str[i - 1] = '-';
	return &str[i - 1];
}

int	chr_to_int(char c)
{
	if (c != 0)
		return (c - 48);
	return 0;
}

char	int_to_chr(int i)
{
	return (i + 48);
}

char	*sub(char *min, char *max)
{
	int i = 0;
	char *res = malloc(sizeof(char) * my_strlen(max) + 2);
	int retenu = 0;
	
	for (i = 0; min[i] != '\0'; i++){
		res[i] = int_to_chr((chr_to_int(max[i]) - chr_to_int(min[i])
					+ retenu) % 10);
		if (chr_to_int(max[i]) < (chr_to_int(min[i]) + retenu)){
			res[i] = int_to_chr((chr_to_int(max[i] + 10) - chr_to_int(min[i])
						+ retenu) % 10);
			retenu = 1;
		}
		else {
			res[i] = int_to_chr((chr_to_int(max[i]) - (chr_to_int(min[i])
						+ retenu)));
			retenu = 0;
		}
	}
	for (; max[i] != '\0'; i++) {
		if((chr_to_int(max[i]) + retenu) > 10){
			res[i] = int_to_chr((chr_to_int(max[i]) - retenu + 10) % 10);
			retenu = 1;
		}
		else {
			res[i] = int_to_chr((chr_to_int(max[i]) - retenu));
			retenu = 0;
		}
	}
	if (retenu == 1)
		res[i] = '1';
	res = my_revstr(res);
	return verify(res);
}

char	*add(char *min, char *max)
{
	int i = 0;
	char *res = malloc(sizeof(char) * my_strlen(max) + 2);
	int retenu = 0;

	for (i = 0; min[i] != '\0'; i++){
		res[i] = int_to_chr((chr_to_int(min[i]) + chr_to_int(max[i])
					+ retenu) % 10);
		retenu = (chr_to_int(min[i]) + chr_to_int(max[i]) + retenu) / 10;
	}
	for (; max[i] != '\0'; i++) {
		res[i] = int_to_chr((chr_to_int(max[i]) + retenu) % 10);
		retenu = (chr_to_int(max[i]) + retenu) / 10;
	}
	if (retenu == 1)
		res[i] = '1';
	res = my_revstr(res);
	return res;
}

char    *mult(char *min, char *max)
{
	int j = 0;
	int k = 0;
	char *res = malloc(sizeof(char) * my_strlen(max) + 2);
	int retenue = 0;
	int tmp = 0;
	
	for (int i = 0; min[i] != '\0'; i++) {
		for (j = 0; max[j] != '\0'; j++){
			tmp = chr_to_int(res[k]);
			res[k] = int_to_chr((chr_to_int(min[i]) * chr_to_int(max[j]) +
					     tmp + retenue) % 10);
			retenue = (chr_to_int(min[i]) * chr_to_int(max[j])
				   + tmp + retenue)/ 10;
			k++;
		}
		for (;max[j] != '\0'; j++) {
			res[k] = int_to_chr((chr_to_int(max[j]) + 
						chr_to_int(res[k]) + retenue) % 10);
			retenue = (chr_to_int(max[j]) + retenue) / 10;
		}
		if (retenue >= 1)
			res[k] = int_to_chr(chr_to_int(res[k]) + retenue);
		j = 0;
		k = i + 1;
		retenue = 0;
	}
	res = my_revstr(res);
	return (res);
}

char    *divis(char *max, char *min)
{
	int reste = 0;
	int retenue =  0;
	char *res = malloc(sizeof(char) * my_strlen(max) + 2);

	for (int i = 0; max[i] != '\0'; i++) {
			retenue = (reste * 10) + chr_to_int(max[i]);
			res[i] = int_to_chr(retenue / my_getnbr(min));
			reste = (retenue % my_getnbr(min));
	}
	return verify(res);
}

int	mod(char *max, char *min)
{
	int reste = 0;
	int retenue =  0;
	char *res = malloc(sizeof(char) * my_strlen(max) + 2);

	for (int i = 0; max[i] != '\0'; i++) {
			retenue = (reste * 10) + chr_to_int(max[i]);
			res[i] = int_to_chr(retenue / my_getnbr(min));
			reste = (retenue % my_getnbr(min));
	}
	return reste;
}


int	biggest(char *s1, char *s2)
{
	int res = 0;

	s1 = my_revstr(s1);
	s2 = my_revstr(s2);

	if (my_strlen(s1) > my_strlen(s1))
		res = 1;
	else if (my_strlen(s1) < my_strlen(s2))
		res = 2;
	else {
		if(my_strcmp(s1, s2) >= 0)
			res = 1;
		else
			res =  2;
	}
	s1 = my_revstr(s1);
	s2 = my_revstr(s2);
	return res;
}

int	infinit_add(char *s1, char *s2)
{
	char *min;
	char *max;

	s1 = verify(s1);
	s2 = verify(s2);
	if (my_strlen(s1) >= my_strlen(s2)) {
		max = my_revstr(my_strdup(s1));
		min = my_revstr(my_strdup(s2));
	}
	else {
		max = my_revstr(my_strdup(s2));
		min = my_revstr(my_strdup(s1));
	}
	if (min[my_strlen(min) - 1] == '-' && max[my_strlen(max) - 1] == '-') {
		min[my_strlen(min) - 1] = '\0';
		max[my_strlen(max) - 1] = '\0';
		return (my_getnbr(add(min, max)) * (-1));
	}
	else if (min[my_strlen(min) - 1] == '-'){
		min[my_strlen(min) - 1] = '\0';
		if (biggest(min, max) == 1)
			return (my_getnbr(sub(max, min)) * (-1));
		else
			return my_getnbr(sub(min, max));
	}
	else if (max[my_strlen(max) - 1] == '-'){
		max[my_strlen(max) - 1] = '\0';
		if (biggest(min, max) == 1)
			return my_getnbr(sub(max, min));
		else
			return (my_getnbr(sub(min, max)) * (-1));
	}
	else 
		return my_getnbr(add(min, max));
	return 0;
}

int	infinit_mult(char *s1, char *s2)
{
	char *min;
	char *max;

	s1 = verify(s1);
	s2 = verify(s2);
	if (my_strlen(s1) >= my_strlen(s2)) {
		max = my_revstr(my_strdup(s1));
		min = my_revstr(my_strdup(s2));
	}
	else {
		max = my_revstr(my_strdup(s2));
		min = my_revstr(my_strdup(s1));
	}
	if (min[my_strlen(min) - 1] == '-' && max[my_strlen(max) - 1] == '-') {
		min[my_strlen(min) - 1] = '\0';
		max[my_strlen(max) - 1] = '\0';
		return (my_getnbr(mult(min, max)));
	}
	else if (min[my_strlen(min) - 1] == '-'){
		min[my_strlen(min) - 1] = '\0';
		if (biggest(min, max) == 1)
			return (my_getnbr(mult(max, min)) * (-1));
		else
			return (my_getnbr(mult(min, max)) * (-1));
	}
	else if (max[my_strlen(max) - 1] == '-'){
		max[my_strlen(max) - 1] = '\0';
		if (biggest(min, max) == 1)
			return (my_getnbr(mult(max, min)) * (-1));
		else
			return (my_getnbr(mult(min, max)) * (-1));
	}
	else
		return (my_getnbr(mult(min, max)));
	return 0;
}

int	infinit_div(char *s1, char *s2)
{
	s1 = verify(s1);
	s2 = verify(s2);
	if (s2[0] == '0') {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_SYNTAX);
	}
	if (s1[0] == '-' && s2[0] == '-') {
		s1 = &s1[1];
		s2 = &s2[1];
		return (my_getnbr(divis(s1, s2)));
	}
	else if (s1[0] == '-') {
		//my_putchar('-');
		s1 = &s1[1];
		return (my_getnbr(divis(s1, s2)) * (-1));
	}	
	else if (s2[0] == '-') {
		//my_putchar('-');
		s2 = &s2[1];
		return (my_getnbr(divis(s1, s2)) * (-1));
	}
	else 
		return (my_getnbr(divis(s1, s2)));
}

int	infinit_mod(char *s1, char *s2)
{
	s1 = verify(s1);
	s2 = verify(s2);
	if (s2[0] == '0') {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (EXIT_SYNTAX);
	}
	if (s1[0] == '-' && s2[0] == '-') {
		s1 = &s1[1];
		s2 = &s2[1];
		return (mod(s1, s2));
	}
	else if (s1[0] == '-') {
		//my_putchar('-');
		s1 = &s1[1];
		return (mod(s1, s2) * (-1));
	}	
	else if (s2[0] == '-') {
		//my_putchar('-');
		s2 = &s2[1];
		return (mod(s1, s2) * (-1));
	}
	else 
		return (mod(s1, s2));
}
