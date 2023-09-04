#include "main.h"

/**
 * append_text_to_file - At the end of a file
 *                     it append text.
 * @fname: The filename.
 * @txt_cont: The text added content.
 *
 * Return: If the file exists it returns 1,
 *          if it does not exist or it fails it returns -1.
 */
int append_text_to_file(const char *fname, char *txt_cont)
{
	int fd;
	int nletters;
	int rwr;

	if (!fname)
		return (-1);

	fd = open(fname, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (txt_cont)
	{
		for (nletters = 0; txt_cont[nletters]; nletters++)
			;

		rwr = write(fd, txt_cont, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
