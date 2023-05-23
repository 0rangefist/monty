#include "monty.h"

/**
 * execute_push - Pushes a new node unto to the stack
 *
 * @new_node: new node to be pushed unto stack
 * @line_number: current line number in the monty file
 */
void execute_push(stack_t **new_node, unsigned int line_number)
{
	(void) line_number;
	(*new_node)->prev = NULL;
	(*new_node)->next = head;
	if (head != NULL) /* if not an empty list */
		head->prev = *new_node;
	head = *new_node;
}
