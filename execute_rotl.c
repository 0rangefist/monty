#include "monty.h"

/**
 * execute_rotl - makes the top stack element the last,
 * and makes the second element the top element.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *node1;
	stack_t *node2;
	stack_t *tail;

	(void) line_number;

	if (get_stack_count(head) < 2) /* if stack is empty or single */
		return;

	node1 = *head;
	node2 = (*head)->next;
	tail  = *head;

	while (tail->next != NULL) /* traverse to last node of stack */
		tail = tail->next;

	/* make node1 the new tail */
	tail->next	= node1;
	node1->next = NULL;
	node1->prev = tail;

	/* make node2 the new head */
	node2->prev = NULL;
	*head		= node2;
}
