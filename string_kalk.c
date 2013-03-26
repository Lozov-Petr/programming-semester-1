//String_kalk
//Lozov Petr
//23.11.12

#include <stdio.h>

typedef 
enum {PLUS, MINUS, MULT, DIV, NUMBER, OBRACE, CBRACE, ERROR, END}
lexem;

lexem currlexem;
char str[1000];
int value, currpos = 0, is_error = 0;

int Expr();
int Term();
int Factor();
void Next();

int main()
{
	int res;
	gets(str);
	Next();
	res = Expr();
	if (!is_error)
	{
		if (currlexem == END) printf("%d", res); 
		else printf("Incorrect expression.\n");
	}  
	return 0;	
}

void Next()
{
	value = 0;
	while (str[currpos] == ' ') ++currpos;
	switch(str[currpos])
	{
		case '+':
		currlexem = PLUS;
		break;
		case '-':
		currlexem = MINUS;
		break;
		case '*':
		currlexem = MULT;
		break;
		case '/':
		currlexem = DIV;
		break;
		case '(':
		currlexem = OBRACE;
		break;
		case ')':
		currlexem = CBRACE;
		break;
		case 0:
		currlexem = END;
		break;
		default :
		if ((str[currpos] >= '0') && (str[currpos] <= '9'))
		{
			currlexem = NUMBER;
			while ((str[currpos] >= '0') && (str[currpos] <= '9'))
			{
				value = value * 10 + str[currpos++] - '0';		
			}
		}
		else currlexem = ERROR;
	}
	if (currlexem != NUMBER) ++currpos;  	
}

int Expr()
{
	if (is_error) return 0;
	{
		int res;
		if (currlexem == MINUS)
		{

			Next();
			res = -Term();
		}
		else res = Term();
		while ((currlexem == PLUS) || (currlexem == MINUS))
		{
			lexem operation = currlexem;
			Next();
			if (operation == PLUS) res += Term();
			else res -= Term();
		}
		return res;
	}	
} 

int Term()
{
	if (is_error) return 0;
	{
		int res = Factor();
		Next();
		while ((currlexem == MULT) || (currlexem == DIV))
		{
			lexem operation = currlexem;
			int res_next;
			Next();
			res_next = Factor();
			if (operation == MULT) res *= res_next;
			else if (res_next) res /= res_next;
			else if (!is_error)
			{
				is_error = 1;
				printf("Cannot perform division by zero.");
				return 0;
			}
			Next();	
		}
		return res;
	}
}

int Factor()
{
	if (is_error) return 0;
	if (currlexem == NUMBER) return value;
	else if (currlexem == OBRACE) 
	{
		int res;
		Next();
		res = Expr();
		if (currlexem == CBRACE) return res;
		else if (!is_error)
		{
			is_error = 1;
			printf("Espected ')'.");
			return 0;
		}
	}
	else if (!is_error) 
	{
		is_error = 1;
		printf("Espected number or expression.");
		return 0;
	}
		
}