//Puti po reshotke
//Lozov Petr
//23.10.12


#include <stdio.h>

int kolvo(int, int);

int main()
{
	int i, j, res;
	scanf("%d", &i);
	scanf("%d", &j);
	printf("%d", kolvo(i, j));
	return 0;
}       

int kolvo(int i, int j)
{
	if ((!i) || (!j)) return 1;
	else return (kolvo(i, j - 1) + kolvo(i - 1, j));
}