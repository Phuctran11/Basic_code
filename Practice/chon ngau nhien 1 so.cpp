#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int N;
	scanf("%d \n", &N);
	if(1<=N<=10){
	
		 srand(time(NULL));
		for(int i=0; i<4; i++){
			
			
			int M=1+ rand() % 10;
			if(M=N){
				printf("%d-0 ", M);
			}
			else{
			
			if(M<N){
				printf("%d-1 ", M);
			}
			if(M>N){
				printf("%d--1 ", M);
			}
		}
		}
	}
	else{
	    printf("Hay nhap lai N: %d", N);
	}
	return 0;
}
