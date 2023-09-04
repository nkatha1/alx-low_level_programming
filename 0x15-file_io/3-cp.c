#include "main.h"
#include <stdio.h>

/**
 * err_file - It checks if files can be opened.
 * @fle_frm: The file which is taken from.
 * @fle_to: The file to be taken to.
 * @argv: The vector argument.
 * Return: Null.
 */
void err_file(int fle_frm, int fle_to, char *argv[])
{
	if (fle_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (fle_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - The code for Holberton students it checks it.
 * @argc: Arguments number.
 * @argv: The vector arguments.
 * Return: Null always.
 */
int main(int argc, char *argv[])
{
	int fle_frm, fle_to, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	fle_frm = open(argv[1], O_RDONLY);
	fle_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	err_file(file_from, file_to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(fle_frm, buf, 1024);
		if (nchars == -1)
			err_file(-1, 0, argv);
		nwr = write(fle_to, buf, nchars);
		if (nwr == -1)
			err_file(0, -1, argv);
	}

	err_close = close(fle_frm);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
