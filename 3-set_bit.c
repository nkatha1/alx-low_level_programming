#include "main.h"

/**
 * set_bit - It sets the value to 1 of the bit
 * at an index that is given.
 * @n: The long int unsigned pointer.
 * @index: The bit index.
 *
 * Return: If it worked 1,if it didn't -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;
	*n = (*n | m);

	return (1);
}
