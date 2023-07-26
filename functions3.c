#include "monty.h"

/**
* pp_pint - prints the top element of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void pp_pint(stack_t **head, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

printf("%d\n", (*head)->n);
}

/**
* i_pchar - prints the char at the top of the stack,
* followed by a new line.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void i_pchar(stack_t **head, unsigned int counter)
{
stack_t *h = *head;

if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

if (h->n > 127 || h->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

printf("%c\n", h->n);
}

/**
* p_pally - prints the entire stack.
* @head: stack head
* @counter: not used
* Return: no return
*/
void p_pally(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
(void)counter;

while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}

/**
* d_nop - does nothing (no operation).
* @head: stack head
* @counter: line_number
* Return: no return
*/
void d_nop(stack_t **head, unsigned int counter)
{
(void)counter;
(void)head;
}

/**
* g_product - multiplies the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void g_product(stack_t **head, unsigned int counter)
{
stack_t *h = *head;
int len = 0, aux;

while (h)
{
h = h->next;
len++;
}

if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

h = *head;
aux = h->next->n * h->n;
h->next->n = aux;
*head = h->next;
free(h);
}
