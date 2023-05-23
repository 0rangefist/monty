#include "monty.h"

/**
 * get_tokens - Tokenizes an string into an array of
 * strings using whitespace as the delimiter
 *
 * @input: The string to tokenize
 *
 * Return: Array of strings or NULL otherwise
 */
char **get_tokens(char *input)
{
	char **tokens = NULL;
	char   *delim = " \t\r\n\f\v"; /* delimiter for the tokenization */

	tokens = tokenize(input, delim);

	/* free memory pointed to by input & reset it to NULL */
	free(input);
	input = NULL;

	return (tokens);
}
