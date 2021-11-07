/*
** EPITECH PROJECT, 2017
** infin_add.c
** File description:
** infin add
*/

#include <stdio.h>
#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

int error_detect(int argc, char **argv)
{
	if (argc != 3) {
		write(2, "Invalid number of arguments\n", 28);
		return (1);
	}
	return (0);
}

void  infadd(char *str1, char *str2)
{
	int result = 0;
	int retenu = 0;
	int x = 0;
	char *str = 0;
	int  end = 0;

	if (my_strlen(str1) > my_strlen(str2))
		end = my_strlen(str1);
	if (my_strlen(str1) <= my_strlen(str2))
		end = my_strlen(str2);
	str = malloc((end + 3) * sizeof(char));

	while (str1[x] != '\0' &&  str2[x] != '\0')
	{
		result = (str1[x] - 48) + (str2[x] - 48) + retenu;
		retenu = 0;
		if (result > 9)
		{
			retenu = 1;
			str[x] = ((result % 10) + 48);
		}
		else str[x] = result + 48;
		x++;
	}
	if (my_strlen(str1) == my_strlen(str2))
		str[x] = retenu + 48;
	while (str1[x] != '\0')
	{
		str[x] = str1[x] + retenu;
		x++;
		retenu = 0;
	}
	while (str2[x] != '\0' && x < my_strlen(str2))
	{
		str[x] = str2[x] + retenu;
		x++;
		retenu = 0;
	}
	str[x + 1] = '\0';
	my_revstr(str);
	x = 0;
	while (str[x] == '0')
		x++;
	my_putstr(str + x);
	my_putchar('\n');
}

int main(int argc,char **argv)
{
	char *str1, *str2;
	if (error_detect(argc, argv))
		return (84);
        else (infadd(my_revstr(argv[1]), my_revstr(argv[2])));
		return (0);
}
