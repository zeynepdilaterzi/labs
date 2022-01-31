/*
Download the swap.c base code
Create a program that reads two numbers and swaps them
Create two functions to read and swap the variable values. 
Look for the function comments in the base code! Write your functions underneath the comments, based on the description
Don’t forget to add the prototypes
Call those functions in the appropriate order
Print out the memory addresses you are manipulating! In total you need to print 6 memory addresses
2 in main, showing the original location
2 in swap, showing which memory locations you are manipulating
2 in read, showing to which memory locations you are storing the input
In the mini report, include the following answer to the question:
What conclusion can you make based on those memory addresses printed in different functions?
*/

/**
 * File:           swap.c
 * Author:         Risto Heinsar
 * Created:        19.08.2014
 * Last edit:      12.09.2018
 *
 * Description:    Partial lab code. Swaps the two numbers using pointers.
 */
 
#include <stdio.h>
void ScanInt(int*a, int*b);
void Swap(int *a, int *b);

// Write your prototypes for the functions here



int main(void)
{
    int x, y;
    
    // Write a line here to show the location of the x and y variable
    ScanInt(&x,&y);

    
    // Call your first function that scans for the values
   
    
    // printout just to verify that the numbers are scanned correctly.
    printf("Original values:\t  x=%3d and y=%3d\n", x, y);
    
    // Call your second function that swaps the numbers
 Swap(&x, &y);
    
    // a printout to verify the correctness of this swap
    printf("New: \t  x=%3d and y=%3d\n", x, y); 
   
    return 0;
}


/**
 * Description:    Scan for two integer values and store them to
 *                   locations passed as pointers. It will also print
 *                 out the two locations where the values are stored.
 *
 * Parameters:     a - int pointer, first value
 *                 b - int pointer, second value
 *
 * Notes:          Write this function yourself!
 *
 * Return:         none
 */
void ScanInt(int *a, int *b)
{
	
	
	printf(">");
	scanf("%d", a);
	printf(">");	
	scanf("%d", b);
	
	printf("the first value (%d) is stored in %p. \nthe second value (%d) is stored in %p. \n", *a ,&a, *b, &b  );
}
/**
 * Description:    Swaps the two values passed using pointers. It will
 *                 also print out the locations of the two variables
 *                 that are about to be swapped.
 *
 * Parameters:     a - int pointer, first value
 *                 b - int pointer, second value
 *
 * Notes:          Write this function yourself!
 *
 * Return:         none
 */
void Swap(int *a, int *b)
{
	int temp =0;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("the first value (%d) is stored in %p. \nthe second value (%d) is stored in %p. \n", *a ,&a, *b, &b  );
}
