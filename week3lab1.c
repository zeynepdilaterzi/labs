#include<stdio.h>

/*
 * Normal task
 * get 5 number add them and display the final results.
 * (do this with three loops no magical numbers!)
 */
int main ()
{
	printf("This program adds up to 5 numbers from the user. \n");
	printf("Subtotal will be shown until the final result is reached. \n");
	
	int i,number;
	int sum;
	#define COUNTOFNUMBERS 5
	
	sum = 0;
	
	for(i = 0; i < COUNTOFNUMBERS; i++)
	{

		printf("Give me a number %d/5 \n", i+1);
		scanf("%d",&number);
		sum = sum + number;	
	}
	
	printf("the sum is %d \n \n", sum);
	
	
	i = 0;
	sum = 0;
	while(i < COUNTOFNUMBERS)
	{
		printf("Give me a number %d/5 \n", i+1);
		scanf("%d",&number);
		sum = sum + number;
		i++;
	}
	printf("the sum is %d \n", sum);
	
	i = 0;
	sum = 0;
	do
	{
		printf("Give me a number %d/5 \n \n", i+1);
		scanf("%d",&number);
		sum = sum + number;
		i++;
	}
	while(i < COUNTOFNUMBERS);
	printf("the sum is %d", sum);
	
return(0);
}
