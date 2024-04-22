#include <stdio.h>

void swap( int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void check( int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if ( left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if ( right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        check( arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n/2 - 1; i>=0; i--)
    {
        
        check(arr, n, i);
    }

    for ( int i = n - 1; i>= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        check(arr, i, 0);
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
    int N = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, N);

    for (int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
