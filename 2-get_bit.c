#include "main.h"

/**
 * get_bit - Value of a bit at a given index it
 * returns it.
 * @l: Long integer input that is unasigned.
 * @index: The bit index.
 *
 * Return: The bit value.
 */
int get_bit(unsigned long int l, unsigned int index)
{
	unsigned int i;

	if (l == 0 && index < 64)
		return (0);

	for (i = 0; i <= 63; l >>= 1, i++)
	{
		if (index == i)
		{
			return (l & 1);
		}
	}

	return (-1);
}
