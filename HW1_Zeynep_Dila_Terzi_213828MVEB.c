#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HW1_Zeynep_Dila_Terzi_213828MVEB.h"
/**
 * Author:		Zeynep Dila Terzi
 * Created: 	03.03.2022
 * Last edit: 	06.03.2022
 * 
 * Description: This program reads name, group and age info of some animals
 * 				from a file. It finds and outputs the names and ages, 
 * 				starting from mammals, followed by birds, reptiles, fish 
 * 				and amphibians.
 */

int main(void)
{
	animals myAnimals[MAX]; // the struc. array to store every member of the file (until the desired max is reached)
	inputData(myAnimals); // this function will read and store from the input file and categorize animals according to their groups.
	
	printf("NAME\t\tAGE\n\n");
	// these will display each group's list on the screen.
	outputData(mammals, mammalLength);
	outputData(birds, birdsLength);
	outputData(reptiles, reptilesLength);
	outputData(fishes, fishesLength);
	outputData(amphibians, amphibiansLength);
	
	FILE *fOutput;
	
	// these will print the same list in the output file
	fOutput = fopen("HW1_Zeynep_Dila_Terzi_213828MVEB_OUTPUT.txt", "w");
	fprintf(fOutput,"\nNAME\t\t AGE\n\n");
	fclose(fOutput); 

	outputFile(mammals,  mammalLength);
	outputFile(birds, birdsLength);
	outputFile(reptiles, reptilesLength);
	outputFile(fishes, fishesLength);
	outputFile(amphibians, amphibiansLength);
	
return 0;	
}
/* Description:		Opens the input file and saves the data into an structure array at first.
 *					It then assigns each member of the same class to the same structure array. 
 * 					Prints an error message if the file can't be found, or if the lenght of
 * 					lines in the data is longer than expected.
 * 
 * Parameters:		animals animal[] - animals, structure array which includes name, 
 * 					group and age.
 * 
 * Return:			None.
 * 
 */
void inputData(animals animal[])
{
	int i = 0;
	int fileLength =0; 
	
	FILE *fData = fopen("HW1_Zeynep_Dila_Terzi_213828MVEB_INPUT.txt", "r");
	if(fData == NULL)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	
	while (fscanf(fData, "%s %s %d", animal[i].name, animal[i].group, &animal[i].age) == 3) // this will help us avoid scanning texts that are not in our format
	{
		i++;
		fileLength++;
		
		if (i >= MAX)
		{
			printf("File length limit reached, stopping reading\n");
			break;
		}
	}
	// this will match every class with their own animals 
	//structure. this will help us call each class faster. 
	for (i = 0; i < fileLength ; i++)
	{ 
		if(strcmp(animal[i].group, "Mammal") == 0) 
		{
			mammals[ mammalLength] = animal[i];	
			mammalLength++;
		}
		
		else if(strcmp(animal[i].group, "Birds") == 0)
		{	
			birds[birdsLength] = animal[i];	
			birdsLength++;
		}
		else if(strcmp(animal[i].group, "Reptile") == 0)
		{
			reptiles[reptilesLength] = animal[i];	
			reptilesLength++;
		}
		else if(strcmp(animal[i].group, "Fish") == 0)
		{
			fishes[fishesLength] =  animal[i] ;	
			fishesLength++;
		}
		else if(strcmp(animal[i].group, "Amphibian") == 0)
		{
			amphibians[amphibiansLength] = animal[i];
			amphibiansLength++;	
		}
	}
	fclose(fData);	
}

/* Description:		Prints the list of animals' names and ages in a table format. 
 * 					
 * 
 * Parameters:		animals animal[] - animals, structure array which includes name, 
 * 					group and age.
 * 					len - integer, lenght of lines in the input file.
 * 				
 * 
 * Return:			None.
 * 
 */
void outputData(animals animal[], int len)
{
 int i;
 for (i = 0; i < len; i++)
	{
		printf("%-15s %-10d \n",animal[i].name, animal[i].age);	
	}
}
/* Description:		Prints the list of animals' names and ages in a table format into a file.
 * 
 * Parameters:		animals animal[] - animals, structure array which includes name, 
 * 					group and age.
 * 					len - integer, lenght of lines in the input file.
 * 
 * Return:			None.
 * 
 */
void outputFile(animals animal[], int len)
{
	FILE *fOutput;
	int i;
	fOutput = fopen("HW1_Zeynep_Dila_Terzi_213828MVEB_OUTPUT.txt", "a");
	
	if(fOutput == NULL)
	{
		perror("Error opening the output file\n");
		exit(EXIT_FAILURE);	
	}
	
	for (i = 0; i < len; i++)
	{
		fprintf(fOutput,"%-15s %-10d \n",animal[i].name, animal[i].age);
	}
	fclose(fOutput); 
}





void printTime(FILE *fp,int timeInSecond)
{
	int h,m,s; 
	h = timeInSecond/3600;
	m = timeInSecond/60 - h*60;
	s = timeInSecond-h*3600-m*60;
	printf("%02d:%02d:%02d  ",h,m,s);
	if( fp != NULL)
	{
		fprintf(fp,"%02d:%02d:%02d  ",h,m,s);
	}
	
}
int ComparFuncStructTime(const void *x, const void *y)
{
	int a = ((rallyInfo*)x)->finishTime;
	int b = ((rallyInfo*)y)->finishTime;
	if(a==0)
	{
		return 1;
	}
	if( b== 0)
	{
		return -1;
	}
	return a-b;
}
