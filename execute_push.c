#include "monty.h"
/**
 * enqueue - Adds a new node to the back of the queue
 * @new_node: new node to be pushed unto stack
 */
void enqueue(stack_t **new_node)
{
	stack_t *tail;

	if (head == NULL) /* if queue is empty add new node to head */
	{
		(*new_node)->next = NULL;
		head			  = *new_node;
		return;
	}

	tail = head;
	while (tail->next != NULL) /* traverse to end to get tail node */
		tail = tail->next;

	/* add new node to end */
	(*new_node)->next = NULL;
	(*new_node)->prev = tail;
	tail->next		  = *new_node;
}

/**
 * push - Pushes a new node unto to the stack
 * @new_node: new node to be pushed unto stack
 */
void push(stack_t **new_node)
{
	(*new_node)->prev = NULL;
	(*new_node)->next = head;

	if (head != NULL) /* if not an empty list */
		head->prev = *new_node;

	head = *new_node;
}

/**
 * execute_push - Pushes a new node to top of stack if in stack
 * mode or enqueues a new node at the back if prog in queue mode
 * @new_node: new node to be pushed or enqueued
 * @line_number: current line number in the monty file
 */
void execute_push(stack_t **new_node, unsigned int line_number)
{
	(void) line_number;

	if (prog_state.is_stack) /* in stack mode */
		push(new_node);
	else /* in queue mode */
		enqueue(new_node);
}
