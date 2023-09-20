#include <stdio.h>

int factorial(int n) 
{
    if(n==0 || n==1) 
	{
        return 1;
    } else 
	{
        return n * factorial(n - 1); 
    }
}

int main() 
{
    int num;

    printf("ENTER A POSITIVE NUMBER: ");
    scanf("%d", &num);

    if (num < 0) 
	{
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(num);
        printf("FACTORIAL OF  %d IS %d.\n", num, result);

    }

}
