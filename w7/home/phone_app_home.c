/*
Name:Sahil Nimeshkumar Lapsiwala
Student number: 132584160
Email: snlapsiwala@myseneca.ca
Workshop: 7
Section: M
Date: 13/3/2017
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 3
void decompose(long long const phoneNum, int *areacode, int *prefix, int *lineNum);
int isValid(long long const validNum);

/* main program */
int main(void) {

	int option;
	int i = 0, number = 0, areacode = 0, prefix = 0, lineNum = 0;
	long long phoneNumber[SIZE] = { 0LL };

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;


		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for (i = 0; i < SIZE; i++)
			{
				if (phoneNumber[i] > 0)
				{
					decompose(phoneNumber[i], &areacode, &prefix, &lineNum);
					printf("(%3d)-%3d-%4d", areacode, prefix, lineNum);
					printf("\n");
				}
			}printf("\n");
			break;

		case 2:
			// Add a Phone Number
			// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");

			if (number < SIZE)
			{
				long long temp = 0;

				scanf(" %lld", &temp);
				int result = isValid(temp);
				if (result == 1) {
					phoneNumber[number] = temp;
					number++;
					printf("\n");
				}
				else {
					printf("ERROR!!! Phone Number is not Valid\n\n");
				}
			}
			else
			{
				printf("\nERROR!!! Phone Number List is Full");
			}
			break;

		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");
			break;
		}
	} while (option != 0);

	return 0;
}
void decompose(long long const phoneNum, int *areacode, int *prefix, int *lineNum)
{
	*areacode = phoneNum / 10000000;
	*prefix = (phoneNum % 10000000) / 10000;
	*lineNum = (phoneNum % 1000000) % 10000;
}
int isValid(long long const validNum)
{
	int areacode = 0, prefix = 0;

	areacode = validNum / 10000000;
	prefix = (validNum % 10000000) / 10000;
	if (((areacode == 416) || (areacode == 647) || (areacode == 905)) && ((prefix >= 100) && (prefix <= 999)))
	{
		return 1;
	}
	else
		return 0;
}