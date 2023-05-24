#include "monty.h"

/**
 * execute_mod - modulo the second element of the stack by the
 * first & saves the result in the second and pops the first.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_mod(stack_t **head, unsigned int line_number)
{
	stack_t *node1 = NULL;
	stack_t *node2 = NULL;

	if (get_stack_count(head) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	node1 = *head;
	node2 = node1->next;

	/* node1->n is 0, division by 0 error */
	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	/* modulo node2 by node1 & save in node2 */
	node2->n = node2->n % node1->n;

	/* pop node 1 */
	execute_pop(head, line_number);
}
