/*
** EPITECH PROJECT, 2017
** match.c
** File description:
** task1
*/

int match(char const *s1, char const *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	while(*s1 != '\0' || *s2 != '\0')
		{
			if (*s1 != *s2)
			{
				return (0);
			}
			if (*s1  == '\0' || *s2 == '\0')
			{
				return (0);
			}
			else if (*s1 == *s2 || *s2 == '*')
			{
				*s1++;
				*s2++;
			}
			//else if (*s2 == '*')
			//	*s1=;
		}
	return (1);
}
