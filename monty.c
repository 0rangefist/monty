#include "monty.h"

stack_t		*head		= NULL; /* global stack head varaible */
prog_state_t prog_state = {0};	/* program-wide state variable */

/**
 * main - The entry point of the program
 *
 * @argc: The number of command line arguments passed to the program
 * @argv: An array of strings containing the command line arguments
 * passed to the program
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	char  *line;   /*current line from monty file*/
	char **tokens; /*string tokens of opcodes and arguments*/

	initialize_prog(argc, argv);
	while (prog_state.is_alive)
	{
		/* read line from file */
		line = get_line();

		if (line == NULL) /* if empty input or error */
			continue;	  /*restart loop*/

		if (is_comment(line)) /* if line is a comment */
		{
			free(line);
			continue; /* restart loop */
		}

		/* tokenize line into array of strings delimited by whitespace */
		tokens = get_tokens(line);

		/* interpret each opcode */
		interpret_opcode(tokens);

		free_array(tokens);
	}
	close(prog_state.fildes);
	free_nodes(head);
	return (prog_state.exit_status);
}
