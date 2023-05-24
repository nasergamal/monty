#include "monty.h"

/**
 * add - addition of the first 2 nodes into 2nd node and remove the top node
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = val;
	pop(stack, line_number);
}
/**
 * sub - calculate the module of the first 2 nodes and remove the top node
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = val;
	pop(stack, line_number);
}
/**
 * _div - calculate the division of the first 2 nodes and remove the top node
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stuff(stack), exit(EXIT_FAILURE); }
	val = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = val;
	pop(stack, line_number);
}
/**
 * mul - multiply the first 2 nodes and remove the top node
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = val;
	pop(stack, line_number);
}
/**
 * mod - calculate the module of the first 2 nodes and remove the top node
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stuff(stack), exit(EXIT_FAILURE); }
	val = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = val;
	pop(stack, line_number);
}
