#include "sort.h"

void sort(int *mass, int len_mass)
{
	int i = 1, j = 2;
	while (i < len_mass)
	{
		if (mass[i - 1] >= mass[i])
		{
			i = j;
			++j;
		}
		else
		{
			int k = mass[i - 1];
			mass[i - 1] = mass[i];
			mass[i] = k;
			i--;
			if (i == 0)
			{
				 i = j;
				 j++;
			}
		}
	}
}

