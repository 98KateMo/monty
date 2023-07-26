#include "monty.h"

val_t bus = {NULL, NULL, NULL, 0};
/**
* h_modulus - computes the rest of the division of the second
* top element of the stack by the top element of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void h_modulus(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execution(content, &stack, counter, file);
		}
		free(content);
	}
	release_stack(stack);
	fclose(file);
	return (0);
}

/**
* release_stack - frees a doubly linked list
* @head: head of the stack
*/
void release_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

/**
* execution - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: pointer to monty file
* @content: line content
* Return: no return
*/
int execution(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {{"push", x_dash}, {"pall", p_pally}, {"pint", pp_pint},
{"pop", a_pip}, {"swap", b_change}, {"add", c_plus}, {"nop", d_nop},
{"sub", e_minus}, {"div", f_quotient}, {"mul", g_product}, {"mod", h_modulus},
{"pchar", i_pchar}, {"pstr", j_pqws}, {"rotl", k_rotl}, {"rotr", l_rotr},
{"queue", m_queue}, {"stack", n_stacker}, {NULL, NULL}};
unsigned int i = 0;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[i].opcode && op)
{
if (strcmp(op, opst[i].opcode) == 0)
{
opst[i].f(stack, counter);
return (0);
}
i++;
}
if (op && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
release_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}

/**
* f_quotient - divides the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_quotient(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		release_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
