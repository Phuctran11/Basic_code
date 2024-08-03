#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
		//Tao 2 mang de in canh cua cay
	int n, length;
	char a4[1000000];
	int a1[n],a2[n];
	for(int i=0; i<n; i++){
		scanf("%d %d \n", &a1[i], &a2[i]);
	}

	//Tim bac cua tinh dinh tu 0->n+1
	int a3[n];
	int dem=0;
	for(int j=0; j<n; j++){
		for(int k=0; k<n+1; k++){
			if(a1[j]==k || a2[j]==k){
				a3[k]=dem+1;
			}
		}
	}
	
	//Tim tung dinh theo tich chat cua day prufer roi in ket qua
	
	for (int i=1; i<n; i++){
		if(a3[i]==1){
			for(int j=0; j<n; j++){
				if(a1[j]==i){
					sprintf(a4+strlen(a4), "%d ", a2[i]); //gan dinh tim duoc vao mang a4 da tao
					a3[i]=a3[i]-1;
					a3[a2[j]]=a3[a2[j]]-1;
					a1[j]=-10;
					a2[j]=-10;
					break;
				}
				if(a2[j]==i){
					sprintf(a4+strlen(a4), "%d ", a1[i]); ////gan dinh tim duoc vao mang a4 da tao
					a3[i]=a3[i]-1;
					a3[a1[j]]=a3[a1[j]]-1;
					a1[j]=-10;
					a2[j]=-10;
					break;
				}
			}
		}
	}
	 length = strlen(a4); 
    
        a4[length-3] = '\0'; //bo 3 ki tu cuoi cua mang a4 de duoc dong prufer code yeu cau
    
    printf("%s",a4); 
	return 0;
	
	
	
	
	
	
	
	
}


