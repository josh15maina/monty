#include "monty.h"
#include <stdio.h>

/**
 * main - entry point of Monty interpreter
 * @argc: argument count
 * @argv: argument strings array
 *
 * Return: 0 on success, exit with status code on failure
 */
int main(int argc, char **argv)
{
	size_t size = BUF_SIZE;
	int i, num_read = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	state_init();
	state->fptr = fopen(argv[1], "r");
	if (!state->fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		state_clear();
		exit(EXIT_FAILURE);
	}
	do {
		for (i = 0; i < BUF_SIZE; i++)
			state->buffer[i] = 0;
		num_read = getline(&(state->buffer), &size, state->fptr);
		process_line(state->buffer);
		if (state->op)
		{
			if (state->op[0] != '#')
				runner();
		}
		state->op = NULL;
		state->argument = NULL;
	} while (num_read != -1);
	state_clear();
	return (0);
}
