#include <stdio.h>

void insertionSort(int a[], int array_size) {
    int i, j, last;
    for (i = 1; i < array_size; i++) {
        last = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > last)) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = last;
    }
}

int main() {
    int arr[] = {1, 2, 5, 7, 9, 3, 55, 0, 8, 66};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, size);

    printf("Mảng sau khi sắp xếp: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
