#include "monty.h"

/**
 * execute_pint -  prints top value on the stack.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_pint(stack_t **head, unsigned int line_number)
{
	stack_t *curr_node = *head;

	if (head == NULL || *head == NULL) /* null ptr or empty stack */
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	printf("%d\n", curr_node->n);
}
