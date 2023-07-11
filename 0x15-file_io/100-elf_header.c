#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * close_a_file - Close a file
 * @file: ELF file.
 * Return: none.
 */
void close_a_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", file);
		exit(98);
	}
}
/**
 * check_file - Checks if file is ELF.
 * @r: Remaining file content.
 * Return: none.
 */
void check_file(unsigned char *r)
{
	int i;

	for (i = 0; i < 4; i++)
		if (r[i] != 127 && r[i] != 'E' &&
		    r[i] != 'L' && r[i] != 'F')
			dprintf(STDERR_FILENO, "Error: Not ELF file\n"),
				exit(98);
}
/**
 * print_magic - Prints magic of ELF file.
 * @magic: ELF magic numbers.
 * Return: none.
 */
void print_magic(unsigned char *magic)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic[i]);
		i == EI_NIDENT - 1 ? printf("\n") : printf(" ");
	}
}
/**
 * print_class - Printf ELF class.
 * @class: ELF file.
 * Return: none.
 */
void print_class(unsigned char *class)
{
	printf("  Class:                             ");
	switch (class[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", class[EI_CLASS]);
	}
}
/**
 * print_data - Print ELF data file.
 * @data: ELF file.
 * Return: none.
 */
void print_data(unsigned char *data)
{
	printf("  Data:                              ");

	switch (data[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", data[EI_CLASS]);
	}
}
/**
 * print_version - Prints ELF version file.
 * @version: ELF file.
 * Return: none.
 */
void print_version(unsigned char *version)
{
	printf("  Version:                           %d",
	       version[EI_VERSION]);

	switch (version[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_os_abi - Prints ELF OS/ABI file.
 * @o_a: ELF file.
 * Return: none.
 */
void print_os_abi(unsigned char *o_a)
{
	printf("  OS/ABI:                            ");

	switch (o_a[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", o_a[EI_OSABI]);
	}
}
/**
 * print_abi - Prinf ELF ABI version file.
 * @abi: ELF file.
 * Return: none.
 */
void print_abi(unsigned char *abi)
{
	printf("  ABI Version:                       %d\n",
	       abi[EI_ABIVERSION]);
}
/**
 * print_type - Print ELF type file.
 * @type: ELF type.
 * @class: ELF Class.
 * Return: none.
 */
void print_type(unsigned int type, unsigned char *class)
{
	if (class[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}
/**
 * print_entry - Print ELF entry.
 * @e: ELF type.
 * @class: ELF Class
 * Return: none.
 */
void print_entry(unsigned long int e, unsigned char *class)
{
	printf("  Entry point address:               ");

	if (class[EI_DATA] == ELFDATA2MSB)
	{
		e = ((e << 8) & 0xFF00FF00) | ((e >> 8) & 0xFF00FF);
		e = (e << 16) | (e >> 16);
	}

	if (class[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e);

	else
		printf("%#lx\n", e);
}
/**
 * main - Displays the information contained in the ELF header at the
 *        start of an ELF file.
 * @ac: Number of arguments passed into the program
 * @av: Array of arguments passed.
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	Elf64_Ehdr *h;
	int o, r;

	if (ac != 2 || av[1] == NULL)
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n",
			av[0]), exit(98);
	o = open(av[1], O_RDONLY);
	if (o == -1)
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n",
			av[1]), exit(98);
	h = malloc(sizeof(Elf64_Ehdr));
	if (!h)
	{
		dprintf(STDERR_FILENO, "Error: No memory allocated for %s\n",
			av[1]);
		close_a_file(o), exit(98);
	}
	r = read(o, h, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		printf("Error: Cannot read file %s\n", av[1]);
		free(h), close_a_file(o), exit(98);
	}
	check_file(h->e_ident);
	print_magic(h->e_ident);
	print_class(h->e_ident);
	print_data(h->e_ident);
	print_version(h->e_ident);
	print_os_abi(h->e_ident);
	print_abi(h->e_ident);
	print_type(h->e_type, h->e_ident);
	print_entry(h->e_entry, h->e_ident);

	free(h);
	close_a_file(o);
	return (0);
}
