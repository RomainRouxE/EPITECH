/*
** EPITECH PROJECT, 2017
** concat_params
** File description:
** task 2
*/
#include <stdlib.h>
#include <stdio.h>
int my_strlen(char const *str);
char *my_strcat(char *, char const *);
char *concat_params(int argc, char **argv)
{
        int x = 0;
        int y = 0;
        char *str;
	while (x < argc) {
		y = y + my_strlen(argv[x]);
		x++;
	}
	str = malloc(sizeof(char) * (y + argc + 1));
	if (str == NULL)
		return NULL;
	*str = '\0';
	x = 0;
	while(x < argc) {
		my_strcat(str, argv[x]);
		if (x < argc - 1)
			my_strcat(str, "\n");
		x++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	char *s = concat_params(argc, argv);
	printf("%s\n", s);
	if (s != NULL)
		free(s);
	return (0);
}
