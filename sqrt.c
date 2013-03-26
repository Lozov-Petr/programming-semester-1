//sqrt
//Lozov Petr
//22.10.12


#include <stdio.h>
#include <math.h>

float sqroot(float);
	
int main()
{
	float n;
	scanf("%f", &n);
	printf("%f", sqroot(n));
	return 0;
}

float sqroot(float n)
{
	int i;
	float sqr_n = n;
	if (n < 0)
	{
		printf("i * ");
		n = -n;
		sqr_n = n;
	}
	while (fabs((sqr_n * sqr_n / n) - 1) >= 0.000001) 
		sqr_n = 0.5 * (sqr_n + n / sqr_n);
	return sqr_n;
}