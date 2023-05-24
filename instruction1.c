#include "monty.h"

/**
 * push - add new node to the linked list
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int newvalue, i = 0;
	stack_t *newptr, *sptr = NULL;

	if (s.id2)
	{
		if (s.id2[i] == '-')
			i++;
		for (; s.id2[i]; i++)
		{
			if (s.id2[i] > 57 || s.id2[i] < 48)
			{	fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stuff(stack), exit(EXIT_FAILURE); }
		}
	}
	else
	{	fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stuff(stack), exit(EXIT_FAILURE); }
	newvalue = atoi(s.id2);
	newptr = malloc(sizeof(stack_t));
	if (newptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stuff(stack), exit(EXIT_FAILURE);
	}
	newptr->n = newvalue;
	newptr->prev = newptr->next = NULL;
	if (*stack == NULL)
	{	*stack = newptr;
		return; }
	if (!(s.queue))
	{	newptr->next = *stack;
		(*stack)->prev = newptr;
		*stack = newptr; }
	else
	{	sptr = *stack;
		while (sptr->next != NULL)
		{	sptr = sptr->next; }
		sptr->next = newptr;
		newptr->prev = sptr;
	}
}
/**
 * pall - print stack content
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr;

	ptr = *stack;
	while (ptr)
	{
		fprintf(stdout, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * pint - print the top most node in the linked list
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE); }
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * pop - remove the first node in the linked list
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	if (!(*stack == NULL))
		(*stack)->prev = NULL;
	free(ptr);
}
/**
 * swap - swap the first and 2nd node in the linked list
 * @stack: linked list
 * @line_number: line count in the file being read
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stuff(stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = val;
}
