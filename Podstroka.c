//Kol-vo vhogdenii podstioki
//Lozov Petr
//22.10.12

#include <stdio.h>

int main()
{
	char S1[100], S2[100];
	int i, i1, d1, d2, vhod, r; 
	vhod = 0;
	gets(S1);
	gets(S2);
	for(d1 = 0; S1[d1] != '\0'; d1++);
	for(d2 = 0; S2[d2] != '\0'; d2++);
	d1 -= (d2 - 1);
	for(i = 0; i < d1; i++)
	{
		r = 1;
		for(i1 = 0; i1 < d2; i1++)
		{
			if (S1[i + i1] != S2[i1]) r = 0;
		}
		vhod += r;
	}
	printf("%d", vhod);
	return 0;
}