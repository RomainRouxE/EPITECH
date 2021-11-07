/*
** EPITECH PROJECT, 2018
** print_data.c
** File description:
** print_data.c
*/

#include "objdump.h"

void print_hexa(uint8_t const *const data, int const size)
{
	register int i = -1;

	while (++i < 16) {
		if (i < size)
			printf("%02x", data[i]);
		else
			printf("  ");
		if (!((i + 1) % 4))
			printf(" ");
	}
	printf(" ");
}

void print_ascii(uint8_t const *const data, int const size)
{
	register int i = -1;

	while (++i < 16) {
		if (i < size)
			printf("%c", IS_PRINTABLE(data[i]) ? data[i] : '.');
		else
			printf(" ");
	}
	printf("\n");
}

void print_data(t_elf *const elf, int const i, int const j)
{
	printf(" %04x ",
	       (int)(elf->shdr[i].sh_addr + j - elf->shdr[i].sh_offset));
	print_hexa((unsigned char *)elf->ehdr + j,
		   elf->shdr[i].sh_offset + elf->shdr[i].sh_size - j);
	print_ascii((unsigned char *)elf->ehdr + j,
		    elf->shdr[i].sh_offset + elf->shdr[i].sh_size - j);
}

int write_data(t_elf *const elf)
{
	int i = -1;
	int j;

	while (++i < elf->ehdr->e_shnum) {
		if ((void *)&elf->shdr[i] > elf->end
		    || (void *)&elf->strtab[elf->shdr[i].sh_name] > elf->end)
			return (fprintf(stderr, "Error : invalid file\n") && 0);
		if (((elf->shdr[i].sh_type == SHT_SYMTAB
		      || elf->shdr[i].sh_type == SHT_NOBITS
		      || elf->shdr[i].sh_type == SHT_STRTAB)
		     && strcmp(&elf->strtab[elf->shdr[i].sh_name], ".dynstr"))
		    || !elf->shdr[i].sh_size)
			continue ;
		printf("Contents of section %s:\n", &elf->strtab[elf->shdr[i].sh_name]);
		j = elf->shdr[i].sh_offset;
		while ((unsigned)j < elf->shdr[i].sh_offset + elf->shdr[i].sh_size) {
			print_data(elf, i, j);
			j += 16;
		}
	}
	return (1);
}
