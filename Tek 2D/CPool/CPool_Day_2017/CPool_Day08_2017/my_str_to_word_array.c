/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** task04
*/

int	check_isalnum(char);
char	*get_word_from_str(int*, char const *);
int	count_words(char const *);

char	**my_str_to_word_array(char const *str)
{
	int	i = 0, j = 0, words = count_words(str);
	char	**warray;

	warray = malloc(sizeof(char*) * (words + 1));
	for (i = 0; str[i] != '\0'; i++) {
		if (check_isalnum(str[i])) {
			warray[j] = get_word_from_str(&i, str);
			j++;
		}
	}
	warray[words] = 0;
	return (warray);
}

int	check_isalnum(char c)
{
	int	isupper = (c >= 'A' && c <= 'Z');
	int	islower = (c >= 'a' && c <= 'z');
	int	isnum = (c >= '0' && c <= '9');

	return (isupper || islower || isnum);
}

int	count_words(char const *str)
{
	int	nwords = 0, i;

	for (i = 0; str[i] != '\0'; i++) {
		if (check_isalnum(str[i]) && !check_isalnum(str[i + 1]))
			nwords++;
	}
	return (nwords);
}

char	*get_word_from_str(int *i, char const *str)
{
	int j = *i, length;
	char	*dynamic_point = NULL;

	while (check_isalnum(str[j]))
		j++;
	length = j - *i;
	dynamic_point = malloc(sizeof(char) * (length + 1));
	for (j = 0; j < length; j++) {
		dynamic_point[j] = str[*i];
		*i = *i + 1;
	}
	dynamic_point[length] = '\0';
	return (dynamic_point);
}
