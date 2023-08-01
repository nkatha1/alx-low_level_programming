#include "lists.h"

/**
 * print_listint - Prints all elements of a list.
 * @h: The head of list.
 *
 * Return:The numbers of the nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t nnodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nnodes++;
	}
	return (nnodes);
}

