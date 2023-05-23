#include "monty.h"

/**
 * interpret_opcode - Interpretes an opcode
 * or returns a line number error if invalid
 *
 * @tokens: Token array (opcode & arguments)
 * @prog_state: Struct of current shell state variables
 */
void interpret_opcode(char **tokens, prog_state_t *prog_state)
{
	if (_strcmp(tokens[0], "push") == 0) /* push opcode */
		execute_push(tokens, prog_state);
	else /* invalid opcode */
		fprintf(stderr, "L%d: unknown instruction %s", prog_state->line_number,
				tokens[0]);
}
