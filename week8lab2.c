#include <stdio.h>
#include <stdbool.h>

#define SORTING_FACILITY_SIZE 10

int main(void)
{
    int i, j, temp, totalCargo, totalInSorting;
    bool sorted;
    
    int storageA[] = {17, 4, 9, 15, 2, 11, 44};
    int storageB[] = {15, 9, 2, 13, 1};
    int sortingFacility[SORTING_FACILITY_SIZE];
    
    int totalA = sizeof(storageA) / sizeof(int);
    int totalB = sizeof(storageB) / sizeof(int);

    totalCargo = totalA + totalB;

	/* initial data print */
    printf("Warehouse A contains:\n");
    for (i = 0; i < totalA; i++)
    {
        printf("%d ", storageA[i]);
    }
    printf("\n\n");
    
    printf("Warehouse B contains:\n");
    for (i = 0; i < totalB; i++)
    {
        printf("%d ", storageB[i]);
    }
    printf("\n\n");


    /* printing informaton about if all items will fit or not */
    if (totalCargo < SORTING_FACILITY_SIZE)
    {
        printf("All %d item(s) will be shipped to sorting", totalCargo);
    }
    else
    {
        printf("Only %d / %d items will be shipped to sorting",
            SORTING_FACILITY_SIZE, totalCargo);
    }
    printf("\n\n");


    /* copying all the items from the initial storages to the sorting facility (third array)*/
    totalInSorting = 0;
    for (i = 0; i < totalA && totalInSorting < SORTING_FACILITY_SIZE; i++)
    {
        sortingFacility[totalInSorting] = storageA[i];
        totalInSorting++;
    }
    for (i = 0; i < totalB && totalInSorting < SORTING_FACILITY_SIZE; i++)
    {
        sortingFacility[totalInSorting] = storageB[i];
        totalInSorting++;
    }


	/* test print to see if it everything was copied over successfully */
    printf("Entry order to the sorting facility:\n");
    for (i = 0; i < totalInSorting; i++)
    {
        printf("%d ", sortingFacility[i]);
    }
    printf("\n\n");
    
	
    /* sorting the elements in the descending order */
    for (i = 0, sorted = false; !sorted; i++)
    {
        /* assume that the array is sorted unless any swaps happen */
        sorted = true;
        
        for (j = 0; j < totalInSorting - 1 - i; j++)
        {
            if (sortingFacility[j] < sortingFacility[j + 1])
            {
                temp = sortingFacility[j];
                sortingFacility[j] = sortingFacility[j + 1];
                sortingFacility[j + 1] = temp;
                /* since we had to swap something, it was not sorted */
                sorted = false;
            }
        }
    }

	/* printing the result of the program */
    printf("Exit order to the sorting facility:\n");
    for (i = 0; i < totalInSorting; i++)
    {
        printf("%d ", sortingFacility[i]);
    }
    printf("\n\n");

    return 0;
}
