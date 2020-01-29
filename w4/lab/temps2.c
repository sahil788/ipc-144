/*********************************************************
      Name:     Sahil Nimeshkumar Lapsiwala
      ID:       132-584-160
      Section:  M 
*********************************************************/
#include<stdio.h>

int main()

{
	int ndays=0,i;
	int high[10] = { 0 };
	int low[10] = { 0 };

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &ndays);
	printf("\n");
	while (ndays < 3 || ndays > 10)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &ndays);
	}
printf("\n");
	
	
        for (i = 0; i < ndays; i++)
		{
			
			printf("Day %d - High: ", i + 1);
			scanf("%d", &high[i]);
			printf("Day %d - Low: ", i + 1);
			scanf("%d", &low[i]);
			
			
		}
	
	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < ndays; i++)
	{
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}
	return 0;
}














