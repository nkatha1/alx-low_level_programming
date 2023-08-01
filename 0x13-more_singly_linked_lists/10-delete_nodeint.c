#include "lists.h"

/**
 * delete_nodeint_at_index - At index
 * of a linked list deletes the node.
 * @head: The head of a list.
 * @index: The index of the list where the
 * deleted node is.
 *
 * Return: If it succeeded 1,
 * if it failed -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *prev;
	listint_t *next;

	prev = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && prev != NULL; i++)
		{
			prev = prev->next;
		}
	}

	if (prev == NULL || (prev->next == NULL && index != 0))
	{
		return (-1);
	}

	next = prev->next;

	if (index != 0)
	{
		prev->next = next->next;
		free(next);
	}
	else
	{
		free(prev);
		*head = next;
	}

	return (1);
}

