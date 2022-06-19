#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 4096
#define MOD_STK 0
#define MOD_QUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct info_s - hold info on current program states
 * @buffer: input buffer
 * @op: opcode
 * @argument: opcode argument
 * @stack: stack
 * @fptr: file ptr
 * @mode: stack / queue
 * @size: stakc/queue size
 * @ln: processing line number
 */
typedef struct info_s
{
	char *buffer;
	char *op;
	char *argument;
	stack_t *stack;
	FILE *fptr;
	unsigned int mode;
	unsigned int size;
	unsigned int ln;
} info_t;

int _strcmp(char *s1, char *s2);

void state_init(void);
void state_clear(void);
void process_line(char *line);
void (*get_func(char *op))(stack_t **stack, unsigned int line_number);
void runner(void);

void push(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

extern info_t *state;

#endif /* MONTY_H_ */
