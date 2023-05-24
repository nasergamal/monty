#include "monty.h"

/**
 * pchar - print the content of the top node as ascii
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE); }
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE); }
	fprintf(stdout, "%c\n", ((*stack)->n));
}
/**
 * pstr - print nodes elements as ascii
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->n > 127 || ptr->n <= 0)
			break;
		fprintf(stdout, "%c", ptr->n);
		ptr = ptr->next;
	}
	fprintf(stdout, "\n");
}
/**
 * rotl - move the first node to the end of linked list
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr;
	int val;

	if (stack == NULL || *stack == NULL)
		return;
	ptr = *stack;
	while (ptr->next != NULL)
	{
		val = ptr->n;
		ptr->n = ptr->next->n;
		ptr = ptr->next;
		ptr->n = val; }
}
/**
 * rotr - rotate the linked list
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
		return;
	ptr = *stack;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	(*stack)->prev = ptr;
	ptr->next = (*stack);
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	*stack = ptr;
}
/**
 * free_stuff - close files and free mem of global variables and linked list
 * @stack: linked list
 * Return: void
 */
void free_stuff(stack_t **stack)
{
	fclose(s.fp);
	free(s.cmdline);
	freestack(stack);
}
