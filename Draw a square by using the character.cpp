#include <stdio.h>

int main()
{
	int n;
	scanf ("%d", &n);
	int square[n][n];
	for (int i=0; i<n; i++)
	{
		printf("*");
	}
	printf ("\n");
	for (int i=0; i<=n-3; i++){
		for (int j=0; j<n; j++){
			if(j==0 || j==n-1){
				printf ("*");
			}
			else {
				printf (" ");
			}
		}
		printf ("\n");
	}
	
	for (int i=0; i<n; i++)
	{
		printf("*");
	}
	return 0;
}
