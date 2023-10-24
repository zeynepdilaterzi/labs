#include <stdio.h>

/*
Create a program based on the algorithm composed previously, add missing functionality.
Part 1:
* 6 numbers will be read from the keyboard and stored in an array
* Print out the contents of the array
* Find and print the smallest number
* Find and print the biggest number

Part 2:
* Print all positions where the smallest and the biggest number were
* Print how many times the smallest and biggest number existed in the array
* You must be consistent in your number positions 
*/
#define NUM_COUNT 6
int main (void)
{
	int nums[NUM_COUNT];
	int i;
	int maxNumAmount = 0;
	int minNumAmount = 0;
	
	
	printf("Enter 6 integers:\n");
	for (i=0; i<NUM_COUNT ; i++)
	{
		scanf("%d", &nums[i]);
	}
	
	int maxNum = nums[0];
	
	for (i = 0 ; i< NUM_COUNT; i++)
	{
		
		if (maxNum < nums[i])
		{
			maxNum = nums[i];
		}
	}
	printf("Maximum Number is: %d\n", maxNum);
	
	for (i = 0 ; i<NUM_COUNT ; i++)
	{
		if (maxNum == nums[i])
		{
			printf ("location is: %d\n" , i+1 );
			maxNumAmount++;
		}
	}
	
	if(maxNumAmount == 1)
	{
		printf("there was %d biggest number\n", maxNumAmount);
	}
	else 
	{
		printf("there were %d biggest numbers\n", maxNumAmount);	
	}
	
	int minNum = nums[0];
	for (i=0; i<NUM_COUNT; i++)
	{
		if (minNum > nums[i])
		{
			minNum = nums[i];
		}
	}
	printf("Minimum Number is: %d\n" , minNum);
	
	for (i = 0 ; i<NUM_COUNT ; i++)
	{
		if (minNum == nums[i])
		{
			printf ("location is %d\n" , i+1);
			minNumAmount++;
		}
	}
	if(minNumAmount == 1)
	{
		printf("there was %d smallest number\n", minNumAmount);
	}
	else 
	{
		printf("there were %d biggest numbers\n", maxNumAmount);	
	}
	printf("The number stored in the arrey are:\n");
	for (i = 0 ; i< NUM_COUNT; i++)
	{
		printf("%d\n", nums [i]);
	}
	printf("Maximum Number is: %d\nMinimum Number is: %d\n" , maxNum, minNum);
	return 0;
}
