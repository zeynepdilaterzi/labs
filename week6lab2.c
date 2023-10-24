#include <stdio.h>
#define COUNT_OF_NUM 5
int main(void)
{
	int i, j, temp;
	int comp = 0;
	int num[COUNT_OF_NUM];
	
	printf("please enter %d numbers to be sorted: \n", COUNT_OF_NUM);

	for(i=0; i<COUNT_OF_NUM; i++)
	{
		scanf("%d",&num[i]);
	}
	
	int value =0;
	int secVal=0; 
	
	for(i=0; i<COUNT_OF_NUM -1; i++)
	{
		if(num[i] > num[i+1])
		{
			value++;		
		}
		else if(num[i] < num[i+1])
		{
			secVal++;
		}
	}
	// printf("\n value is %d \n secval is %d \n", value, secVal);
	
	if(value != 0 && secVal != 0)
	{
		for(i=0; i < COUNT_OF_NUM; i++) 
		{	
			for(j=0; j < COUNT_OF_NUM -i -1; j++)
			{
				if(num[j] > num[j+1])
				{
					temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
				}
			comp++;
			}
		} 
	}
	
	else  
	{
		printf("Numbers are already in order. \n");
	}
	
	printf("comparisons made: %d \n", comp);
	printf("Nums in acseding order: \n");
	
	for(i=0; i < COUNT_OF_NUM; i++)
	{
		printf("%d ", num[i]);
	}	
	printf("\nNums in descending order: \n");
	
	for(i= COUNT_OF_NUM -1; i >= 0; i--)
	{
		printf("%d ", num[i]);
	}
	
return 0;
}



