#include <stdio.h>

int main()
{
	int a,b;
	scanf ("%d %d", &a, &b);
	int perimeter=2*(a+b);
	int area = a*b;
	printf ("%d %d ", perimeter, area);
	return 0;
	
}
