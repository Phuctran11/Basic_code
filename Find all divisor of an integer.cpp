#include <stdio.h>

int main()
{
	int n;
	scanf ("%d", &n);
	while (n<=0 || n>100000)
	{
		printf ("Bad input. Please re-enter input!");
		scanf ("%d", &n);
	}
	for (int i=n; i>=1; i--){
		if(n%i==0){
			printf ("-%d ", i);
		}
	}
	for (int i=1; i<=n; i++){
		if(n%i==0){
			printf ("%d ", i);
		}
	}
	return 0; 
}
