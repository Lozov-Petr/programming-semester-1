#include <stdio.h>
#include "sort.h"

void print_mass(int*, int);

int main()
{
	int *mass, len_mass, i;
	printf("Input length mass: ");
	scanf("%d", &len_mass);
	mass = (int*)malloc(sizeof(int) * len_mass);
	for (i = 0; i < len_mass; ++i)
	{
		scanf("%d", &mass[i]);
	}
	sort(mass, len_mass);
	printf("\n\n");
	print_mass(mass, len_mass);
	return 0;
}

void print_mass(int *n, int len_mass)
{
	int i;
	for (i = 0; i < len_mass; ++i)
	{
		printf("%d\n", n[i]);
	}
}

