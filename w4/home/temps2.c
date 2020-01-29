/*********************************************************
Name:     Sahil Nimeshkumar Lapsiwala
ID:       132-584-160
Section:  M
*********************************************************/
#include<stdio.h>
#define MAXDAYS 10
int main()

{
	int ndays = 0, i,num = 0, flag = 0;
	double avg = 0, temp=0;
	int high[MAXDAYS]= { 0 }, low[MAXDAYS] = { 0 };

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and %d, inclusive: ",MAXDAYS);
	scanf("%d", &ndays);

	while (ndays < 3 || ndays > 10)
	{
		printf("\nInvalid entry, please enter a number between 3 and %d, inclusive: ",MAXDAYS);
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
	       printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",ndays);
	          scanf("%d", &num);

		do
		{
                 
                   if (num >= 1 && num <= 4)
		     { 
			for (i = 0; i < num; i++)
			{
				temp += high[i] + low[i];
			}
			avg = (temp / (num * 2));
                        temp=0;
			printf("\nThe average temperature up to day %d is: %.2lf\n", num, avg);

			printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",ndays);
			scanf("%d", &num);
                }
		else if(num < 0)
		{
			printf("\nGoodbye!\n");
			flag = 1;
		}
		else
		{
			printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &num);
		}
		}while(flag == 0);
		

	    return 0;
}














