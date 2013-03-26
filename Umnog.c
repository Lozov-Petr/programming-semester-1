//Umnogenie bez znaka *
//Lozov Petr
//22.10.12


#include <stdio.h>
int umnog(int, int);

int main()
{
 int a, b;
 scanf("%d", &a);
 scanf("%d", &b); 
 printf("%d", umnog(a, b));
 return 0;
}       

int umnog(int a, int b)
{
	int i, res = 0;
	for ( i = 0; i < abs(b); i++)
	{
		if (b > 0) res += a;
		else res -= a;
	}
	return res;
	
}