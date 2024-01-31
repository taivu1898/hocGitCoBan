#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int low, int high);

void quick_sort(int *arr, int low, int high);
void swap(int *a, int *b);
void display_array(int *, int);

int main() {
    int arr[] = {12, 18, 17, 20, 28, 29, 30},
        length = sizeof(arr) / sizeof(arr[0]);

    display_array(arr, length);
    printf("\n");

    quick_sort(arr, 0, length - 1);
    display_array(arr, length);
    return 0;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high],
        j = low - 1;
    
    for (int i = low; i < high; ++i) {
        if (arr[i] < pivot) {
            ++j;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[j + 1], &arr[high]);

    return j + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void display_array(int *arr, int length) {
    for (int i = 0; i < length; ++i) 
        printf("%d ", *(arr + i));
    printf("\n");
}