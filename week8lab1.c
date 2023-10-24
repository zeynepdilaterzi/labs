#include <stdio.h>
// this is the first function
int readnum(int min, int max);
void readArr(int array[], int arrayLen);
void printingArr(int array[], int arrayLen);
float aritMean(int array[],int arrayLen);
int minVal(int array[], int arrayLen);
int checkVal(int array[], int arrayLen, int value);
#define countOfNum 5
#define MIN -100
#define MAX 100
int i;



int main(void)
{
	
	 int array[5];
	 int x,y;
	
	readArr(array, 5);
	printingArr(array,5);
	x = minVal(array,5);
	printf("\n en kucugu %d", x);
	aritMean(array, 5);
	y = checkVal(array, 5, 7);
	printf("%d 7 icinde mi", y);
	
	return 0;
	}
// this function asks for a number stores it if it's in the right range.
int readnum(int min, int max)
{	
	int num;
	printf("Give me a number \n" );
	do
	{
		scanf("%d", &num);
	}
	while(min > num || max < num);
	return num;
	}
// this 
void readArr(int array[countOfNum], int arrayLen)
{	
	for(i=0; i < arrayLen ; i++)
	{	
		array[i] = readnum(MIN,MAX);
	}
}
void printingArr(int array[countOfNum], int arrayLen)
{
	for(i=0; i < arrayLen ; i++)
	{	
		printf("%d \n", array[i]);
	}
}
float aritMean(int array[countOfNum], int arrayLen)
{
	float mean;
	int sum=0;
	for(i=0; i <arrayLen; i++)
	{
		sum = sum + array[i];
	}
	mean = (float)sum / (float)arrayLen;
	return mean;
}
int minVal(int array[countOfNum],int arrayLen)
{
	int minVal = array[0];
	for(i=0; i < arrayLen; i++)
	{	
		if(minVal > array[i])
		{
			minVal = array[i];
		}	
	}
	
	return minVal;	
}
int checkVal(int array[], int arrayLen, int value)
{

	for(i=0; i< arrayLen; i++)
	{
		if(array[i] == value)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
}
