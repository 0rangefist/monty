#include "monty.h"

/**
 * is_number - checks if string is a number
 * @str: the input string
 * Return: 1 if the string represents a number, 0 otherwise
 */
int is_number(const char *str)
{
	int i = 0;

	/* Skip leading whitespaces */
	while (str[i] == ' ')
	{
		i++;
	}

	/* Check optional negative sign */
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	/* Check digits */
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}

	/* Check end of string for null byte*/
	if (str[i] == '\0')
	{
		return (1);
	}

	return (0);
}

/**
 * create_node - create node filled with int data
 * @token: string token containing an integer
 * Return: 1 if the string represents a number, 0 otherwise
 */
stack_t *create_node(char *token)
{
	stack_t *new_node; /* node  */
	int		 n;		   /* node data */

	if (token == NULL || !is_number(token)) /* if token isnt an int */
	{
		fprintf(stderr, "L%d: usage: push integer\n", prog_state.line_number);
		return (NULL);
	}

	n = atoi(token);
	/* create the node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL) /* alloc fail */
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node->n	   = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
/**
 * interpret_opcode - Interpretes an opcode
 * or returns a line number error if invalid
 *
 * @tokens: Token array (opcode & arguments)
 */
void interpret_opcode(char **tokens)
{
	void (*execute_opcode)(stack_t **, unsigned int);
	stack_t *new_node = NULL;

	execute_opcode = get_opcode(tokens[0]);
	if (execute_opcode == NULL) /* invalid opcode */
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				prog_state.line_number, tokens[0]);
		prog_state.is_alive	= 0;
		prog_state.exit_status = EXIT_FAILURE;
		return;
	}
	if (_strcmp(tokens[0], "push") == 0)
	{
		/* create a new node */
		new_node = create_node(tokens[1]);
		if (new_node == NULL) /* no/invalid argument or malloc fail */
		{
			prog_state.is_alive	= 0;
			prog_state.exit_status = EXIT_FAILURE;
			return;
		}
		execute_opcode(&new_node, prog_state.line_number);
	}
	else
	{
		execute_opcode(&head, prog_state.line_number);
	}
}
