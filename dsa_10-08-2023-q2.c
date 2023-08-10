#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


float calculateMedian(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);

    if (size % 2 == 0) {
        int mid1 = arr[size / 2];
        int mid2 = arr[size / 2 - 1];
        return (float)(mid1 + mid2) / 2.0;
    } else {
        return (float)arr[size / 2];
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    float median = calculateMedian(arr, size);
    printf("Median: %.2f\n", median);

    return 0;
}