#include "monty.h"
/**
 * stack - switch to stack mode
 * @stack: address of stack
 * @line_number: line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	state->mode = MOD_STK;
}
/**
 * queue - switch to queue mode
 * @stack: address of stack
 * @line_number: line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack += 0;
	line_number += 0;
	state->mode = MOD_QUE;
}
