#include "main.h"

/**
 * get_endianness - The endianness it checks it.
 *
 * Return: If big endian 0, if little endian 1.
 */
int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 1;
	c = (char *) &x;

	return ((int)*c);
}
