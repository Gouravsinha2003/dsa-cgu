#include <stdio.h>
#include <math.h>

int main() {
  int n;
  float mean, sd, sum = 0.0;
  float arr[100];

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%f", &arr[i]);
  }

  
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  mean = sum / n;


  float variance = 0.0;
  for (int i = 0; i < n; i++) {
    variance += (arr[i] - mean) * (arr[i] - mean);
  }
  variance /= n;

  
  sd = sqrt(variance);

  
  printf("Mean: %.2f\n", mean);
  printf("Standard deviation: %.2f\n", sd);

  return 0;
}