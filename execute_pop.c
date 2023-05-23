#include "monty.h"

/**
 * execute_pop - removes top element from the stack.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_pop(stack_t **head, unsigned int line_number)
{
	stack_t *old_head = NULL;

	if (head == NULL || *head == NULL) /* null ptr or empty stack */
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		prog_state.exit_status = EXIT_FAILURE;
		prog_state.is_alive	   = 0;
		return;
	}

	/* save the original head node */
	old_head = *head;

	/* if only one item in stack */
	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	else /* more than one item in stack */
	{
		/* make next node after head the new head */
		*head = (*head)->next;
		/* point new head's prev to NULL */
		(*head)->prev = NULL;
	}

	/* free the old head node */
	free(old_head);
}
