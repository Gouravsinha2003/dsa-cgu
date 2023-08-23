#include <stdio.h>

int main() {
    int i,j,k,N, M, P; 
    printf("Enter the number of classes: ");
    scanf("%d", &N);
    printf("Enter the number of students per class: ");
    scanf("%d", &M);
    printf("Enter the number of subjects: ");
    scanf("%d", &P);
    int grades[N][M][P];
    for (i=0; i<N; i++) 
	{
        for (j=0; j<M; j++) 
		{
            printf("\nEnter grades for Class %d, Student %d:\n", i+1, j+1);
            for (k=0; k<P; k++) 
			{
                printf("Enter grade for Subject %d: ", k+1);
                scanf("%d", &grades[i][j][k]);
            }
        }
    }
    for (i=0; i<N; i++) 
	{
        for (j=0; j<M; j++) 
		{
            printf("\nClass %d, Student %d:\n", i+1, j+1);
            for (k=0; k<P; k++) 
			{
                printf("Subject %d: %d\n", k+1, grades[i][j][k]);
            }
        }
    }
    return 0;
}
