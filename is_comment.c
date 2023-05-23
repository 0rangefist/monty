#include "monty.h"

/**
 * is_comment - Checks if line is a comment by determining if
 * the first non-space character of a line is #.
 *
 * @input: The input string to be processed.
 * Return: 1 if line is a comment or 0 otherwise
 */
int is_comment(char *input)
{
	int i;

	/* remove leading whitespace so input[0] will be a non-whitespace char */
	strip_lead_trail_whitespace(input);

	for (i = 0; input[i] != '\0'; i++)
	{
		/* we have a comment if # is found & it is the 1st char*/
		if (input[i] == '#' && i == 0)
		{
			return (1);
		}
	}
	return (0);
}
