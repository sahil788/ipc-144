/*
Name: Sahil Nimeshkumar Lapsiwala
Student number: 132584160
Email: snlapsiwala@myseneca.ca
Workshop: 8
Section: M
Date:22/03/2017
*/
#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20
struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};
void menu();
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
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

		for (i = 0; i < size ; i++)
		{
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}
		printf("===================================================\n\n");
	}

	else
	{
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	
   }
	
}
int searchInventory(const struct Book book[], const int isbn, const int size)
{
	int val=-1,i;
	for (i = 0; i < size; i++)
	{
	    if (isbn==book[i]._isbn)  
	  {
	     val = i;
	  }
   }
	return val;
}
void checkPrice(const struct Book book[], const int size)
{
	int isbn,found;

	printf("Please input the ISBN number of the book:\n\n");
    scanf("%d", &isbn);

	found=searchInventory(book,isbn,size );

	if (found != -1)
	{
	   printf("Book %d costs $%.2lf\n\n", book[found]._isbn, book[found]._price);
	}
	else
	    printf("Book does not exist in the bookstore! Please try again.\n\n");
}
void addBook(struct Book book[], int *size)
{
	int isbn, qty, found = -1;
	
	if (*size == MAX_BOOKS)
	{
         printf("the inventory is full\n");
	}
	else
	{
		printf("ISBN:");
		scanf("%d", &isbn);
		found= searchInventory(book, isbn, *size);
		if (found== -1)
		{
			book[*size]._isbn = isbn;
			printf("Quantity:");
			scanf("%d", &book[*size]._qty);
			while (getchar() != '\n');
			printf("Title:");
			scanf(" %20[^\n]s", book[*size]._title);
			printf("Year:");
			scanf("%d", &book[*size]._year);
			printf("Price:");
			scanf("%f", &book[*size]._price);
			printf("The book is successfully added to the inventory.\n\n");
			*size = *size + 1;
		}
		else
		{
			printf("Quantity:");
			scanf("%d", &qty);
			book[found]._qty = book[found]._qty + qty;
			printf("The book exists in the repository, quantity is updated.\n\n");
		}
	}
}



