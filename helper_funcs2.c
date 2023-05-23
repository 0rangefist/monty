#include "monty.h"
/**
 * _strcmp - compare two strings
 *
 * @s1: pointer to the first string to be compared
 * @s2: pointer to the second string to be compared
 *
 * Return: an int greater than, equal to, or less than 0.
 */
int _strcmp(const char *s1, const char *s2)
{
	int result;

	while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	result = *(const unsigned char *) s1 - *(const unsigned char *) s2;

	return (result);
}

/**
 * get_stack_count - gets the number of elements in a stack
 *
 * @head: double pointer to head of the stack
 * Return: number of stack elements.
 */
int get_stack_count(stack_t **head)
{
	int		 count = 0;
	stack_t *stack = *head;

	if (head == NULL || *head == NULL) /* null ptr or empty stack */
		return (0);

	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}

	return (count);
}
