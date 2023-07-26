#include "monty.h"

/**
* plusnode - adds a node to the head of the stack.
* @head: head of the stack
* @n: new_value
* Return: no return
*/
void plusnode(stack_t **head, int n)
{
stack_t *new_node, *aux;

aux = *head;
new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

if (aux)
aux->prev = new_node;

new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;

*head = new_node;
}

/**
* c_plus - adds the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void c_plus(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't add, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

h = *head;
aux = h->n + h->next->n;
h->next->n = aux;
*head = h->next;
free(h);
}
