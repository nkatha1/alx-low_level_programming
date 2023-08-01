#include "lists.h"

/**
 * sum_listint - Returns sum of all data (n) of
 * the linked list.
 * @head: The head of a list.
 *
 * Return: The Sum of all data (n).
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

