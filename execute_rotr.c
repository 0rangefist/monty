#include "monty.h"

/**
 * execute_rotr - makes the last stack element the first.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *node1;
	stack_t *tail_but_one;
	stack_t *tail;

	(void) line_number;

	if (get_stack_count(head) < 2) /* if stack is empty or single */
		return;

	node1 = *head;
	tail  = *head;

	while (tail->next != NULL) /* traverse to last node of stack */
		tail = tail->next;

	tail_but_one = tail->prev;

	/* make tail_but_one the new tail */
	tail_but_one->next = NULL;

	/* make old tail the new head */
	tail->next = node1;
	tail->prev = NULL;

	/* point node1 back to the new head */
	node1->prev = tail;

	/* update the new head */
	*head = tail;
}
