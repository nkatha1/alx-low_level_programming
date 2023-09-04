#include "main.h"

/**
 * read_textfile - It reads the text file
 *             and it prints those letters.
 * @fname: The filename.
 * @ltrs: The printed numbers to letters.
 *
 * Return: It returns the printed number of letters,
 *          it returns 0 if it fails.
 */
ssize_t read_textfile(const char *fname, size_t ltrs)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (!fname)
		return (0);

	fd = open(fname, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (ltrs));
	if (!buf)
		return (0);

	nrd = read(fd, buf, ltrs);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(fd);

	free(buf);

	return (nwr);
}
