#include "main.h"

/**
 * flip_bits - It returns the number of bits you would
 * need to flip.
 * @a: first number.
 * @b: second number.
 *
 * Return: bits number.
 */
unsigned int flip_bits(unsigned long int a, unsigned long int b)
{
	unsigned int nbits;

	for (abits = 0; a || b; a >>= 1, b >>= 1)
	{
		if ((a & 1) != (b & 1))
			abits++;
	}

	return (abits);
}
