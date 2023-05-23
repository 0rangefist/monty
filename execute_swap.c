#include "monty.h"

/**
 * execute_swap - swaps top two elements of the stack.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_swap(stack_t **head, unsigned int line_number)
{
	stack_t *node1 = NULL;
	stack_t *node2 = NULL;

	if (get_stack_count(head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	node1 = *head;
	node2 = node1->next;

	/* swap node1 and node2 */
	node1->prev = node2;
	node1->next = node2->next;

	node2->prev = NULL;
	node2->next = node1;

	/* update head to point node 2 */
	*head = node2;
}
