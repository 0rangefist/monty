#include "monty.h"

/**
 * get_opcode - Returns the function associated with an opcode
 * @opcode: opcode to retrieve function for
 *
 * Return: function pointer associated with opcode or NULL otherwise
 */
void (*get_opcode(char *opcode))(stack_t **, unsigned int)
{
	int			  i;
	instruction_t opcodes[] = {
		{"push", execute_push}, {"pall", execute_pall}, {"pint", execute_pint},
		{"pop", execute_pop},	{"swap", execute_swap}, {"add", execute_add},
		{"nop", execute_nop},	{"sub", execute_sub},	{"div", execute_div},
		{"mul", execute_mul},	{"mod", execute_mod},	{NULL, NULL}};
	/*
	 *	{"pchar", execute_pchar},
	 *	{"pstr", execute_pstr},
	 *	{"rotl", execute_rotl},
	 *	{"rotr", execute_rotr},
	 *	{"stack", execute_stack},
	 *	{"queue", execute_queue}
	 */

	/* check for the opcode*/
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		/*compare command to names of builtin commands*/
		if (_strcmp(opcode, opcodes[i].opcode) == 0)
		{
			/* return the function whose name matches */
			return (opcodes[i].f);
		}
	}
	return (NULL); /* return NULL if no match was made */
}
