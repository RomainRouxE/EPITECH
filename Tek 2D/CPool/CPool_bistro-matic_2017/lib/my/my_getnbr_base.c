/*
** EPITECH PROJECT, 2017
** my_getnbr_base.c
** File description:
** get the number in decimal number
*/

int	my_compute_power_rec(int nb, int p);
int	my_strlen(char *str);

int	my_getnbr_base(char const *str, char const *base)
{
	int len = my_strlen((char *)base);
	int p = my_strlen((char *)str) - 1;
	int j = 0;
	int res = 0;
	int i = 0;
	int is_neg = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			is_neg++;
		i++;
		p--;
	}
	while (str[i] != '\0') {
		for (j = 0; str[i] != base[j]; j++){}
		res += j * my_compute_power_rec(len, p);
		p--;
		i++;
	}
	if (is_neg % 2 == 1)
		res *= - 1;
	return (res);
}
