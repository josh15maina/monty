#include "monty.h"
/**
 * pchar - pring top of stack as char
 * @stack: address of stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (state->size == 0)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
/**
 * pstr - print stack as a string
 * stop when stack is over, value of element is 0, or not ascii char
 * @stack: address of stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void) line_number;

	while (ptr && (ptr->n <= 127 && ptr->n > 0))
	{
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}
/**
 * rotl - rotate stack to the top
 * @stack: address of stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *tail = *stack;
	(void) line_number;

	if (state->size > 1)
	{
		*stack = head->next;
		while (tail->next)
			tail = tail->next;
		head->next->prev = NULL;
		head->next = NULL;
		head->prev = tail;
		tail->next = head;
	}
}
/**
 * rotr - rotate stack to the bottom
 * @stack: address of stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *tail = *stack;
	(void) line_number;

	if (state->size > 1)
	{
		while (tail->next)
			tail = tail->next;
		*stack = tail;
		tail->prev->next = NULL;
		tail->prev = NULL;
		tail->next = head;
		head->prev = tail;
	}
}
