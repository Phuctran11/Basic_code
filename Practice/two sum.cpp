#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{    
    int  target, sum, size;
    int nums[size];
    scanf("%d %d", &size, &target);
    for(int i=0; i<(size-1); i++){
		scanf("%d \n", &nums[i]);
	}
   
        
    
    
    for(int i=0; i<(size-1); i++){
    	int sum=nums[i]+nums[i+1];
        if(sum==target){
        printf("[%d %d]", i, i+1);
    }
    	
	}
	return 0;


}

