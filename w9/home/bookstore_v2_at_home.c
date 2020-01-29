//  -------------------------------------------------
//  Name:       Sahil Nimeshkumar Lapsiwala
//  Email:      snlapsiwala@myseneca.ca
//  Workshop:   WS9_IN_LAB
//  Date:       2017-03-29
//  Section:    MM
//  -------------------------------------------------

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TITLE_SIZE 21


//Type the struct here
struct Book {
	int _isbn;
	float _price;
	int _year;
	int _qty;
	char _title[MAX_TITLE_SIZE];
};


//Type the function prototypes here
void menu();
void displayInventory(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
int searchInventory(FILE *fp, const int isbn2find);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);
void footer();


int main()
{

	//Type your code here:
	int val,isbn=0;
	float total;
	struct Book mybook;
	char filename[] = "inventory.txt";
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	do {
		menu();
		printf("Select: ");
		scanf("%d", &val);

		switch (val)
		{
		case 0:
			printf("Goodbye!\n");
			break;

		case 1:
			displayInventory(filename);
			break;

		case 2:
			printf("ISBN:");
			scanf("%d", &mybook._isbn);
			while (getchar() != '\n');
			printf("Title:");
			scanf("%20[^\n]", mybook._title);
			while (getchar() != '\n');
			printf("Year:");
			scanf("%d", &mybook._year);
			printf("Price:");
			scanf("%f", &mybook._price);
			printf("Quantity:");
			scanf("%d", &mybook._qty);
			addBook(filename, &mybook);
			break;
		case 3:
                        printf("Please input the ISBN number of the book:\n\n");
	                scanf("%d", &isbn);
	                checkPrice(filename,isbn);
			break;
		case 4:
			total = calculateCapital(filename);
			printf("The total capital is: $%.2f.\n", total);
			break;
		default:
			printf("Invalid input, try again:\n");
			break;
		}
	} while (val != 0);
	return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");

}


void displayInventory(const char filename[])
{
	//Define an object of struct Book
	struct Book mybook;

	//Open the file, and check for null pointer
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp != NULL)
	{

		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");


		while (readRecord(fp, &mybook) == 5)
		{
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", mybook._isbn, mybook._title, mybook._year, mybook._price, mybook._qty);
		}

		fclose(fp);
	}

	//If the file is properly opened, display headers, similar to workshop 8



	//Use a while loop to call readRecord and display the records.
	//while(/*call readRecord and check its return value*/)
	//display the record


	footer();
	//Display the footer
	//Close the file

}

void addBook(const char filename[], struct Book *b2Add)
{
	//struct Book mybook;

	FILE *fp = NULL;
	int found;
	////Open the file for appending (a+)
	fp = fopen(filename, "a+");

	////Type your code here
	

	found = searchInventory(fp, b2Add->_isbn);

	if (found !=-1)
	{
		printf("The book exists in the repository!\n\n");
	}

	else
	{
		fprintf(fp, "%d;%f;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
		printf("The book is successfully added to the inventory.\n\n");
	}
		
		fclose(fp);
}


void checkPrice(const char filename[], const int isbn2find)
{
	struct Book mybook;
	int found, flag=0;
	
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	
	found = searchInventory(fp, isbn2find);
	if (fp != NULL)
	{
		if(found == 1 && flag==0)
		{
			rewind(fp);
			while (readRecord(fp, &mybook) == 5)
			{
				if (isbn2find == mybook._isbn)
				{
					printf("Book %d costs $%.2f\n\n", isbn2find, mybook._price);
					flag = 1;
				}
			}
		}
		fclose(fp);
	}
	if (flag == 0)
	{
		printf("Book does not Exist\n\n");
	}
}

int searchInventory(FILE *fp, const int isbn2find)
{
	struct Book mybook;
	int val = -1;
	//Define an object of struct Book and other necessary variables
	if (fp != NULL)
	{
		while (readRecord(fp, &mybook) == 5)
		{
			if (mybook._isbn == isbn2find)
			{
				val = 1;
			}
		}
	}
	return val;
}

float calculateCapital(const char filename[])
{
	struct Book mybook;
	float total_capital = 0;
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL)
	{

		while (readRecord(fp, &mybook) == 5)
		{
			total_capital += (mybook._price)*(mybook._qty);
		}
	}

	//Define an object of struct Book

	//Define and initialize total_capital


	//Open the file, and check for null pointer


	//If the file is properly opened, use a while loop to call readRecord
	//while(/*call readRecord and check its return value*/)
	//Accumulate the multiplication of the price of each item to its quantity



	//Display the footer
	//footer();
	//Close the file
	fclose(fp);
	//return the total_capital
	return total_capital;
}

int readRecord(FILE *fp, struct Book *b2read)
{
	int rv = 0;

	rv = fscanf(fp, "%d;%f;%d;%d;%20[^\n]", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);


	return rv;
}
void footer()
{
	printf("===================================================\n\n");
}

