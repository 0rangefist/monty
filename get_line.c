#include "monty.h"
/**
 * get_line - gets a line read from a file
 * Return: line string or NULL otherwise
 */
char *get_line()
{
	char *line = NULL;
	int	  chars_read;
	int	  fd = prog_state.fildes;

	chars_read = read_line(&line, fd);
	(prog_state.line_number)++;

	if (chars_read == -1)		 /* if EOF encountered */
		prog_state.is_alive = 0; /* kill program */

	if (line != NULL && chars_read >= 1) /* non empty line */
		return (line);

	/* else if line == NULL || chars_read < 1  */
	free(line);
	return (NULL);
}
