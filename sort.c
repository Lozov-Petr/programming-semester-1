//sort
//Lozov Petr
//22.10.12

#include <stdio.h>

int* add_mass();
void sort_mass(int*);
void print_mass(int*);
int n;

int main()
{
	int *mass;
	mass = add_mass();
	printf("\n");
	sort_mass(mass);
	print_mass(mass);
	free(mass);
	return 0;
}

int* add_mass()
{
	int *mass1, vvod = 1;
	mass1 = (int*)malloc(sizeof(int));
	for (n = 0; vvod != 0; n++)
	{
		scanf("%d", &vvod);	
		mass1 = (int*)realloc(mass1, (n + 1) * sizeof(int));
		mass1[n] = vvod;
		
	}
	n--;
	return mass1;
}

void sort_mass(int* mass1)
{
	int i, j, obmen;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (mass1[j] < mass1[i])
			{
				obmen = mass1[j];
				mass1[j] = mass1[i];
				mass1[i] = obmen;
			}
		}
 	}
}

void print_mass(int* mass1)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", mass1[i]);
	}
}