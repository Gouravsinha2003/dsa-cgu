#include <stdio.h>

int main(){
    int n, m;
    printf("Enter value of n : ");scanf("%d", &n);
    printf("Enter value of m : ");scanf("%d", &m);
    int array[n][m];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter value : ");scanf("%d", &array[i][j]);
            sum += array[i][j];
        }
        
    }

    printf("Sum is equalm to : %d", sum);
    
    return 0;
}