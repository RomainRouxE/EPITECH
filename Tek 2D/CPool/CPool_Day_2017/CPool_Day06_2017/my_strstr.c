/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** 
*/
char	*my_strstr(char const *str, char const *to_find)
{
	int	x = 0;
	int	y = 0;
	for (int	z = 0; str[z] != '\0'; z++) {
		if (str[z] == to_find[x]) {
			y = z;
			for (x = 0; to_find[x] != '\0' && str[z] == to_find[x]; x++) {
				if (to_find[x + 1] == '\0')
					return (char *) (&str[y]);
				else
					z++;
			}
			x = 0;
			z = y + 1;
		}
	}
	return (0);
}
