//Skobki
//Lozov Petr
//22.10.12

#include <stdio.h>

int main()
{
	char S[100];
	int i, j, res;
	gets(S);
	for (j = 0; S[j] != '\0'; j++);
	res = 0; 
	for (i = 0; i < j; i++)
	{
		if (S[i] == '(') res++;
		if (S[i] == ')') res--;
		if (res < 0) break;
	}
	if (res == 0) printf("Yes");
	else printf("No");
	return 0;
}