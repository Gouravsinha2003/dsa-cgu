#include <stdio.h>

int main(){
    float avg = 0;
    int array[10]; 

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]); 
        avg+=array[i];
    }

    printf("Average %.2f", avg/10);
    
    return 0;
}