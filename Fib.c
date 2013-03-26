//fibonacci
//Lozov Petr
//22.10.12


#include <stdio.h>

int main()
{
	int n, res = 0, i1 = 0, i2;
	scanf("%d", &n);
 	for (i2 = 1; i2 < n; i2 += i1) 
 	{
		i1 = i2 - i1;
		if (i2 % 2 == 0) res += i2;
 	}
 	printf("%d", res);
 	return 0;
}       