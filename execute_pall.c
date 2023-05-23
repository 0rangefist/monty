#include "monty.h"

/**
 * execute_pall -  prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @head: double pointer to head of the stack
 * @line_number: current line number in the monty file
 */
void execute_pall(stack_t **head, unsigned int line_number)
{
	(void) line_number;

	if (head == NULL || *head == NULL) /* null ptr or empty stack */
		return;

	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}
