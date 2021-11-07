/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** displays number
*/

const int INT_MIN = -2147483648;

void my_putchar(char c);

void print_min(void)
{
	my_putchar('-');
	my_putchar('2');
	my_putchar('1');
	my_putchar('4');
	my_putchar('7');
	my_putchar('4');
	my_putchar('8');
	my_putchar('3');
	my_putchar('6');
	my_putchar('4');
	my_putchar('8');
}

void print_rightmost(int nb)
{
	int num = nb;
	if (nb > 9) {
		nb /= 10;
		num -= nb * 10;
	}
	my_putchar(num + 48);
}

void loop (int nb)
{
	if (nb > 0) {
		loop (nb / 10);
		print_rightmost(nb);
	}
}

int my_put_nbr(int nb)
{
	if (nb == INT_MIN) {
		print_min();
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	} else if (nb == 0) {
		my_putchar('0');
		return (0);
	}
	loop(nb);
	return (0);
}
