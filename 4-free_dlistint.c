#include "monty.h"

/**
 * free_dlistint - free a doubly linked list
 * @head: pointer to head node
 */
void free_dlistint(stack_t *head)
{
	stack_t *ptr = head;

	while (head)
	{
		ptr = ptr->next;
		free(head);
		head = ptr;
	}
}
