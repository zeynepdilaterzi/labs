/**
 * File:        HW2_Zeynep_Dila_Terzi_213828MVEB.h
 * Author:      Zeynep Dila Terzi
 * Created:     13.04.2022
 *
 * Description: 
 */
#ifndef HEADER_FILE
#define HEADER_FILE

#define POWERPLANT_INPUT "HW2_Zeynep_Dila_Terzi_213828MVEB_data_power_plants.txt"
#define STATISTICS_INPUT "HW2_Zeynep_Dila_Terzi_213828MVEB_data_power_production.txt"
#define LEN_NAME_MAX 50 

typedef struct
{
	int day;
	int month;
	int year;
}date;

typedef struct
{
	int plantNo;
	char *plantName;
	char *plantType;
	int ratedCap;
	int avgCost;
	
}powerPlant;

typedef struct
{
	int logID;
	int plantNo;
	int dailyProduction;
	int avgPrice;
	date logDate;
}statistic;
typedef struct
{
	int totalProduction;
	int plantNo;
}productions;


int ReadPowerPlant(powerPlant **pData, char *fileName);
int ReadStatistics(statistic **pData, char *fileName);
void DisplayPowerPlantLogs(powerPlant *pPowerPlant,int powerLen, statistic *pStatistics , int statisticLen);
int EditPlantType(statistic *pStatistics, powerPlant *pPowerPlant, int len, char *fileName);
int EditDailyProduction(statistic *pStatistics, powerPlant *pPowerPlant, int len, char *fileName);
void DisplayTotalProduction(int powerLen,powerPlant *pPowerPlant, int statisticLen, statistic *pStatistics);
#endif

