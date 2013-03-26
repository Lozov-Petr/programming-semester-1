#ifndef _stack_h
#define _stack_h

typedef struct stack
{
	int value;
	struct stack *next;
}
stack;

stack **new_stack();
void push(stack **, int);
int pop(stack **);
void duplicate(stack **);
void swap(stack **);
void free_stack(stack **);
int len_stack(stack **);
void operation(stack **, char);
#endif

