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
 * struct prog_state - Holds state & info variables
 * of the interpreter program
 *
 * @prog_name: the name of the prog executable obtained from argv[0]
 * @line_number: current line number of the interpreter
 * @is_alive: boolean to determine if the program should keep running
 * @tokens: backup of array of token strings
 * @exit_status: 0 or positive number exit status of the program
 * @fildes: file descriptor for reading from a file
 */
struct prog_state
{
	char  *prog_name;
	int	   line_number;
	int	   is_alive;
	char **tokens;
	int	   exit_status;
	int	   fildes;
};

/**
 * prog_state_t - typedef for struct prog_state
 */
typedef struct prog_state prog_state_t;

/* main program functions */
void   initialize_prog(prog_state_t *s, int argc, char *argv[]);
char  *get_line(prog_state_t *s);
int	   is_comment(char *input);
char **get_tokens(char *input);
void   interpret_opcode(char **tokens, prog_state_t *prog_state);

/* monty opcodes */
void execute_push(char **tokens, prog_state_t *prog_state);

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
int	   is_whitespace_string(char *str);
void   strip_lead_trail_whitespace(char *str);
void   strip_all_whitespace(char *str);
int	   strip_repeated_whitespace(char *buffer, int buff_len);
void  *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /*MONTY_H*/
