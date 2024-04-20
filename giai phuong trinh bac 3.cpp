#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	scanf ("%d %d %d", &a, &b, &c);
	int num[3], multi[3];
	int j = 0;
	for (int i = -500; i<= 500; i++)
	{
		if ( (pow(i, 3) + a*pow(i, 2) + b*i + c) == 0)
		{
			num[j] = i;
			if ( (pow(i,2) + (a + i)*i-c/i) == 0)
			{
				multi[j] = 2;
			}
			else {
				multi[j] = 1;
			}
			j++;
		}
		else {
			continue;
		}
	}
	
	if ( num[0] == 0 && num[1] == 0 && num[2] == 0)
	{
		printf ("NO SOLUTION");
	}
	else {
		for (int i = 0; i<3; i++)
		{
			if (num[i] != 0)
			{
				printf("%d %d\n", num[i], multi[i]);
			}
		}
	}
	return 0;
}
