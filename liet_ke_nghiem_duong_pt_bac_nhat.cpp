#include <stdio.h>
#define Max 100

int n, M, T;
int heso[Max];
int x[Max];

void solution()
{
	for (int i = 1; i<=n; i++)
	{
		printf ("%d ", x[i]);
	}
	printf ("\n");
}


int check( int v, int k)
{
	if (k < n) return 1;
	return T + v == M;
}


void Try ( int k)
{
	for (int v = 1; v <= (M - T - (n - k)) / heso[k]; v++)
	{
		if ( check(v,k))
		{
			x[k] = v;
			T = T +x[k] * heso[k];
			if ( k == n) solution();
			else Try (k+1);
			T = T - x[k] * heso[k];
		}
	}
}

int main()
{
	
	T = 0;
	printf ("Nhap so nghiem can tim: ");
	scanf ("%d", &n);
	printf ("Nhap he so cua tung nghiem:\n");
	for (int i = 1; i<=n; i++)
	{
		scanf ("%d", &heso[i]);
	}
	printf ("Nhap tong phuong trinh: ");
	scanf ("%d", &M);
	Try(1);
	return 0;
	
}
