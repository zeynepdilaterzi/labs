#include <stdio.h>

int main(void)
{
	/*Task 1:

    Read 7 integers from the keyboard
    Ask user for two indexes.
        Check that they are within the array bounds before proceeding.
        Numeration must be the same as when asking for input
        Print the values corresponding to those indexes from the array for self-check
    Using those two values you found, find the following results
        Compare them, print out their relation to each other (e.g. is the first number smaller, greater or equal to the second)
        Create a division operation. The operation must be formed in a way, that the dividend is always greater (or equal to) the divisor. This means that if needed, they should be swapped around.
        Division answer must be given as a real number, 1 place after the comma
*/

#define countOfNumbers 7
#define countOfIndex 2
int numbers[7];	
int index[2];
int i;

for(i=0; i < countOfNumbers; i++)
{
	printf("input 7 numbers %d/7: \n", i+1);
	scanf("%d", &numbers[i] );
}
i=0; 

while(i < countOfIndex)
{
	printf("Input 2 index numbers %d/2\n", i+1);
	scanf("%d", &index[i]);	
	if(index[i]-1 >= countOfNumbers)
	{

	}
	else
	{
	i++;
	}
}
for(i=0; i < countOfIndex; i++)
{
	printf("The value for index %d is: %d \n", index[i], numbers[index[i]-1] );
}

float division; 
if(numbers[index[0]-1] > numbers[index[1]-1])
{	
	printf("\nThe first number is bigger than the second number.\n");
	division = (float)numbers[index[0]-1] / (float)numbers[index[1]-1];
	printf("division of these numbers is: %.1f", division);

}
else if(numbers[index[0]-1] == numbers[index[1]-1])
{
	printf("\nThe first number is equal to the second number. \n");
	printf("the result of the division of these numbers is: 1");
}
else if (numbers[index[0]-1] < numbers[index[1]-1])
{
	printf("\nThe first number is smaller than the second number.\n");
	division = (float)numbers[index[1]-1] / (float)numbers[index[0]-1];
	printf("division of these numbers is: %.1f", division);		
}
return 0;
	
}
