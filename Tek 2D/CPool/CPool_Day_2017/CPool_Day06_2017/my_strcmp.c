/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** 
*/
int my_strcmp(char const *s1, char const *s2) {
	int x = 0;
	while (s1[x] == s2[x])
			x++;
		if (s1[x] > s2[x])
		       return (1);
        if (s1[x] < s2[x])
		return (-1);
	return (0);
}
