/*
** EPITECH PROJECT, 2017
** my_print_comb2.c
** File description:
** 
*/
int my_putchar(char c);
int my_print_comb2(void)
{
	int x;
        int y;
        int z;
	int i;

        x = 0;
        y = 0;
        z = 0;
	i = 1;

        while (x <= 9) {
         	while (y <= 9) {
                        while (z <= 9) {
				while (i <= 9) {
					if (i > y) {
						my_putchar(x + 48);
						my_putchar(y + 48);
						my_putchar(' ');
						my_putchar(z + 48);
						my_putchar(i + 48);
						
						if (!((y == 8) && (z == 9) && (i == 9))) {
							my_putchar(',');
							my_putchar(' ');
						}
					}
					i++;
				}
                                z++;
				i = 0;
			}
                        y++;
                        z = 0;
		}
                x++;
		y = 0;
	}
	return(0);
}
