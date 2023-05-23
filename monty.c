#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
char *id2;

/**
 * main - program entry point
 * @ac: argument count
 * @av: pointer to arguments
 *
 * Return: 0 on success or 1 for failure
 */
int main(int ac, char **av)
{
	FILE *fp;
	unsigned int line = 1;
	char *cmdline = NULL;
	stack_t *stack = NULL;
	int ch_count, stat = 0;
	size_t bs = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch_count = getline(&cmdline, &bs, fp)) > 1 && !stat)
	{
		stat = process_line(&stack, cmdline, line);
		line++;
	}
	free(cmdline);
	freestack(&stack);
	fclose(fp);
	return (stat);
}
/**
 * process_line - processes the given line from file
 * @stack: linked list
 * @cmdline: the line to process
 * @line: line count in the file being read
 *
 * Return: 0
 */
int process_line(stack_t **stack, char *cmdline, unsigned int line)
{
	instruction_t st[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL},
	};
	int i;
	char *token;
	char *del = " \t\n$";

	token = strtok(cmdline, del);
	if (token && token[0] == '#')
		return (0);
	id2 = strtok(NULL, del);
	for (i = 0; st[i].opcode && token; i++)
	{
		if (!strcmp(token, "nop"))
			return (0);
		if (!strcmp(st[i].opcode, token))
		{	st[i].f(stack, line);
			return (0); }
	}
	if (st[i].opcode == NULL)
	{	fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
		free(cmdline);
		freestack(stack);
		exit(EXIT_FAILURE); }
	return (0);
}
/**
 * freestack - free linked list
 * @stack: linked list
 *
 * Return: void
 */
void freestack(stack_t **stack)
{
	stack_t *ptr;

	if (stack && *stack)
	{
		ptr = *stack;
		while (*stack)
		{
			*stack = (*stack)->next;
			free(ptr);
			ptr = *stack;
		}
	}
}
