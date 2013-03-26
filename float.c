//float
//Lozov Petr
//11.10.12

#include <stdio.h>

union float_int
{
	float f;
	int i;
};

void print_float(int);
int mantis(int);
void space(int);
int mant[22];

int main()
{
	union float_int fi;
	system("cls");
	scanf("%f", &fi.f);
	system("cls");
	print_float(fi.i);
	return 0;
}

void print_float(int n)
{
	int znak, exp, mant_length, i;
	znak =(n & (1 << 31));
	exp = ((n & (~(1 << 31))) >> 23) - 127;
	mant_length = mantis(n);
	
	if (exp == 128)
	{
		if (mant_length != 0) printf("NaN");
		else 
		{
			if (znak == 0) printf("Infinity"); 
			else printf("-Infinity");
		}
	}
	else
	{
		if ((exp == -127) && (mant_length == 0))
		{
			if (znak == 0) printf("0"); 
			else printf("-0");
		}
		else
		{
			if (znak == 0) printf("     %d\n1 * 2", exp);
			else printf("        %d\n(-1) * 2", exp);
			space(exp);
			if (mant_length == 0) printf("1");
			else
			{
				if (exp != -127) printf("1.%d", mant[0]);
				else 
				{
					if (mant_length == 1) printf("1");
					else printf("%d.", mant[0]);
				}
				for (i = 1; i < mant_length; i++) printf ("%d", mant[i]);
			}
		}		
	}
}

int mantis(int n)
{
	int i, lenght = 0;
	for (i = 0; i <= 22; i++)
	{
		if ((n & (1 << i)) != 0)
		{
			if (lenght == 0) lenght = 23 - i;
			mant[22 - i] = 1;
		}
		else mant[22 - i] = 0;
	}
	return lenght;
}

void space(int exp)
{
	if (exp < 0) printf(" ");
	exp = abs(exp);
	if (exp <= 9) printf(" * ");
	if ((exp >= 10) && (exp <= 99)) printf("  * ");
	if (exp >= 100) printf("   * ");
}