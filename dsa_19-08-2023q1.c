#include <stdio.h>

int main() {
    int N, M;

    printf("Enter the number of rows (N): ");
    scanf("%d", &N);

    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    int array[N][M];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Calculate the sum of all elements
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += array[i][j];
        }
    }

    printf("Sum of all elements in the array: %d\n", sum);

    return 0;
}
