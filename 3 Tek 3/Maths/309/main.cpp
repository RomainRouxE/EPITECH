#include "309pollution.hpp"

static void error()
{
	cerr << "Error" << endl;
	exit(84);
}

static void usage()
{
	cout << "USAGE" << endl;
	cout << "\t./309pollution n file x y" << endl;
	cout << "DESCRIPTION" << endl;
	cout << "\tn\tnumber of points on the grid axis" << endl;
	cout << "\tfile\tcsv file containing the data points x;y;p" << endl;
	cout << "\tx\tabscissa of the point whose pollution level we want to know" << endl;
	cout << "\ty\tordinate of the point whose pollution level we want to know" << endl;
}

bool is_num(string& s)
{
	int i = 0;
	int a = 0;
	string::const_iterator num = s.begin();

	while (num != s.end()) {
		if (isdigit(*num) || *num == '.' || *num == '-') {
			if (*num == '.')
				i++;
			if (*num == '-')
				a++;
		}
		else
			error();
		if (i > 1 || a > 1)
			error();
		num++;
	}
	return (true);
}

void check(int ac, char **av)
{
	if (string("-h") == av[1])
		usage();
	if (ac != 5 || ac == NULL)
		error();

	ifstream ifs;
	ifs.open (av[2]);
	if (!ifs)
		error();
	ifs.close();

	string a = av[1];
	string b = av[3];
	string c = av[4];

	if (!is_num(a) || !is_num(b) || !is_num(c))
		error();

	int n = atoi(av[1]);
	int x = atoi(av[3]);
	int y = atoi(av[4]);

}

int main(int ac, char **av)
{
	if (ac == 2 and strcmp(av[1], "-h") == 0)
		usage();

	check(ac, av);

}
