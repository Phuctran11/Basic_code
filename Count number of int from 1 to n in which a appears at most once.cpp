#include <stdio.h>
#include <math.h>


int check(int a)
{
	
	int b[1000],c;
	int dem=0, i=0;
	
	while (a!=0){
		b[i]=a%10;
		a=a/10;
		i++;
		if(b[i-1]==1)
			{
				dem++;
			}
	}
		
	if (dem>1)
	  	{
		return -1;
		}
	else {
		return 0;
	}
		
	
	
}

int main(){
	int n;
	int count =0;
	scanf ("%d", &n);
	for (int i=1; i<=n; i++){
		if(check(i)==0){
			count++;
		}
	}
	printf ("%d", count);
	return 0;
	
}
