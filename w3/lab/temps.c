/*
Name            :    Sahil Nmeshkumar Lapsiwala
Student number  :    132584160
Email           :    snlapsiwala@myseneca.com
Workshop        :    3
Section         :    M
Date            :    1/02/2017
*/

#include<stdio.h>

#define NUMS 3

int main()

{
	int TOTAL_HIGH = 0, TOTAL_LOW = 0, i;
	float TOTAL_AVG = 0;
	printf("---=== IPC Temperature Analyzer ===---");
	for (i = 1; i <= NUMS; i++)
	{
		int HIGH, LOW;

		do {
			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &HIGH);
			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &LOW);
			if (HIGH < LOW || HIGH > 40 || LOW < -40)
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			}

		} while (HIGH < LOW || HIGH > 40 || LOW < -40);

		TOTAL_HIGH += HIGH;
		TOTAL_LOW += LOW;
	}

	TOTAL_AVG = TOTAL_HIGH + TOTAL_LOW;
	TOTAL_AVG = TOTAL_AVG / (NUMS * 2);

	printf("\nThe average (mean) temperature was: %.2lf\n", TOTAL_AVG);
      return 0;

}



















