#include <stdio.h>
#include <math.h>

int main()

{
    float sum=0;
    printf("Hay nhap 5 so nguyen: \n");
    float num[5];
    for(int i=0; i<5; i++){
        scanf("%f", &num[i]);
        sum=sum+num[i];
    }
    printf("%2f", sum/5);
    return 0;
}

