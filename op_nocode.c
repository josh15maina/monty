#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: address of stack
 * @line_number: line number of the current processing input
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (state->size == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number of the current processing input
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (state->size == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
	state->size--;
}
/**
 * swap - swap first two element in stack
 * @stack: address of stack
 * @line_number: line number of the current processing input
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;

	if (state->size < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	*stack = second;
}
/**
 * nop - waste of skin
 * @stack: address of stack
 * @line_number: line number of the current processing input
 */
void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack + 0;
	line_number += 0;
}
/**
 * pall - print all elements in stack
 * @stack: address of stack
 * @line_number: line number of the current processing input
 */
void pall(stack_t **stack, unsigned int line_number)
{
	print_dlistint(*stack);
	line_number += 0;
}
