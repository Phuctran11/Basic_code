#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	scanf ("%d %d %d", &a, &b, &c);
	float x,x0, x1, x2, delta;
	if(a==0 && b==0 && c==0){
		printf ("INFINITE SOLUTIONS");
		
	}
	else if (a==0){
		if(b!=0){
			x=-c/b;
			printf ("%.2f", x);
		}
		else {
			printf ("NO SOLUTION");
		}
	}
	else if (a!=0) {
		delta=b*b-4*a*c;
		if (delta==0){
			x0=-b/(2*a);
			printf("%.2f", x0);
			
		}
		if (delta > 0){
			x1=(-b-sqrt(delta))/2;
			x2=(-b+sqrt(delta))/2;
			printf ("%.2f %.2f", x1, x2);
		}
		if (delta < 0){
			printf ("NO SOLUTION");
		}

	}
	return 0;
	
	
}

