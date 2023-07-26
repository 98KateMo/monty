#include "monty.h"

/**
* m_queue - sets the mode to queue (last in, first out).
* @head: stack head
* @counter: line_number
* Return: no return
*/
void m_queue(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 1;
}

/**
* plusqueue - adds a node to the tail of the stack.
* @n: new_value
* @head: head of the stack
* Return: no return
*/
void plusqueue(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->next = NULL;

if (aux)
{
while (aux->next)
aux = aux->next;
}

if (!aux)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
aux->next = new_node;
new_node->prev = aux;
}
}

/**
* x_dash - adds a node to the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void x_dash(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] > 57 || bus.arg[j] < 48)
flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

n = atoi(bus.arg);
if (bus.lifi == 0)
plusnode(head, n);
else
plusqueue(head, n);
}

/**
* j_pqws - prints the string starting at the top of the stack,
* followed by a new line.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void j_pqws(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}

/**
* a_pip - removes the top element from the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void a_pip(stack_t **head, unsigned int counter)
{
stack_t *h;

if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

h = *head;
*head = h->next;
if (h->next)
h->next->prev = NULL;

free(h);
}
