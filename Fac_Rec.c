//Factorial Rec
//Lozov Petr
//22.10.12


#include <stdio.h>

int rec(int);

int main()
{
	int n;
	
	printf("Input n = ");
	scanf("%d", &n);
	printf("n! = %d", rec(n));
	return 0;
}       

int rec(int n)
{
	if (n == 0) return 1;
	else return n * rec(n - 1);
}