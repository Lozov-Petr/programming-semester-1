//Factorial Iter
//Lozov Petr
//22.10.12


#include <stdio.h>

int main()
{
	int n, res = 1, i;

	printf("Input N = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) res *= i + 1;
	printf("n! = %d", res);
	return 0;
}       