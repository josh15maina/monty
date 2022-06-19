#include "monty.h"
/**
 * _add - add first two elements in stack,
 * then remove them, and push result to stack
 * @stack: address of stack
 * @line_number: line number of current processing input
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (state->size < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	state->size--;
}
/**
 * _sub - subtract top from second top
 * @stack: address of stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (state->size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	state->size--;
}
/**
 * _mul - multiply first two elements on stack
 * @stack: address of stack
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (state->size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	state->size--;
}
/**
 * _div - divide second top by top
 * @stack: address of stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (state->size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	state->size--;
}
/**
 * _mod - second top % top
 * @stack: address of stack
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (state->size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	state->size--;
}
