#include "monty.h"

/**
 * initialize_prog - Initializes the prog_state_t struct with
 * startup values for various program-wide variables
 *
 * @prog_state: Pointer to the prog_state_t struct to initialize
 * @argc: Number of command-line arguments
 * @argv: Array of strings containing command-line arguments
 */
void initialize_prog(prog_state_t *prog_state, int argc, char *argv[])
{
	prog_state->prog_name	= argv[0];
	prog_state->line_number = 0;
	prog_state->is_alive	= 1;
	prog_state->exit_status = 0;
	prog_state->tokens		= NULL;
	prog_state->fildes		= 99;

	if (argc != 2) /* incorrect usage */
	{
		fprintf(stderr, "USAGE: monty file\n");
		prog_state->is_alive	= 0; /*kill prog*/
		prog_state->exit_status = EXIT_FAILURE;
		return;
	}

	prog_state->fildes = open(argv[1], O_RDONLY);
	if (prog_state->fildes == -1) /* file read error */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		prog_state->is_alive	= 0; /*kill prog*/
		prog_state->exit_status = EXIT_FAILURE;
	}
}
