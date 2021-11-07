/*
 ** EPITECH PROJECT, 2017
 ** my_strstr.c
 ** File description:
 ** return the first same occurence
 */

char	*my_strstr(char const *str, char const *to_find)
{
	int i = 0;
	int res = 0;

	for (int j = 0; str[j] != '\0'; j++) {
		if (str[j] == to_find[i]) {
			res = j;
			for (i = 0; to_find[i] != '\0' && str[j] == to_find[i]; i++) {
				if (to_find[i + 1] == '\0')
					return (char *)(&str[res]);
				else
					j++;
			}
			i = 0;
			j = res;
		}
	}
	return (0);
}
