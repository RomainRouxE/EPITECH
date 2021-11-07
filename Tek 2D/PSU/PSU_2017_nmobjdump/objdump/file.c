/*
** EPITECH PROJECT, 2018
** file.c
** File description:
** file.c
*/

#include "objdump.h"

static int check_file(t_elf *const elf)
{
	if (elf->len < sizeof(Elf64_Ehdr)
	    || memcmp(elf->ehdr, MAGIC_NUMBER, sizeof(MAGIC_NUMBER) - 1)) {
		fprintf(stderr, "File format not recognized\n");
		return (0);
	}
	if ((void *)(elf->shdr = ((void *)elf->ehdr + elf->ehdr->e_shoff)) > elf->end
	    || (void *)&elf->shdr[elf->ehdr->e_shstrndx] > elf->end
	    || (void *)(STRTAB) > elf->end)
		return (fprintf(stderr, "Error : invalid file\n") && 0);
	elf->strtab = (char *)(STRTAB);
	return (1);
}

int parse_file(char const *const file, t_elf *const elf)
{
	int fd;

	elf->file_name = file;
	if ((fd = open(file, O_RDONLY)) == -1) {
		printf("objdump: \'%s\': No such file\n", file);
		return (0);
	}
	if ((elf->len = lseek(fd, 0, SEEK_END)) == (unsigned)-1) {
		perror("lseek");
		return (0);
	}
	if (!(elf->ehdr = mmap(NULL, elf->len, PROT_READ, MAP_SHARED, fd, 0))) {
		perror("mmap");
		return (0);
	}
	elf->end = (void *)elf->ehdr + elf->len;
	return (check_file(elf));
}
