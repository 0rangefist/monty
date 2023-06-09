#ifndef MONTY_H
#define MONTY_H

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* constants */
#define BUFFER_SIZE 1024
#define LINE_FACTOR 2

/* type definitions*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int				n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct prog_state - Holds state & info variables
 * of the interpreter program
 *
 * @prog_name: the name of the prog executable obtained from argv[0]
 * @line_number: current line number of the interpreter
 * @is_alive: boolean to determine if the program should keep running
 * @tokens: backup of array of token strings
 * @exit_status: 0 or positive number exit status of the program
 * @fildes: file descriptor for reading from a file
 * @is_stack: 1 if interpreter is in stack mode or 0 if in queue mode
 */
typedef struct prog_state
{
	char  *prog_name;
	int	   line_number;
	int	   is_alive;
	char **tokens;
	int	   exit_status;
	int	   fildes;
	int	   is_stack;
} prog_state_t;

extern stack_t	   *head;
extern prog_state_t prog_state;

/* main program functions */
void   initialize_prog(int argc, char *argv[]);
char  *get_line();
int	   is_comment(char *input);
char **get_tokens(char *input);
void   interpret_opcode(char **tokens);

/* monty opcodes */
void (*get_opcode(char *opcode))(stack_t **, unsigned int);
void execute_push(stack_t **head, unsigned int line_number);
void execute_pall(stack_t **head, unsigned int line_number);
void execute_pint(stack_t **head, unsigned int line_number);
void execute_pop(stack_t **head, unsigned int line_number);
void execute_swap(stack_t **head, unsigned int line_number);
void execute_add(stack_t **head, unsigned int line_number);
void execute_nop(stack_t **head, unsigned int line_number);
void execute_sub(stack_t **head, unsigned int line_number);
void execute_div(stack_t **head, unsigned int line_number);
void execute_mul(stack_t **head, unsigned int line_number);
void execute_mod(stack_t **head, unsigned int line_number);
void execute_pchar(stack_t **head, unsigned int line_number);
void execute_pstr(stack_t **head, unsigned int line_number);
void execute_rotl(stack_t **head, unsigned int line_number);
void execute_rotr(stack_t **head, unsigned int line_number);

/* string manipulation functions */
char *_strdup(const char *str);
int	  _strlen(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
int	  _strncmp(const char *str1, const char *str2, size_t n);
int	  _strcmp(const char *s1, const char *s2);

/* auxilliary functions */
int	   read_line(char **line, int fd);
char **tokenize(char *str, char *delim);
void   free_array(char **str_arr);
void   free_nodes(stack_t *head);
int	   is_whitespace_string(char *str);
void   strip_lead_trail_whitespace(char *str);
void   strip_all_whitespace(char *str);
int	   strip_repeated_whitespace(char *buffer, int buff_len);
void  *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int	   get_stack_count(stack_t **head);
#endif /*MONTY_H*/
