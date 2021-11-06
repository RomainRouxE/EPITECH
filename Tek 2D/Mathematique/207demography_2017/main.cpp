//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main.cpp
//

#include "207demographie.hpp"

using namespace std;

static bool is_cap(char *str)
{
        int i = 0;

        while (str[i]) {
	        if (str[i] < 'A' || str[i] > 'Z' || i > 2)
                        return (false);
		else
                        i++;
        }
	if (i <= 2)
                return (false);
        return (true);
}

static void usage(char **av)
{
        cout << "USAGE" << std::endl;
        cout << "\t   " << av[0] << " code1 [...]" << std::endl;
        cout << std::endl;
        cout << "DESCRIPTION" << std::endl;
        cout << "\t   code1 country code" << std::endl;
	exit(0);
}

static void error()
{
        std::cerr << "Bad argument" << std::endl;
	exit(84);
}

int main(int argc, char **argv, char **envp)
{
	int x;
	
	if (argv[1] == NULL)
                error();
        if (string("-h") == argv[1])
                usage(argv);
        for (x = 1; x != argc; x++) {
                if (is_cap(argv[x]) == false)
                        error();
        }
        Core core;

	core.init(argc, argv, envp);
	core.run();
        return 0;
}
