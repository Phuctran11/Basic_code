#include <stdio.h>
#include <math.h>

int isPrime (int x)
{
	int count = 0;
	for (int i=2; i<=sqrt(x); i++){
		if(x % i ==0){
			count++;
		}
	}
	if (count==0){
		return 1;
	}
	else {
		return 0;
	}
}



int main()
{
	int n,x;
	scanf ("%d", &n);
	if(n<=0){
		x=2;
	}
	else {
		x=n+1;
	}
	
	while ( isPrime(x)==0)
	{
		x++;
		
	}
	printf ("%d", x);
	return 0;
	
}
