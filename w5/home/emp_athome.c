/*
Name: Sahil Nimeshkumar Lapsiwala
Student number:132584160
Email:snlapsiwala@myseneca.ca
Workshop: 5
Section: M
Date: 22/02/2017
*/
#include <stdio.h>
#define SIZE 4


// Declare Struct Employee
struct Employee
{
	int id;
	int age;
	double salary;
};


/* main program */
int main(void)
{
	struct Employee emp[SIZE] = { { 0 } };
	int option = 0,p=0,  flag = 0,i=0,  j = 0, number = 0, position = 0;
	printf("---=== EMPLOYEE DATA ===---\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	do {
		// Print the option list
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
			printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			// Exit the program

			break;
		case 1:
			// Display Employee Data
			// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for ( p = 0; p < SIZE && p >= 0; p++)
			{
				if (emp[p].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[p].id, emp[p].age, emp[p].salary);
				}
			}


			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;
		case 2:	// Adding Employee
				// @IN-LAB


			printf("Adding Employee\n");
			printf("===============");

			if (number < SIZE)
			{
				printf("\nEnter Employee ID: ");
				scanf("%d", &emp[number].id);
				if (emp[number].id > 0)
				{
					printf("Enter Employee Age: ");
					scanf("%d", &emp[number].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[number].salary);

					// Check for limits on the array and add employee 
					// data accordingly. 
					number++;
				}
			}
			else
			{
				printf("\nERROR!!! Maximum Number of Employees Reached\n");
			}


			break;
		case 3:
			do {
				printf("Update Employee Salary\n");
				printf("======================\n");
				printf("Enter Employee ID: ");
				scanf("%d", &j);
				for (i = 0; i < SIZE; i++) {
					if (j == emp[i].id) {
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);

						flag = 1;
					}
				}

			} while (flag != 1); break;

			break;
		case 4:
			
			do
			{
				printf("Remove Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &j);
				for ( i = 0; i < SIZE - 1; i++)
				{
					if (j == emp[i].id) {
						position = i;
					}
				}

				while (position < SIZE) 
				{
					if (position == SIZE - 1) 
					{
						emp[position].id = 0;
						emp[position].age = 0;
						emp[position].salary = 0;
					}
					else
					{
						emp[position] = emp[position + 1];
					}
					position++;
				}
				number--;

				printf("Employee %d will be removed\n", j);

			} while (SIZE < i);

			break;

		default:

			printf("ERROR: Incorrect Option: Try Again\n");

		}

        } while (option != 0);

	return 0;
}





// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements







// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   99999.99
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/
