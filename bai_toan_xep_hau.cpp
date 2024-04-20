#include<stdio.h>
#include <math.h>
#define N 50

int n;
int x[N];

void solution(int x[])
{	
	int stt[n];
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			if (x[j] == i)
			{
				stt[i] = j;
			}
		}
	}
	int k = 1;
	for(int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			
			if (j == stt[k])
			{
				printf ("x ");
			}
			else {
				printf (". ");
			}
		}
		k++;
		printf ("\n");
	}

	
}

int check (int v, int k)
{
	for (int i = 1; i<=k-1; i++)
	{
		if (x[i] == v) return 0;
		if ( abs(x[i] - v) == abs(i - k)) return 0;
	}
	return 1;
}

void TRY (int k)
{
	for (int v = 1; v <= n; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			if (k == n) {
				solution(x);
				printf ("\n");
			}
			else TRY(k+1);
		}
	}
}


int main()
{
	scanf("%d", &n);
	TRY(1);
	return 0;
}
