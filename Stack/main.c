//kalk_main
//Lozov Petr
//20.11.12

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define LEN_STR 20

int string_is_number(char *);
void operation(stack **, char);
char *read_str(int *);

int main()
{
	stack **Stack = new_stack();
	for( ; ; )
	{
		char *str;
		int Len_stack = len_stack(Stack), is_EOF;
		str = read_str(&is_EOF);
		if (string_is_number(str)) push(Stack, atoi(str));
		else if (!strcmp(str, "swap"))
		{
		 	if (Len_stack >= 2) swap(Stack);
			else
			{
				printf("Not enough elements.\n");
				free_stack(Stack);
				return 1;
			} 
		}
		else if (!strcmp(str, "dup"))
		{
			if (Len_stack >= 1) duplicate(Stack);
			else
			{
				printf("Not enough elements.\n");
				free_stack(Stack);
				return 1;
			}
		}
		else if ((strlen(str) == 1) && ((str[0] == '+') || (str[0] == '-') || (str[0] == '*') || (str[0] == '/')))
		{
			if (Len_stack >= 2) operation(Stack, str[0]);
			else
			{
				printf("Not enough elements.\n");
				free_stack(Stack);
				return 1;
			}
		}
		else if (!strcmp(str, "print"))
		{
			if (Len_stack >= 1) printf("%d\n", pop(Stack));
			else
			{
				printf("Not enough elements.\n");
				free_stack(Stack);
				return 1;
			}
		}
		else if ((!strcmp(str, "exit")) || (is_EOF == EOF))
		{
			free_stack(Stack);
			return 0;
		}
		else
		{
			if (str[0] != 0)
			{
				printf("Incorrect expression.\n");
				free_stack(Stack);
				return 1;
			}
		}		                         
		  
	}	
}

int string_is_number(char *str)
{
	int str_len = strlen(str), i, bool = 1;
	for (i = 0; i < str_len; ++i) if ((str[i] < '0') || (str[i] > '9')) bool = 0;
	if (str_len == 0) bool = 0;
	return bool;
}

char *read_str(int *end_of_file)
{
	char *str;
	int symbol = 0, i;
	str = (char*)malloc(sizeof(char) * LEN_STR);
	for (i = 0; ((symbol != '\n') && (symbol != EOF)); ++i)
	{
		if ((i + 1) % LEN_STR == 0) str = (char*)realloc(str, sizeof(char) * (i + 1 + LEN_STR));
		symbol = fgetc(stdin);
		if((symbol == EOF) || (symbol == '\n')) str[i] = 0;
		else str[i] = symbol;
	}
	*end_of_file = symbol;
	return str;
}                                                                                 