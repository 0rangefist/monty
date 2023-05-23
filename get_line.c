#include "monty.h"
/**
 * get_line - gets a line read from a file
 * @prog_state: Struct of current prog state variables
 * Return: line string or NULL otherwise
 */
char *get_line(prog_state_t *prog_state)
{
	char *line = NULL;
	int	  chars_read;
	int	  fd = prog_state->fildes;

	chars_read = read_line(&line, fd);
	(prog_state->line_number)++;

	if (chars_read == -1)		  /* if EOF encountered */
		prog_state->is_alive = 0; /* kill program */

	if (is_whitespace_string(line))
	{
		free(line);
		return (NULL);
	}

	if (line != NULL && chars_read >= 1) /*if line is non-empty string*/
		return (line);

	/* else if line == NULL || chars_read < 1  */
	free(line);
	return (NULL);
}
