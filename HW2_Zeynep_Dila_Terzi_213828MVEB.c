#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "HW2_Zeynep_Dila_Terzi_213828MVEB.h"

int main(void)
{
	powerPlant *pPlant = NULL;
	statistic *pStat = NULL;
	
	char powerPlantFile[] = POWERPLANT_INPUT;
	char statisticsFile[] = STATISTICS_INPUT;
	
	int totalPowerPlants = ReadPowerPlant(&pPlant,powerPlantFile );
	int totalStats = ReadStatistics(&pStat, statisticsFile);
	int option;
	
	
	
	while (1)
	{
        printf("\n\nSelect your action!\n\n");
        printf("1. Display powerplants and their production logs. \n");
        printf("2. Edit the plant types. \n");
        printf("3. Edit the daily production values. \n");
        printf("4. Display the total power produced in the observed period. \n");
        printf("0. Exit\n");
        scanf("%u", &option);
        switch (option)
        {
            case 1:
            
				DisplayPowerPlantLogs(pPlant, totalPowerPlants, pStat, totalStats);
				break;
				
            case 2:
				EditPlantType(pStat, pPlant, totalPowerPlants, powerPlantFile);
				  
                break;
            case 3:
                EditDailyProduction(pStat, pPlant, totalStats, statisticsFile);
				break;
			case 4:
                DisplayTotalProduction(totalPowerPlants, pPlant,totalStats, pStat );
				break;
            case 0:
                return 0;
               
            default:
                printf("Only selections from 1 to 5 and 0 are accepted\n");
		}  
	}
	
	free(pPlant);
	free(pStat);
return 0;	
}

int ReadPowerPlant(powerPlant **pData, char *fileName)
{
    int count;
    
    int plantNo;
    int ratedCap;
	int avgCost;

	char plantName[LEN_NAME_MAX], plantType[LEN_NAME_MAX];
	
    powerPlant *pArr = NULL;
    powerPlant *pTemp = NULL;

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        perror("Error opening input file:");
        exit(EXIT_FAILURE);
    }
    
    count = 0;
    
    while (fscanf(fp, "%d %s %s %d %d", &plantNo, plantName,plantType,&ratedCap, &avgCost ) == 5)
    {
		pTemp = realloc(pArr, sizeof(powerPlant)*(count +1));
    
    
        if (pTemp == NULL)
        {
			free(pTemp);
			free(pArr);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
    
        pArr = pTemp;
        
        (pArr + count)->plantName = strdup(plantName);
        if ((pArr + count)->plantName == NULL)
        {
            fclose(fp);
            
        }
        (pArr + count)->plantType = strdup(plantType);
        
        if ((pArr + count)->plantType == NULL)
        {
           fclose(fp);
           
        }
 
		(pArr + count)->plantNo = plantNo;
		(pArr + count)->ratedCap = ratedCap;
		(pArr + count)->avgCost = avgCost;
		count++;
    }

    *pData = pArr;
 
    fclose(fp);
    
   
    return count;
 }
 

int ReadStatistics(statistic **pData, char *fileName)
{
	int count;
    
    int logID;
    int plantNo;
    int dailyProduction;
    int avgPrice;
    int day;
    int month;
    int year;
    //date logDate;

	
    statistic *pArr = NULL;
    statistic *pTemp = NULL;

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        perror("Error opening input file:");
        exit(EXIT_FAILURE);
    }
    count = 0;
    
    while (fscanf(fp, "%d %d %d %d %d.%d.%d", &logID, &plantNo, &dailyProduction, &avgPrice, &day, &month, &year) == 7)
    {
		pTemp = realloc(pArr, sizeof(statistic)*(count +1));
    
    
        if (pTemp == NULL)
        {
			free(pTemp);
			free(pArr);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
     
        pArr = pTemp;
        
 
		(pArr + count)->plantNo = plantNo;
		(pArr + count)->logID = logID;
		(pArr + count)->dailyProduction = dailyProduction;
		(pArr + count)->avgPrice = avgPrice;
		(pArr + count)->logDate.day = day;
		(pArr + count)->logDate.month = month;	
		(pArr + count)->logDate.year = year;
		count++;
    }
    
    *pData = pArr;
   
    fclose(fp);
    return count;
}

