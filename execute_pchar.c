#include "monty.h"

/**
 * execute_pchar - prints the char at the top of the stack,
 * followed by a new line.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *node1 = *head;

	/* if stack is empty */
	if (get_stack_count(head) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	/* if n isnt in the ascii range 0-127 */
	if(node1->n < 0 || node1->n >127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	/* print n as an ascii character */
	printf("%c\n", node1->n);

}
