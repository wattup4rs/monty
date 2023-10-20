#ifndef _MAIN_H_
#define _MAIN_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points too the previous elements of the stack (or queue)
 * next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instructions_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global - global structure to use in the functions
 * @lifo: is stack or queue
 * @curr: current line
 * @content: line content
 * @head: doubly linked list
 * fdis: file descriptor
 * @buff: input text
 * @arg: value
 *
 * Description: doubly linked listnode structure for
 * stack, queues. LIFO. FIFO
 */
typedef struct global
{
	int lifo;
	unsigned int curr;
	char *arg;
	stack_t *head;
	FILE *fdis;
	char *content;
	char *buff;
} global;

extern global glob;

/* opcode_instructions*/
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int counter);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);

/* doubly linked list functions */
stack_t *add_queue(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
void free_list(stack_t *head);

/* get function */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* main */
void free_glob(void);

#endif
