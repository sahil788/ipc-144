/*
Name:Sahil Nimeshkumar Lapsiwala 
Student number: 132584160
Email: snlapsiwala@myseneca.ca
Workshop: 7
Section: M
Date: 13/3/2017
*/

#include <stdio.h>
#define SIZE 3
void decompose(long long const t, int *t1, int *t2, int *t3);

void decompose(long long const t, int *t1, int *t2, int *t3)
{
	*t1 = t / 10000000;
	*t2 = (t % 10000000) / 10000;
	*t3 = (t % 1000000) % 10000;
}


/* main program */
int main(void) {

	int option;
	int i = 0, number = 0, t1 = 0, t2 = 0, t3 = 0;
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
				if (phoneNumber[i] > 0) {
					decompose(phoneNumber[i], &t1, &t2, &t3);
					printf("(%3d)-%3d-%4d\n", t1, t2, t3);
				}
			}
			printf("\n");

			break;


		case 2:	
			// Add a Phone Number
			// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");
			if (number < SIZE)
			{
				scanf(" %lld", &phoneNumber[number]);
				number++;
				printf("\n");
			}
			else
			{
				printf("ERROR!!! Phone Number List is Full\n\n");
			}
			break;

		default:
			printf("Incorrect option, Please try again!! \n");
			break;
		}
	} while (option != 0);

	return 0;
}