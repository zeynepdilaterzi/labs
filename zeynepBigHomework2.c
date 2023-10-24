/**
 * Author:          Zeynep Dila Terzi
 * Created:         25.11.2021
 * Modified:        28.11.2021
 * Description:     The program’s purpose is finding the competitors who got the three highest points from
 * 				    a photography competition and showing the disqualified ones.
 *                  
 */
#include <stdio.h>
#include <string.h>

// constants
#define MAX_LENGHT 15
#define MIN_LENGHT 3
#define DISQUALIFIED 0
#define TOPNUM 3


// function prototypes
int lenghts(int minVal, int maxVal);
void readArray(int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT] );
void display (int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT] );
void sort(int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT]);
void displayTopThree ( int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT]);
void displayDisqualified(int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT]);

int main (void)
{
	
	int lenght = lenghts(MIN_LENGHT, MAX_LENGHT);
	char names[MAX_LENGHT][MAX_LENGHT]; 
	float points[MAX_LENGHT];
	
	readArray(lenght, names, points);
	display(lenght, names, points);
	sort(lenght,names,points);
	displayTopThree(lenght, names, points);
	displayDisqualified(lenght, names, points); 

	return 0;
}
/**
 * Function to get a value in specified range. The range will be in between
 * the 2 passed integers. User will be prompted for a new value until
 * a suitable one is entered, after which the function will return the
 * specified value as an integer.
 */
 
int lenghts(int minVal, int maxVal)
{
	int lenght;
    do
    {
        printf("Enter the number of names between %d and %d\n", minVal, maxVal);
        scanf("%d", &lenght);
        if (lenght < minVal || lenght > maxVal)
            puts("I'm sorry, I can't handle that :(");
    }
    while (lenght < minVal || lenght > maxVal);
    return lenght;
}

/**
 * Fills in the names and points of the competitors.
 * Requires arrays where to store the data, function has no return.
 */
void readArray(int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT] )
{
	int i;
	printf("Enter the names and points, leave a space between them.\n");
	for(i=0; i<lenght; i++)
	{
		scanf("%s %f",names[i], &points[i] );
		
	}
}

/**
 * Prints the names of the competitors, function has no return.
 */

void display (int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT] )
{
	int i;
	printf("Photographers: ");
	for(i=0; i<lenght; i++)
	{
		printf("%s, ",names[i] );
		
	}
	puts("\n");
}

/**
 * Sorts the points of the competitors in descanding order, and then changes the order of the names.
 * Requiers arrays to store the data, function has no return.
 */

void sort(int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT])
{
	int i,j;
	float temp =0;
	char x[MAX_LENGHT];
	
	for (i = 0; i < lenght-1; i++)
	{
		for(j = 0; j < lenght-i-1; j++)
		{
			if(points[j] < points[j+1])
			{
				temp = points[j];
				points[j] = points[j+1];
				points[j+1] = temp;
				
				strcpy(x, names[j]);
				strcpy(names[j],names[j+1]);
				strcpy(names[j+1],x);
			}	
		}
	}
}
/**
 * Sorts the points of the competitors in descanding order, and then changes the order of the names.
 * Requiers arrays to store the data, function has no return.
 */

void displayTopThree ( int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT])
{
	int i = 0;
	printf("Top %d: \n", TOPNUM);
	for(i=0; i < TOPNUM ; i++)
	{
		printf("No%d: %s with %.1f points. \n",i+1, names[i], points[i]);
	}
}

/**
 * checks if there is any disqualification, and it prints the disqualified
 * competitors or prints "none" depending on the situation. Function has no return.
 * 
 */

void displayDisqualified(int lenght, char names[MAX_LENGHT][MAX_LENGHT], float points[MAX_LENGHT])
{
	int i;
	int x=0;
	printf("Disqualified: ");
	for(i=0; i<lenght; i++)
	{
		if(points[i] <= DISQUALIFIED)
		{
			printf("%s %.2f  ", names[i], points[i]);
			x=1;	
		}
	}
    if(x==DISQUALIFIED)
    {
		printf("none");
	}

}
