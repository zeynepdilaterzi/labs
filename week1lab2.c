#include<stdio.h>
/* advanced task
asks user for an integer and checks if its divisible with 3, 5.
*/

int main ()
{

int number;
printf("Enter a number to check: \n");
scanf("%d", &number);

if (number % 3 == 0 && number % 5 ==0)
{
	printf("%d is divisible by both 5 and 3. \n", number);
	
}
else if(number % 5 == 0)
{
	printf("%d is divisible by only 5. \n", number);
}
else if(number % 3 == 0)
{
	printf("%d is divisible by only 3. \n", number);
}
else
{
	printf("%d is not divisible with either 3 or 5. \n", number);
}
int multiplesOfThree, remainThree, multiplesOfFive, remainFive;

remainThree = number % 3;
multiplesOfThree = number / 3;

remainFive = number % 5;
multiplesOfFive = number / 5;

printf("by dividing %d with 3, we get %d multiples of 3",number, multiplesOfThree);
printf(" and a remainder of %d. \n",remainThree);

printf("by dividing %d with 5, we get %d multiples of 5",number, multiplesOfFive);
printf(" and a remainder of %d.\n", remainFive);

return(0);	
}
