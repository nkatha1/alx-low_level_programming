#include "main.h"

/**
 * clear_bit - It sets the value of a bit at
 * a given index to 0.
 * @n: The unsigned long int pointer.
 * @index: The bit index.
 *
 * Return: If it worked 1,if it didn't -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;

	if (*n & m)
		*n ^= m;

	return (1);
}
