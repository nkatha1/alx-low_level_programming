/*
 * File: 100-elf_header.c
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * chck_elf - It checks for an ELF file.
 * @The_ident: The ELF magic numbers array pointer.
 *
 * Dscrption: Exit code 98 if file is not an elf file.
 */
void chck_elf(unsigned char *The_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (The_ident[index] != 127 &&
		    The_ident[index] != 'E' &&
		    The_ident[index] != 'L' &&
		    The_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * prnt_mgic - The ELF header magic numbers it prints it.
 * @The_ident: Magic numbers ELF header in the array pointer.
 *
 * Dscrption: The magic numbers are separated by spaces.
 */
void prnt_mgic(unsigned char *The_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prnt_class - ELF header class it prints it.
 * @The_ident: ELF class with the array pointer.
 */
void prnt_class(unsigned char *The_ident)
{
	printf("  Class:                             ");

	switch (The_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", The_ident[EI_CLASS]);
	}
}

/**
 * prnt_data - The ELF header it prints it.
 * @The_ident: ELF class with the array pointer.
 */
void prnt_data(unsigned char *The_ident)
{
	printf("  Data:                              ");

	switch (The_ident[EI_DATA])
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
		printf("<unknown: %x>\n", The_ident[EI_CLASS]);
	}
}

/**
 * prnt_vrsion - ELF header version it prints it.
 * @The_ident: ELF version pointer containing the pointer array.
 */
void prnt_vrsion(unsigned char *The_ident)
{
	printf("  Version:                           %d",
	       The_ident[EI_VERSION]);

	switch (The_ident[EI_VERSION])
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
 * prnt_osabi - Elf header OS/ABI it prints it.
 * @The_ident:  ELF version array pointer.
 */
void prnt_osabi(unsigned char *The_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", The_ident[EI_OSABI]);
	}
}


/**
 * print_abi - An ELF header ABI version prints it.
 * @The_ident: ELF ABI version in the pointer array.
 */
void print_abi(unsigned char *The_ident)
{
	printf("  ABI Version:                       %d\n",
	       The_ident[EI_ABIVERSION]);
}

/**
 * prt_type - ELF header it prints the type.
 * @The_type: The type of the ELF.
 * @The_ident: An ELF class array pointer.
 */
void prt_type(unsigned int The_type, unsigned char *The_ident)
{
	if (The_ident[EI_DATA] == ELFDATA2MSB)
		The_type >>= 8;

	printf("  Type:                              ");

	switch (The_type)
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
		printf("<unknown: %x>\n", The_type);
	}
}

/**
 * print_entry - ELF header point of entry it prints it.
 * @The_entry: The ELF entry point adress.
 * @The_ident: The ELF class array pointer.
 */
void print_entry(unsigned long int The_entry, unsigned char *The_ident)
{
	printf("  Entry point address:               ");

	if (The_ident[EI_DATA] == ELFDATA2MSB)
	{
		The_entry = ((The_entry << 8) & 0xFF00FF00) |
			  ((The_entry >> 8) & 0xFF00FF);
		The_entry = (The_entry << 16) | (The_entry >> 16);
	}

	if (The_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)The_entry);

	else
		printf("%#lx\n", The_entry);
}

/**
 * close_elf - The ELF file it closes it.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: Exit code -98 if the file cannot be closed.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - The  info contained in the
 *        ELF header it displays at the start of an ELF file.
 * @argc: Arguments number supplied to the program.
 * @argv: Pointers array to the arguments.
 *
 * Return: On success returns 0.
 *
 * Description: Exit code 98 if the file is not an ELF File or
 *              the function fails.
 */
int main(int __att__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
