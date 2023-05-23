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
		exit(EXIT_FAILURE); }
	if ((*stack)->n > 127 || (*stack)->n < 33)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
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
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE); }
	ptr = *stack;
	while (ptr)
	{
		if (ptr->n == 0)
		{
			fprintf(stdout, "\n");
			return; }
		if (ptr->n > 127 || ptr->n < 33)
		{
			fprintf(stderr, "L%d: can't pstr, value out of range", line_number);
			exit(EXIT_FAILURE); }
		fprintf(stdout, "%c", ptr->n);
		ptr = ptr->next;
	}
	fprintf(stdout, "\n");
}
/**
 * rotl - rotate the whole linked list
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
	val = ptr->n;
	while (ptr->next != NULL)
	{
		val = ptr->n;
		ptr->n = ptr->next->n;
		ptr = ptr->next;
		ptr->n = val; }
}
