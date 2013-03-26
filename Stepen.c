//Stepen
//Lozov Petr
//22.10.12


#include <stdio.h>

int stepen(int, int);

int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", stepen(a, b));
	return 0;
}       

int stepen(int a, int b)
{
	int i, res;
	res = 1;
	for (i = 0; i < b; i++) res *= a;
	return res;
}