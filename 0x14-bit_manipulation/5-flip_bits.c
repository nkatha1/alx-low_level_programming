#include "main.h"

/**
 * flip_bits - Number of bits you need
 * to flip to get from one number to another it returns.
 * @n: first number.
 * @m: second number.
 *
 * Return: Bits number.
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
