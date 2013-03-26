//Palindrom
//Lozov Petr
//22.10.12

#include <stdio.h>

char reg(char);
int corr(char);
char string[100];

int main()
{
	
	int a, i, j;
	gets(string);
	a = 1;
	i = 0;
	for(j = 0; string[j] != '\0'; j++);
	j--;
	while(j - i >= 1)
	{
		while(corr(string[i])) i++;
		while(corr(string[j]) && (j >= 1)) j--;
		if ((reg(string[i]) != reg(string[j])) && (j - i >= 1)) a = 0; 
		i++;
		j--;
	}
	if (a) printf("Yes");
	else printf("No");
	return 0;
}       



char reg(char q)
{
	if ((q >= 'A') && (q <= 'Z')) q += ('a' - 'A');
	return q;
}

int corr(char q)
{
	return ((q < '0') || ((q > '9') && (q < 'A')) || ((q > 'Z') && (q < 'a')) || (q > 'z'));
}