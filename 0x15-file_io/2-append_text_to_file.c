#include "main.h"

/**
 * append_text_to_file - At the end of a file,appends the text.
 * @filename: The filename.
 * @text_content: Content that is added.
 *
 * Return: If file exists 1 ,if file fails
 * or does not exist -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		rwr = write(fd, text_content, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(fd);

	return (1);
}

