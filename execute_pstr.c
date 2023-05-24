#include "monty.h"

/**
 * execute_pstr - prints a string starting at the
 * top of the stack, followed by a new line.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *curr = *head;

	(void) line_number;

	/* if stack is empty */
	if (get_stack_count(head) == 0)
	{
		printf("\n");
		return;
	}

	/* traverse stack till the end */
	while (curr != NULL)
	{
		if (curr->n <= 0 || curr->n > 127) /* out of ascii range */
			break;
		printf("%c", curr->n); /* print ascii char */
		curr = curr->next;/* move to next node */
	}
	printf("\n");
}
