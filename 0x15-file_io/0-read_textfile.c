#include "main.h"

/**
 * custom_read_and_print - Reads a text file and
 *                       prints a specified number of letters.
 * @file_path: The path to the file.
 * @max_chars: The maximum number of characters to print.
 *
 * Return: The number of characters printed. Returns 0 if it fails.
 */
ssize_t custom_read_and_print(const char *file_path, size_t max_chars)
{
	int file_descriptor;
	ssize_t bytes_read, bytes_written;
	char *read_buffer;

	if (!file_path)
		return (0);

	file_descriptor = open(file_path, O_RDONLY);

	if (file_descriptor == -1)
		return (0);

	read_buffer = malloc(sizeof(char) * max_chars);
	if (!read_buffer)
		return (0);

	bytes_read = read(file_descriptor, read_buffer, max_chars);
	bytes_written = write(STDOUT_FILENO, read_buffer, bytes_read);

	close(file_descriptor);

	free(read_buffer);

	return (bytes_written);
}

