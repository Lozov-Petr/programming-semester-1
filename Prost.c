//Prime
//Lozov Petr
//22.10.12


#include <stdio.h>
int prov(int);
int prime[100], mass = 0;

int main()
{
	int n, res, number = 3;
	scanf("%d", &n);
	if (n > 2) res = 3;
	else res = n - 1;
	while (number < n)
	{
		if (prov(number) == 1) 
		{
			prime[mass] = number;
			mass++;			
			res += number;
		}
		number += 2;
	}
	printf("%d", res);
 return 0;
}       

int prov(int number)
{
	int i, k = 1;
	for (i = 1; i < mass; i++) if (number % prime[i] == 0) k = 0;
	return k;

}