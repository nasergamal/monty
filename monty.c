#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
st s = {0, 0, NULL, NULL};

/**
 * main - program entry point
 * @ac: argument count
 * @av: pointer to arguments
 *
 * Return: 0 on success or 1 for failure
 */
int main(int ac, char **av)
{
	unsigned int line = 1;
	stack_t *stack = NULL;
	int ch_count;
	size_t bs = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	s.fp = fopen(av[1], "r");
	if (s.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch_count = getline(&(s.cmdline), &bs, s.fp)) > 0)
	{
		process_line(&stack, line);
		line++;
	}
	free_stuff(&stack);
	return (0);
}
/**
 * process_line - processes the given line from file
 * @stack: linked list
 * @line: line count in the file being read
 *
 * Return: 0
 */
void process_line(stack_t **stack, unsigned int line)
{
	instruction_t st[] = {
		{"push", push},	{"pall", pall},	{"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"sub", sub}, {"div", _div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},	{"pstr", pstr},
		{"rotl", rotl},	{"rotr", rotr},	{NULL, NULL},
	};
	int i;
	char *token, *del = " \t\n";

	token = strtok(s.cmdline, del);
	if (token && token[0] == '#')
		return;
	s.id2 = strtok(NULL, del);
	if (!token || !strcmp(token, "nop"))
		return;
	if (!strcmp(token, "stack"))
	{       s.queue = 0;
		return; }
	if (!strcmp(token, "queue"))
	{       s.queue = 1;
		return; }
	for (i = 0; st[i].opcode && token; i++)
	{
		if (!strcmp(st[i].opcode, token))
		{	st[i].f(stack, line);
			return; }
	}
	if (st[i].opcode == NULL)
	{	fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
		free_stuff(stack), exit(EXIT_FAILURE); }
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
