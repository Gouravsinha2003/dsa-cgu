#include <stdio.h>

int main() 
{
    int M,N,i,j;
    printf("Enter the number of rows : ");
    scanf("%d",&N);
    printf("Enter the number of columns : ");
    scanf("%d",&M);
    int arr[N][M];
    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for(i=0;i<N;i++) 
	{
        for(j=0;j<M;j++) 
		{
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("DISPLAY THE THE MATRIX:\n");
    for (i=0;i<N;i++) 
	{
        for (j=0; j<M;j++) 
		{
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
int tr_array[M][N];
    for (i=0; i<M; i++) 
	{
        for (j=0; j<N; j++) 
		{
            tr_array[i][j]=arr[j][i];
        }
    }

    printf("\nTRANSPOSE OF THE GIVEN MATRIX:\n");
    for (i=0; i<M;i++) 
	{
        for (j=0; j<N; j++) 
		{
            printf("%2d ", tr_array[i][j]);
        }
        printf("\n");
    }


}
