
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf ("Please enter three Coefficients!");
	}
	else {
		double a = atof (argv[1]);
		double b = atof (argv[2]);
		double c = atof
		 (argv[3]);
		if (a == 0 )
		{
			if (b == 0 && c == 0)
			{
				printf ("phuong trinh co vo so nghiem.");
			}
			else if (b == 0 && c != 0)
			{
				printf ("phuong trinh vo nghiem.");
			}
			else {
				printf ("phuong trinh co mot nghiem duy nhat: %.3lf.", -c/b);
			}
		}
		else {
			int delta = b*b -4*a*c;
			if (delta < 0)
			{
				printf ("phuong trinh vo nghiem.");
			}
			else if (delta == 0)
			{
				printf ("phuong trinh co mot nghiem kep: %.3lf.", (-b)/(2*a));
			}
			else {
				double x1=(-b + sqrt(delta))/(2*a);
				double x2=(-b - sqrt(delta))/(2*a);
				printf ("phuong trinh co 2 nghiem phan biet: x1 = %.3lf ; x2 = %.3lf", x1, x2);
			}

		}
		return 0;
		
	}
}
