#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
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
typedef void(*opcodeFunction)(stack_t **stack, unsigned int line_number);

/**
 * struct holder - used to store global variables
 * @buffer: the one containing the current line
 * @new_value: incase of pop, the value is stored here
 * @file: the global file being read
 *
 * Description: stores variables mainly to help in freeing the memory
 */
typedef struct holder
{
	char *buffer;
	int new_value;
	FILE *file;
} holder_t;

extern holder_t global_holder;
/*============================ execute.c =====================*/
void execute(FILE *file);
void hashhandler(char *line);

/*============================ opcode_functions.c =====================*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **top, unsigned int line_number __attribute__((unused)));
void _div(stack_t **top, unsigned int line_number __attribute__((unused)));
void mul(stack_t **top, unsigned int line_number __attribute__((unused)));
void mod(stack_t **top, unsigned int line_number __attribute__((unused)));
void pchar(stack_t **top, unsigned int line_number __attribute__((unused)));
void pstr(stack_t **top, unsigned int line_number __attribute__((unused)));
void rotl(stack_t **top, unsigned int line_number __attribute__((unused)));

/*========================= memory.c ==========================*/
void free_stack(stack_t *top);
void free_global_holder();
#endif
