#include "lists.h"

/**
 * pop_listint - It deletes the linked
 * list head node.
 * @head: The head of a list.
 *
 * Return: The data of the head node.
 */
int pop_listint(listint_t **head)
{
	int hnode;
	listint_t *h;
	listint_t *curr;

	if (*head == NULL)
		return (0);

	curr = *head;

	hnode = curr->n;

	h = curr->next;

	free(curr);

	*head = h;

	return (hnode);
}

