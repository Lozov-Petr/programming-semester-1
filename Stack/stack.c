//kalk_stack
//Lozov Petr
//20.11.12

#include <stdio.h>
#include "stack.h"

stack **new_stack()
{
	stack **Stack;
	Stack = (stack **)malloc(sizeof(stack *));
	*Stack = NULL;
	return Stack;
}

void push(stack **Stack, int n)
{
	stack *element;
	element = (stack *)malloc(sizeof(stack));
	(*element).value = n;
	(*element).next = *Stack;
	*Stack = element;	
}

int pop(stack **Stack)
{
	int n =(**Stack).value;
	stack *element = (**Stack).next;
	free(*Stack);
	*Stack = element;
	return n;
}

void duplicate(stack **Stack)
{
	int n =(**Stack).value;
	push(Stack, n);
}

void swap(stack **Stack)
{
	int n = pop(Stack), m = pop(Stack);
	push(Stack, n);
	push(Stack, m);
}

void free_stack(stack **Stack)
{
	while (*Stack != NULL)
	{
		stack *element = (**Stack).next;
		free(*Stack);
		*Stack = element;		
	}   
	free(Stack);
}

int len_stack(stack **Stack)
{
	int len;
	stack *element = *Stack;
	for (len = 0; element != NULL; ++len) element = (*element).next;
	return len;
}

void operation(stack **Stack, char znak)
{
	int n = pop(Stack), m = pop(Stack);
	if (znak == '+') push(Stack, m + n);
	else if (znak == '-') push(Stack, m - n);
	else if (znak == '*') push(Stack, m * n);
	else if (znak == '/') push(Stack, m / n);
}
