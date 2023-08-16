#include <stdio.h>
#include <math.h>

int main(){
  int n;
  int xi;
  float x = 0.0;
  float variance;
  float sd;
  float sum = 0.0;

  printf("Number of elements to be entered :");
  scanf("%d", &n);

  int arr1[n];

  for (int i = 0; i<n; i++)
  {
      printf("enter number :");
      scanf("%d", &arr1[i]);

      xi = arr1[i];
      x = x+xi;
  }

  x = x/n;

  for(int i= 0; i < n; i++)
  {
    xi = arr1[i];
    sum += pow(xi-x,2);
  }

  variance = sum/(n-1);
  sd = pow(variance, 0.5);

  printf("\nMean = %f\nVariance = %f\nStandard deviation = %f", x, variance, sd);

  return 0;
}