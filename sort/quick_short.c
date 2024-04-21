#include <stdio.h>

//doi cho 2 phan tu
void swaparr( int* m, int* n)
{
    int tmp = *m;
    *m = *n;
    *n = tmp;
}

//chia mang thanh 2 phan: phan ben trai nho hon gia tri pivot & phan ben phai lon hon gia tri pivot
// gia tri pivot duoc dat o giua 2 phan( pivot trong thuat toan nay se lay gia tri phan tu cuoi cua mang)
int partition(int arr[],int low,int high)
{
  int pivot=arr[high];// pivot được gán bằng giá trị phần tử cuối mảng
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    
    if(arr[j]<pivot)
    {
      
      i++;
      swaparr(&arr[i],&arr[j]);
    }
  }
  swaparr(&arr[i+1],&arr[high]);
  return (i+1);
}

//thực hiện hàm partition cho 2 bên phải và trái đến khi sắp xếp đúng thứ tự tăng dần
void quickSort(int arr[],int low,int high)
{
  
  if(low<high)
  {
    int pi=partition(arr,low,high);
    
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

int main()
{
    int n; 
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int m = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, m-1);
    for(int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}