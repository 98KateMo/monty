#include "monty.h"

/**
* b_change - swaps the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void b_change(stack_t **head, unsigned int counter)
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
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

h = *head;
aux = h->n;
h->n = h->next->n;
h->next->n = aux;
}

/**
* e_minus - subtracts the top element from the second element.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void e_minus(stack_t **head, unsigned int counter)
{
stack_t *aux = *head;
int sus, nodes;

for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;

if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
release_stack(*head);
exit(EXIT_FAILURE);
}

aux = *head;
sus = aux->next->n - aux->n;
aux->next->n = sus;
*head = aux->next;
free(aux);
}

/**
* n_stacker - does nothing (no operation).
* @head: stack head
* @counter: line_number
* Return: no return
*/
void n_stacker(stack_t **head, unsigned int counter)
{
(void)head;
(void)counter;
bus.lifi = 0;
}

/**
* l_rotr - rotates the stack to the bottom.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void l_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *copy = *head;

if (*head == NULL || (*head)->next == NULL)
{
return;
}

while (copy->next)
{
copy = copy->next;
}

copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}

/**
* k_rotl - rotates the stack to the top.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void k_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
stack_t *tmp = *head, *aux;

if (*head == NULL || (*head)->next == NULL)
{
return;
}

aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}

tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}
