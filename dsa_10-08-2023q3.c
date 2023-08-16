#include <stdio.h>

int main() 
{
  int temp_data[7] = {25, 28, 27, 30, 31, 29, 26},i;
  float average_temp=0;
  for(i=0;i<7;i++) 
  {
    average_temp=average_temp+temp_data[i]/7;
  }
  int hottest_day= temp_data[0];
  int coldest_day= temp_data[0];
  for (i=1;i<7;i++) 
  {
    if (temp_data[i]>hottest_day) 
	{
      hottest_day = temp_data[i];
    } 
	else if (temp_data[i]<coldest_day) 
	{
      coldest_day=temp_data[i];
    }
  }
  int temperature_range = hottest_day - coldest_day;
  
  printf("The average temperature is %.2f \n", average_temp);
  printf("The hottest day was %d \n ", hottest_day);
  printf("The coldest day was %d \n ", coldest_day);
  printf("The temperature range is %d \n ", temperature_range);
}