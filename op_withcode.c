#include "monty.h"

int isInt(char *s);
/**
 * push - push a element to stack/queue
 * @stack: address of stack
 * @line_number: line number of current processing input
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *ret = NULL;

	if (!state->argument || !isInt(state->argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		state_clear();
		exit(EXIT_FAILURE);
	}
	if (state->mode == MOD_STK)
		ret = add_dnodeint(stack, atoi(state->argument));
	else
		ret = add_dnodeint_end(stack, atoi(state->argument));
	if (!ret)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	state->size++;
}
/**
 * isInt - check if a string is integer
 * @s: string
 *
 * Return: 0 if not integer, 1 otherwise
 */
int isInt(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (*s == 0)
		return (0);
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		s++;
	}
	return (1);
}
