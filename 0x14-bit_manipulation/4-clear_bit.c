#include "main.h"

/**
 * clear_bit - At a given index,it sets the value of a bit to 0.
 * @n: Unsigned long integer pointer.
 * @index: Bit index.
 *
 * Return: If it worked 1,if it did not -1.
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
