#include "monty.h"

/**
 * free_array - Frees the memory used by an array of strings
 *
 * @arr: The array of strings to free
 */
void free_array(char **arr)
{
	int i;

	if (arr == NULL) /* null ptr */
		return;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
