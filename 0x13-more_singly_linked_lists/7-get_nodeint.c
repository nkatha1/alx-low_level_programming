#include "lists.h"

/**
 * get_nodeint_at_index - Returns nth node of the linked list.
 * @head: The head of a list.
 * @index: The index of the node.
 *
 * Return: nth node. NULL return if node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index && head != NULL; i++)
	{
		head = head->next;
	}

	return (head);
}