void DisplayPowerPlantLogs(powerPlant *pPowerPlant,int powerLen, statistic *pStatistics , int statisticLen)
{
	int match = 0;
	
	for(int i = 0; i < powerLen; i++)
	{
		printf("\n%d  No\tName\t  Type\tRated Cap. AvgCost\n", i+1);
		printf("  %-5d %-8s  %-10s %-6d %-6d \n", (pPowerPlant +i) -> plantNo, (pPowerPlant +i) -> plantName,
		(pPowerPlant +i) -> plantType, (pPowerPlant +i) -> ratedCap, (pPowerPlant +i) -> avgCost);
		printf("\n\t \tLog ID		Plant No	Daily Prod.	Avg Price \tDate \n");
			
		for(int j = 0; j < statisticLen; j++)
		{	
			
			if( (pPowerPlant +i) -> plantNo == (pStatistics +j) -> plantNo)
			{				 
				printf("\t\t%d		%d		%d		%d	%10d.%d.%d  \n", (pStatistics + j) -> logID, (pStatistics +j) -> plantNo, (pStatistics +j) -> dailyProduction,(pStatistics +j) -> avgPrice, 
				(pStatistics +j) -> logDate.day, (pStatistics +j) -> logDate.month, (pStatistics +j) -> logDate.year );
					match = 1;
			}
			if(match != 1) 
			{
				printf("no match found.\n");
			}
		
			
		}
		
	}
}
 
 
int EditPlantType(statistic *pStatistics, powerPlant *pPowerPlant, int len, char *fileName)
{
	char powerPlantNo[LEN_NAME_MAX];
	char dailyProductionID[LEN_NAME_MAX];
	char newPlantType[LEN_NAME_MAX];
	int input;
	int option;
	int i = 0;
	int match =0;
	
	while (1)
	{
        printf("\n\nSelect your action!\n\n");
        printf("1. Edit the plant type by entering the power plant number. \n");
        printf("2. Edit the plant type by entering the daily production ID. \n");
        printf("3. Return to the main menu.\n");
        printf("0. Exit the program. \n");
        scanf("%u", &option);
        switch (option)
        {
            case 1:
            
				printf(" Enter the power plant number: \n");
				scanf("%3s",powerPlantNo);
				while (powerPlantNo[i] != '\0') 
				{
					if (!isdigit(powerPlantNo[i]))
					{
						break;
					}
				i++;
				}
				if (powerPlantNo[i] != '\0')
				{
					perror("Input is not a number.\n");
					return 0;
				}
				
				input = atoi(powerPlantNo);
				for(i =0; i< len; i++)
				{
					if((pPowerPlant + i) -> plantNo == input)
					{
						printf("\t%d %s %s %d %d\n", (pPowerPlant + i) -> plantNo, 
						(pPowerPlant + i) -> plantName, (pPowerPlant + i) -> plantType, 
						(pPowerPlant + i) -> ratedCap, (pPowerPlant + i) -> avgCost);
						
						match = 1;
						break;	
					}
				}
				
				if (match == 0)
				{
					perror("There is no such plant number. \n");
					return 0;
				}
				
				printf("Enter the new plant type: \n");
				if(scanf(" %s", newPlantType ) == 1)
				{
					strcpy((pPowerPlant + i) -> plantType, newPlantType);
						
					printf("\t%d %s %s %d %d\n", (pPowerPlant + i) -> plantNo, 
					(pPowerPlant + i) -> plantName, (pPowerPlant + i) -> plantType, 
					(pPowerPlant + i) -> ratedCap, (pPowerPlant + i) -> avgCost);
					
						FILE *fp = fopen(fileName, "w");
						if (fp == NULL)
						{
							perror("Error opening input file. The edit was unsuccesful.");
							exit(EXIT_FAILURE);	
						}
						for( i=0 ; i< len; i++)
						{
							fprintf(fp, "\t%d %s %s %d %d \n", (pPowerPlant + i) -> plantNo, 
								(pPowerPlant + i) -> plantName, (pPowerPlant + i) -> plantType, 
								(pPowerPlant + i) -> ratedCap, (pPowerPlant + i) -> avgCost);
						}
						fclose(fp);
					}
				break;
				
            
            case 2:
             printf("Enter the daily production ID: \n");
             scanf("%3s",dailyProductionID);
				while (dailyProductionID[i] != '\0') 
				{
					if (!isdigit(dailyProductionID[i]))
					{
						break;
					}
				i++;
				}
				if (dailyProductionID[i] != '\0')
				{
					perror("Input is not a number.\n");
					return 0;
				}
				
				input = atoi(dailyProductionID);
				for(i =0; i< len; i++)
				{
					if((pStatistics + i) -> logID == input)
					{
						printf("\t%d %s %s %d %d\n", (pPowerPlant + i) -> plantNo, 
						(pPowerPlant + i) -> plantName, (pPowerPlant + i) -> plantType, 
						(pPowerPlant + i) -> ratedCap, (pPowerPlant + i) -> avgCost);
						
						match = 1;
						break;	
					}
				}
				
				if (match == 0)
				{
					perror("There is no such daily log ID. \n");
					return 0;
				}
				
					printf("Enter the new plant type: \n");
					if(scanf(" %s", newPlantType ) == 1)
					{
						strcpy((pPowerPlant + i) -> plantType, newPlantType);
						
						printf("\t%d %s %s %d %d\n", (pPowerPlant + i) -> plantNo, 
						(pPowerPlant + i) -> plantName, (pPowerPlant + i) -> plantType, 
						(pPowerPlant + i) -> ratedCap, (pPowerPlant + i) -> avgCost);
						
						FILE *fp = fopen(fileName, "w");
						if (fp == NULL)
						{
							perror("Error opening input file. The edit was unsuccesful.");
							exit(EXIT_FAILURE);	
						}
						for( i=0 ; i< len; i++)
						{
							fprintf(fp, "\t%d %s %s %d %d \n", (pPowerPlant + i) -> plantNo, 
								(pPowerPlant + i) -> plantName, (pPowerPlant + i) -> plantType, 
								(pPowerPlant + i) -> ratedCap, (pPowerPlant + i) -> avgCost);
						}
						fclose(fp);
					}
             
                break;
            case 0:
                exit(EXIT_SUCCESS);
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Only selections from 1 to 5 and 0 are accepted\n");
		}  
	}
}
int EditDailyProduction(statistic *pStatistics, powerPlant *pPowerPlant, int len, char *fileName)
{
	char powerPlantNo[LEN_NAME_MAX];
	char dailyProductionID[LEN_NAME_MAX];
	char newDailyProduction[LEN_NAME_MAX];
	int input;
	int trueDailyProd;
	int option;
	int i = 0;
	int match =0;
	
	while (1)
	{
        printf("\n\nSelect your action!\n\n");
        printf("1. Edit the daily production by entering the power plant number. \n");
        printf("2. Edit the daily production by entering the daily production ID. \n");
        printf("3. Return to the main menu.\n");
        printf("0. Exit the program. \n");
        
        scanf("%u", &option);
        switch (option)
        {
            case 1:
            
				printf(" Enter the power plant number: \n");
				scanf("%3s",powerPlantNo);
				while (powerPlantNo[i] != '\0') 
				{
					if (!isdigit(powerPlantNo[i]))
					{
						break;
					}
				i++;
				}
				if (powerPlantNo[i] != '\0')
				{
					perror("Input is not a number.\n");
					return 0;
				}
				
				input = atoi(newDailyProduction);
				for(i =0; i< len; i++)
				{
					if((pPowerPlant + i) -> plantNo == input)
					{
						printf("\t%d %d	%d %d %02d.%02d.%04d\n", (pStatistics + i) -> logID, 
						(pStatistics +i) -> plantNo, (pStatistics +i) -> dailyProduction,
					(pStatistics +i) -> avgPrice, (pStatistics +i) -> logDate.day, 
					(pStatistics +i) -> logDate.month, (pStatistics +i) -> logDate.year);
						
						match = 1;
						break;	
					}
				}
				
				if (match == 0)
				{
					perror("There is no such plant number. \n");
					return 0;
				}
				
				printf("Enter the new Daily Production: \n");
				while (newDailyProduction[i] != '\0')
				{
					if (!isdigit(newDailyProduction[i]))
					{
						break;
					}
				i++;
				}
				
				if (newDailyProduction[i] != '\0')
				{
					perror("Input is not a number.\n");
					return 0;
				}
				trueDailyProd = atoi(newDailyProduction);
				(pStatistics + i)-> dailyProduction = trueDailyProd;
				
				printf("\t%d %d	%d %d %02d.%02d.%04d\n", (pStatistics + i) -> logID, (pStatistics +i) -> plantNo, (pStatistics +i) -> dailyProduction,
				(pStatistics +i) -> avgPrice, (pStatistics +i) -> logDate.day, (pStatistics +i) -> logDate.month, (pStatistics +i) -> logDate.year);
	
				FILE *fp = fopen(fileName, "w");
						if (fp == NULL)
						{
							perror("Error opening input file. The edit was unsuccesful.");
							exit(EXIT_FAILURE);	
						}
						for( i=0 ; i< len; i++)
						{
							fprintf(fp,"\t%d %d	%d %d %02d.%02d.%04d\n", (pStatistics + i) -> logID, (pStatistics +i) -> plantNo, 
							(pStatistics +i) -> dailyProduction,(pStatistics +i) -> avgPrice, (pStatistics +i) -> logDate.day, 
							(pStatistics +i) -> logDate.month, (pStatistics +i) -> logDate.year);
						}
						fclose(fp);
					
				break;
				
            
            case 2:
             printf("Enter the daily production ID: \n");
             scanf("%3s",dailyProductionID);
				while (dailyProductionID[i] != '\0') 
				{
					if (!isdigit(dailyProductionID[i]))
					{
						break;
					}
				i++;
				}
				if (dailyProductionID[i] != '\0')
				{
					perror("Input is not a number.\n");
					return 0;
				}
				
				input = atoi(newDailyProduction);
				for(i =0; i< len; i++)
				{
					if((pStatistics + i) -> logID == input)
					{
						printf("\t%d %d	%d %d %02d.%02d.%04d\n", (pStatistics + i) -> logID, 
						(pStatistics +i) -> plantNo, (pStatistics +i) -> dailyProduction,
					(pStatistics +i) -> avgPrice, (pStatistics +i) -> logDate.day, 
					(pStatistics +i) -> logDate.month, (pStatistics +i) -> logDate.year);
						
						match = 1;
						break;	
					}
				}
				
				if (match == 0)
				{
					perror("There is no such plant number. \n");
					return 0;
				}
				
				printf("Enter the new Daily Production: \n");
				while (newDailyProduction[i] != '\0')
				{
					if (!isdigit(newDailyProduction[i]))
					{
						break;
					}
				i++;
				}
				
				if (newDailyProduction[i] != '\0')
				{
					perror("Input is not a number.\n");
					return 0;
				}
				trueDailyProd = atoi(newDailyProduction);
				(pStatistics + i)-> dailyProduction = trueDailyProd;
				
				printf("\t%d %d	%d %d %02d.%02d.%04d\n", (pStatistics + i) -> logID, (pStatistics +i) -> plantNo, (pStatistics +i) -> dailyProduction,
				(pStatistics +i) -> avgPrice, (pStatistics +i) -> logDate.day, (pStatistics +i) -> logDate.month, (pStatistics +i) -> logDate.year);
	
				FILE *fa = fopen(fileName, "w");
						if (fa == NULL)
						{
							perror("Error opening input file. The edit was unsuccesful.");
							exit(EXIT_FAILURE);	
						}
						for( i=0 ; i< len; i++)
						{
							fprintf(fa, "\t%d %d	%d %d %02d.%02d.%04d\n", (pStatistics + i) -> logID, (pStatistics +i) -> plantNo, 
							(pStatistics +i) -> dailyProduction,(pStatistics +i) -> avgPrice, (pStatistics +i) -> logDate.day, 
							(pStatistics +i) -> logDate.month, (pStatistics +i) -> logDate.year);
						}
						fclose(fa);
				
				break;
			
            case 0:
                exit(EXIT_SUCCESS);
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Only selections from 1 to 5 and 0 are accepted\n");
		}  
	}
}
void DisplayTotalProduction(int powerLen, powerPlant *pPowerPlant,  int statisticLen, statistic *pStatistics )
{
	productions production[powerLen] , temp;
	int i, j;
	int x, y;
	for (i = 0; i < powerLen; i++)
	{
		production[i].totalProduction = 0;
	}
	for (i = 0; i < powerLen; i++)
	{
		for (j = 0; j < statisticLen; j++)
		{
			if ((pPowerPlant + i)->plantNo == (pStatistics + j) -> plantNo)
			{	
				x = production[i].totalProduction;
				y = (pStatistics + j) -> dailyProduction;
				production[i].totalProduction = x + y;
				production[i].plantNo = (pPowerPlant + i)->plantNo;
			}
		}
	}
	
	for (i = 0; i < powerLen; i++)
	{
		for (j = i + 1; j < powerLen; j++)
		{
			if (production[i].totalProduction < production[j].totalProduction)
			{
				temp = production[i];
				production[i] = production[j];
				production[j] = temp;
			}
		}
	}
	
	printf("\t No \t name\t \t \t type\t \trapidCap\t \tavgCost\t TotalProduction \n");

 for (i = 0; i < powerLen; i++)
 {
	for (j = 0; j < powerLen; j++)
	{
		 if (production[i].plantNo == (pPowerPlant + j)->plantNo)
		{
			printf("\t%d\t %-20s %-20s %-20d %-20d %-20d \n", (pPowerPlant + j) -> plantNo, 
				(pPowerPlant + j) -> plantName, (pPowerPlant + j) -> plantType, 
				(pPowerPlant + j) -> ratedCap, (pPowerPlant + j) -> avgCost, production[i].totalProduction);
		}
	}
 }
}


