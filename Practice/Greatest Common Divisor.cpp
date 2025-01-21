#include <stdio.h>

int main()
{
	int a,b,c, greatest_divisor;
	scanf ("%d %d", &a, &b );
	while(a<=0 || a>100000 || b<=0 || b>100000)
	{
		printf ("Bad input. Hay nhap lai: ");
		scanf ("%d %d", &a, &b );
		
	}
	
	if(a<=b){
		c=a;
	}
	else {
		c=b;
	}
	for (int i=1; i<=c; i++){
		if (a%i==0 && b%i==0){
			greatest_divisor = i;
		}
	}
	printf ("%d", greatest_divisor);
	return 0;
	
}
