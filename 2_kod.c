//2 predstavlenie
//Lozov Petr
//01.10.12


#include <stdio.h>

void dva(int);

int main()
{
	int n;
	scanf("%d", &n);
    	dva(n);
	return 0;
}

void dva(int n)
{
	int i;
	const int k = sizeof(int) * 8;
	for (i = 0; i != k; i++) printf("%d", ((n & (1 << (k - i - 1)))!= 0));
}