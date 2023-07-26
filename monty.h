#ifndef MONTY_H
#define MONTY_H

/**
* Monty - A header file for the Monty language interpreter.
* Monty is an educational programming language that utilizes a stack
* data structure to perform various operations.
*/

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - Doubly linked list representation of a stack (or queue)
* @n: Integer value stored in the node
* @prev: Points to the previous element of the stack (or queue)
* @next: Points to the next element of the stack (or queue)
*
* Description: This structure defines the node of a doubly linked list
* used to implement the stack and queue data structures in the Monty
* interpreter.
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
* struct val_s - Variables arg, file, line content, and lifi flag
* @arg: Value of the argument
* @file: Pointer to the Monty file being processed
* @content: The content of the current line being executed
* @lifi: Flag indicating the current data structure mode (stack or queue)
*
* Description: This structure carries essential values throughout the program
* during the execution of Monty code.
*/
typedef struct val_s
{
char *arg;
FILE *file;
char *content;
int lifi;
} val_t;
extern val_t bus;

/**
* struct instruction_s - Opcode and its corresponding function
* @opcode: The opcode (operation code)
* @f: The function to handle the corresponding opcode
*
* Description: This structure defines an opcode and the associated function
* that will be executed when the opcode is encountered during Monty code
* execution.
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_reallocate(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *sheer_line(char *content);

void x_dash(stack_t **head, unsigned int number);
void p_pally(stack_t **head, unsigned int number);
void pp_pint(stack_t **head, unsigned int number);

int execution(char *content, stack_t **head, unsigned int counter, FILE *file);
void release_stack(stack_t *head);
void a_pip(stack_t **head, unsigned int counter);
void b_change(stack_t **head, unsigned int counter);
void c_plus(stack_t **head, unsigned int counter);
void d_nop(stack_t **head, unsigned int counter);
void e_minus(stack_t **head, unsigned int counter);
void f_quotient(stack_t **head, unsigned int counter);
void g_product(stack_t **head, unsigned int counter);
void h_modulus(stack_t **head, unsigned int counter);
void i_pchar(stack_t **head, unsigned int counter);
void j_pqws(stack_t **head, unsigned int counter);
void k_rotl(stack_t **head, unsigned int counter);
void l_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

void plusnode(stack_t **head, int n);
void plusqueue(stack_t **head, int n);
void m_queue(stack_t **head, unsigned int counter);
void n_stacker(stack_t **head, unsigned int counter);

#endif
