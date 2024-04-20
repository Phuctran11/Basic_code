#include <stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	if(1<=n<=100){
	   for(int i=1; i<=n;i++)
	   {
	   	int N=i*i;
	   	printf("%d %d \n", i,N);
		   }	
	}
	else{
		printf(" ");
		
	}
	return 0;
}
