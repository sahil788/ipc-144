	/*
	Name: Sahil Nimeshkumar Lapsiwala
	Student number: 132584160
	Email: snlapsiwala@myseneca.ca
	Workshop: 8
	Section: M
	Date:22/03/2017
	*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define _CRT_SECURE_NO_WARNINGS
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 21
	struct Book {
	int _isbn;
	double _price;
	int _year;
	char _title;
	int _qty;
};
void menu();
void displayInventory(const struct Book book[], const int size);
void searchInventory(const struct Book book[], const int isbn, const int size);
void checkPrice(const struct Book book[], const int size);
void addBook(struct Book book[], int *size);


int main()
{
	struct Book book[MAX_BOOKS];
	int size = 0, val = 0;

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
			displayInventory(book, size);
			break;

		case 2:
			addBook(book, &size);
			break;
		case 3:
			checkPrice(book, size);
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
	printf("0) Exit.\n\n");

}
void displayInventory(const struct Book book[], const int size)
{
	int i;
	if (size != 0)
	{
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		for (i = 0; i < size; i++)
		{
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, &book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}
		printf("===================================================\n\n");
	}
	else 
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}
}


void searchInventory(const struct Book book[], const int isbn, const int size)
{
	printf("Not implemented");
}
void checkPrice(const struct Book book[], const int size)
{
	printf("Not implemented");
}
void addBook(struct Book book[], int *size)		
{
	while (getchar() != '\n');					
	if (*size == MAX_BOOKS)
	{
		printf("the inventory is full");
	}

	else
	{
		printf("ISBN:");
		scanf("%d", &book[*size]._isbn);
		while (getchar() != '\n')
			;
		printf("Title:");
		scanf(" %[^\n]s", book[*size]._title);
		while (getchar() != '\n')
			;
		printf("Year:");
		scanf("%d", &book[*size]._year);
		while (getchar() != '\n')
			;
		printf("Price:");
		scanf("%lf", &book[*size]._price);
		while (getchar() != '\n')
			;
		printf("Quantity:");
		scanf("%d", &book[*size]._qty);

		*size = *size + 1;
		printf("The book is successfully added to the inventory.\n\n");
	}
}

