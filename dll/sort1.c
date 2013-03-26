#include "sort.h"

void sort(int *mass, int len_mass)
{
	int i, j;
	for (i = 0; i < (len_mass - 1); ++i)
	{
		for (j = (i + 1); j < len_mass; ++j)
		{
			if (mass[i] > mass[j])
			{
				int k = mass[i];
				mass[i] = mass[j];
				mass[j] = k;
			
			}
		}
	}
}

