/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main ex00
*/

#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	int i;
	char str;

	std::fstream file;
	std::string line;
	if (argc == 1)
		std::cout << "my_cat: Usage: " << argv[0]
			  << " file [...]" << std::endl;
	for (i = 1; i < argc; i++) {
		file.open(argv[i], std::ios::in);
		if (file) {
			char line[100];
			int readed;
			while ((readed = file.readsome(line, 100)) != 0)
				std::cout.write(line, readed);
			file.close();
		}
		else
			std::cerr << "my_cat: <" << argv[i] <<
				">: No such file or directory" << std::endl;
	}
	return (0);
}
