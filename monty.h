#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define _POSIX_C_SOURCE 200809L
#define UNSUSED(x) (void)(x)
#define INIT_INF {NULL, NULL, NULL, NULL, 1}
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
	int n;
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
 * struct info_s - struct
 * @head : the head of the stack
 * @tail : the tail of the stack
 * @arr : the array of tokens
 * @file : the file to be read
 * @line_num : the line number
 * Description: struct
 * for stack, queues, LIFO, FIFO
 */

typedef struct info_s
{
	stack_t *head;
	stack_t *tail;
	char **arr;
	FILE *file;
	int line_num;
} info_t;


extern info_t info;

int preprocess(char **commcpy, FILE *file);
char **array_of_tokns(char *comm, int token_num);
void exe_func(char **arr);
int number_fo_tokns(char *commcpy);
void check_EOF(size_t n, char *command);
void push(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
ssize_t _getline(char **buff, size_t *buffsize, FILE *file);
void initialze_buff(char **buff, size_t *buffsize);
int valid_int(char *str);
void twoD_free(void);
void free_stack(stack_t *head);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif