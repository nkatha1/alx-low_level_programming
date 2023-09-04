#include "main.h"

/**
 * create_and_write_file - Creates a new file and
 *                       writes specified text content to it.
 * @file_name: The name of the file to create.
 * @content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_and_write_file(const char *file_name, char *content)
{
	int file_descriptor;
	int num_characters;
	int bytes_written;

	if (!file_name)
		return (-1);

	file_descriptor = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (!content)
		content = "";

	for (num_characters = 0; content[num_characters]; num_characters++)
		;

	bytes_written = write(file_descriptor, content, num_characters);

	if (bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}

