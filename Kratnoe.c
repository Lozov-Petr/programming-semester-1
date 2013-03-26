//least common multiple
//Lozov Petr
//23.10.12


#include <stdio.h>


int GCD(int, int);
int LCM(int);

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", LCM(n));
	return 0;
}       

int LCM(int n)
{
	int res = 1, i;
	for (i = 2; i <= n; i++) res *= i / GCD(i, res);
	return res;
}

int GCD(int a, int b)
{
	if (b) return GCD(b, a % b);
	return a;
}