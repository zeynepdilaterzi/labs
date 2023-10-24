/*
 * Advanced tasks
All of the following tasks should be in the same file!
Task 1:
* Find the minimum and maximum value in the same loop
* Find the arithmetic mean, sum and product of the given numbers
* Display the mean with three places after the comma

Task 2:
* Instead of the greatest, find the two greatest numbers. Print out their positions. Do the same for smallest. You are not allowed to sort!
* Greatest and the second greatest cannot be the same numbers, even if multiple exist! Same for smallest numbers.

Task 3:
* Allow the user to specify how many numbers will be entered
* The absolute maximum is set to 50 numbers
* Limit the user’s input so that the user couldn’t overflow the array
* Variable length arrays (VLA) are forbidden!
* */

#include<stdio.h>
int main(void)
{

int i;
int limit;
int maxNum2Amount = 0;
int minNum2Amount = 0;

do
{	
	printf("Specify how many numbers will be entered: \n");
	scanf("%d", &limit);
}
while(limit > 50);

int input[limit];

for(i=0; i < limit; i++)
{
	printf("Enter %d digits %d/%d \n",limit, i+1, limit);
	scanf("%d", &input[i]);
}
int maxNum = input[0];
int minNum =input[0];	

int maxNum2 = input[0];

for(i=1; i < limit; i++)
{
	if( maxNum < input[i])
	{
		maxNum = input[i];
	}
	else if (minNum > input[i])
	{
		minNum = input[i];
	}
}	
printf("max number is: %d \n", maxNum);
printf("min number is: %d\n", minNum);
	int minNum2 = input[0];	
for(i=0; i < limit; i++)
{
	if( maxNum2 < input[i] && maxNum != input[i])
	{
		maxNum2 = input[i];
	}
}
for(i=0; i < limit; i++)
{
	if ( input[i]<minNum2 && input[i]>minNum)
	{
		minNum2 = input[i];
	}
}
printf("second max number is: %d \n", maxNum2);
printf("second min number is: %d\n", minNum2);

for (i = 0 ; i<limit ; i++)
{
	if (maxNum2 == input[i])
	{
		printf ("location of the second greatest number is: %d\n" , i+1);
		maxNum2Amount++;
	}
}
for (i = 0 ; i<limit ; i++)
{
	if (minNum2 == input[i])
	{
		printf ("location of the second smallest number is: %d\n" , i+1);
		minNum2Amount++;
	}
}	
int sum=0;
int product=1;

	for(i=0; i < limit; i++)
	{
		sum = sum + input[i];
		product= product * input[i];
	}
float mean;
mean = (float)sum / (float)limit;

printf("the sum of the numbers is: %d\n",sum);
printf("the product of the numbers is: %d\n",product);
printf("the mean of the numbers is: %.3f",mean);


return 0;
}





