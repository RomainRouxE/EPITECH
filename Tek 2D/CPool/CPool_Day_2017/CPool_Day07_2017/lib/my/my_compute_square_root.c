int	my_compute_square_root(int nb) {
        int x=1;
        while ((x*x) < nb) {
                x++;
        }

        if ((x*x) == nb)
                return (x);
        return (0);
}
