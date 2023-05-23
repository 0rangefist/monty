#include "monty.h"
/**
 * free_nodes - Frees the memory allocated to a stack_t list
 * @head: Pointer to the start of the list
 * Return: void
 */
void free_nodes(stack_t *head)
{
	stack_t *node_to_free = head;

	if (head == NULL) /* empty list */
		return;

	/* traverse through the list & free each node */
	while (head != NULL)
	{
		node_to_free = head;
		head		 = head->next;
		free(node_to_free);
	}
}
