/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** 
*/

int my_strncmp(char const *s1, char const *s2, int n) {
	int x = 0;
		while (s1[x] == s2[x] && x < n && s1[x] != '\0')
			x++;
		if (s1[x] > s2[x])
		       return (1);

        if (s1[x] < s2[x])
		return (-1);
	return (0);
}
