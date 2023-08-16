#include <stdio.h>

int main() 
{
    int scores[] = {85, 78, 92, 65, 89, 76, 94, 81, 87, 90, 72, 88, 95, 79, 83, 91, 70, 84, 86, 93};
    int n_Students =sizeof(scores)/sizeof(scores[0]);
    int passingThreshold=60,sum=0,highest=scores[0],i;
    for (i=0;i<n_Students;i++) 
	{
        sum=sum+scores[i];
        if (scores[i]>highest) 
		{
            highest=scores[i];
        }
    }
    float average=(float)sum/n_Students;
    int pass=0,fail=0;
    for (i=0;i<n_Students;i++) 
	{
        if (scores[i]>=passingThreshold) 
		{
            pass++;
        } else 
		{
            fail++;
        }
    }
    int gradeCount[5] = {0};
    for (i=00;i<n_Students;i++) 
	{
        if(scores[i]>=90) 
		{
            gradeCount[0]++;
        } 
		else if(scores[i]>=80) 
		{
            gradeCount[1]++;
        } 
		else if(scores[i]>=70) 
		{
            gradeCount[2]++;
        } 
		else if(scores[i]>=60) 
		{
            gradeCount[3]++;
        } 
		else 
		{
            gradeCount[4]++;
        }
    }
    printf("Average score: %.2f\n", average);
    printf("Highest score: %d\n", highest);
    printf("No. of students passed: %d\n", pass);
    printf("No. of students failed: %d\n", fail);
    printf("Grade distribution:\n");
    printf("O: %d\n", gradeCount[0]);
    printf("E: %d\n", gradeCount[1]);
    printf("A: %d\n", gradeCount[2]);
    printf("B: %d\n", gradeCount[3]);
    printf("F: %d\n", gradeCount[4]);
}