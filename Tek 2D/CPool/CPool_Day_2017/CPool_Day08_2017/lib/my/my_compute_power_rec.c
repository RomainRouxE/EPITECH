int my_compute_power_rec(int nb, int p)
{
	int x=nb;
	if (p == 0 || nb == 1)
		return (1);
	else if (p < 0 || p > 30 || nb == 2147483648)
		return (0);
	else if (p > 1)
		x = my_compute_power_rec(nb, p-1)*nb;
	return (x);
}
