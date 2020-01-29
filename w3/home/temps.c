/*
Name            :    Sahil Nmeshkumar Lapsiwala
Student number  :    132584160
Email           :    snlapsiwala@myseneca.com
Workshop        :    3
Section         :    M
Date            :    1/02/2017
*/

#include <stdio.h>

#define NUMS 4

int main()

{
	int total_high = 0, total_low = 0, i, highest_temp = 0, lowest_temp = 0, high_d = 0, low_d = 0;
	float total_avg = 0.0;
	printf("---=== IPC Temperature Analyzer ===---");
	for (i = 0; i < NUMS; i++)
	{
		int high, low;

		do {
			printf("\nEnter the high value for day %d: ", i+1 );
			scanf("%d", &high);
			printf("\nEnter the low value for day %d: ", i+1);
			scanf("%d", &low);
			if ((high < low) || (high > 40 || low < -40))
			{
				printf("\nIncorrect values,temperature must be in the range -40 to 40,high must be greater than low\n");
			}
			if (high > highest_temp)
			{
				highest_temp = high;
				high_d = i+1;
			}
			if (low < lowest_temp)
			{
				lowest_temp = low;
				low_d = i+1;
			}

		} while ((high < low) || (high < 40 && low < -40));

		total_high += high;
		total_low += low;
	}

	total_avg = total_high + total_low;
	total_avg = total_avg / (NUMS * 2);

	printf("\nThe average (mean) temperature was: %.2lf\n", total_avg);
	printf("The highest temperature was %d, on day %d\n", highest_temp, high_d);
	printf("The lowest temperature was %d, on day %d\n", lowest_temp, low_d);

	return 0;

}
