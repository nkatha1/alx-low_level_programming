#include "main.h"

/**
 * get_endianness - It checks the endianness
 *
 * Return: If endian is big 0, if endian is little 1.
 */
int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 1;
	c = (char *) &x;

	return ((int)*c);
}
