//head
//Lozov Petr
//15.11.12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 100

int verification(int, char **);
int output(char *, int);
char *read_str(FILE *, int *);
const char *ErrComm = "Incorrect command.";
const char *ErrPath = "Incorrect path.";
const char *Help = "Input 'head <-n [number]> <[path]>'.";

	
int main(int argc, char **argv)
{
	return verification(argc, argv);
}

int verification(int argc, char **argv)
{ 
	int n = 10, i;
	char *path = NULL;		
	if (argc > 4)
	{
		printf("%s\n%s\n", ErrComm, Help);
		return 1;
	}
	for (i = 1; i < argc; ++i)
	{
		if ((strcmp(argv[i], "-n") == 0) && (i != argc))
		{
			if ((atoi(argv[++i]) != 0) && (argv[i][0] != '-')) n = atoi(argv[i]);
			else
			{
				printf("%s\n%s\n", ErrComm, Help);
				return 1;
			}
		}
		else
		{
			if (path == NULL) path = argv[i];
			else
			{
				printf("%s\n%s\n", ErrComm, Help);
				return 1;
			}
		}
	}
	return output(path, n);
}

int output(char* path, int n)
{
	int i, j, symbol = 0;
	char **s;
	FILE *input;
	
	if (path == NULL) input = stdin;
	else input = fopen(path, "r");
	if (input == NULL)
	{
		printf("%s\n%s\n", ErrPath, Help);
		return 1;
	}
	s = (char**)malloc(sizeof(char*) * n);	
	for (j = 0; ((j < n) && (symbol != EOF)); ++j)
	{		
		s[j] = read_str(input, &symbol);
	}
	if (path == NULL) 
	{
		while ((symbol != EOF) && (symbol != 26)) symbol = fgetc(input);
		printf("\n\n");
	}
	for (i = 0; i < j; ++i) printf("%s\n", s[i]);
	fclose(input);
	return 0;
}

char *read_str(FILE *input, int *end_of_file)
{
	char *str;
	int symbol = 0, i;
	str = (char*)malloc(sizeof(char) * LEN_STR);
	for (i = 0; ((symbol != '\n') && (symbol != EOF)); ++i)
	{
		if ((i + 1) % LEN_STR == 0) str = (char*)realloc(str, sizeof(char) * (i + 1 + LEN_STR));
		symbol = fgetc(input);
		if (symbol == 26) symbol = EOF;
		if((symbol == EOF) || (symbol == '\n')) str[i] = 0;
		else str[i] = symbol;
	}
	*end_of_file = symbol;
	return str;
}