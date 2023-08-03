#include "main.h"

/**
 * flip_bits - Returns number of bits
 * needed to flip to get from a number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: bit numbers.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits;

	for (nbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbits++;
	}

	return (nbits);
}

