/*
** EPITECH PROJECT, 2017
** my_print_comb.c
** File description:
** 
*/
void my_putchar(char a);
int my_print_comb(void)
{
        int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	
	while (x <= 9) {
		while (y <= 9) {
			while (z <= 9) {
				if ((z > y) && (y > x)) {
					my_putchar(x + 48);
					my_putchar(y + 48);
					my_putchar(z + 48);
					if (!((x == 7) && (y == 8) && (z == 9))) {
						my_putchar(',');
						my_putchar(' ');
					}
				}
				z++;	
			}
			y++;
			z = 0;
		}
		x++;
		y = 0;
	}
	return (0);
}
