#include <stdio.h>

int main()
{
	
	int m, n, a, b;
	
	
	//doc ma tran 1
	scanf("%d %d", &m, &n);
	int arr1[m][n];
	for (int i = 0; i<m; i++)
	{
		for (int j = 0 ; j<n; j++)
		{
			scanf ("%d", &arr1[i][j]);
		}
	}
	
	
	//doc ma tran 2
	
	scanf("%d %d", &a, &b);
	int arr2[a][b];
	for (int i = 0; i<a; i++)
	{
		for (int j = 0 ; j<b; j++)
		{
			scanf ("%d", &arr2[i][j]);
		}
	}
	
	printf ("\n");
	//tinh phep nhan 2 ma tran
	int matrix[m][b];
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<b; j++)
		{
			matrix[i][j] = 0;
			for (int k = 0; k<n; k++)
			{
				matrix[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	
	
	//in ra ma tran can tim
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<b; j++)
		{
			printf ("%d ", matrix[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
