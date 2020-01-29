/*
Name          : Sahil Nimeshkumar Lapsiwala
Student number: 132584160
Email         : snlapsiwala@myseneca.ca
Workshop      : 8
Section       : M
Date          :22/03/2017*/
	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// Define statements:

#define LINEAR 1
#define FORM 0



// Constant TAX value:
double const TAX = 0.13;



// Item structure:

struct Item 
{
double price;   
int sku;
int isTaxed;    
int quantity;
int minQuantity;
char name[21];
};



// Function Prototypes Milestone 1:

void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);










// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);








// Function Implementations Milestone 1:

void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n");
	printf("\n");
}
void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void printFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
	{
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
	}
}
void flushKeyboard(void)
{
	while (getchar() != '\n')
      ;
}
void pause(void)
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}
int getInt(void)
{
	int value = 0, flag;
	char c = 'x';

	do {
		scanf("%d%c", &value, &c);
		if (c != '\n')
		{
			flushKeyboard();
			printf("Invalid integer, please try again:");
			flag = 1;
		}
		else
			flag = 0;
	} while (flag == 1);
	return value;
}
int getIntLimited(int lowerLimit, int upperLimit)
{
	int limit, flag;

	do {
		limit = getInt();
		if (limit < lowerLimit || limit > upperLimit)
		{
			printf("Invalid value, %d < value > %d: ", lowerLimit, upperLimit);
			flag = 1;
		}
		else
			flag = 0;
	} while (flag == 1);
	return limit;
}
double getDouble(void)
{
	double value;
	int flag;
	char c = 'x';
	do {
		scanf("%lf%c", &value, &c);
		if (c != '\n')
		{
			flushKeyboard();
			printf("Invalid integer, please try again:");
			flag = 1;
		}
		else
			flag = 0;
	} while (flag == 1);
	return value;
}
double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double limit;
	int flag;

	do {
		limit = getDouble();
		if (limit <= lowerLimit || limit >= upperLimit)
		{
			printf("Invalid value, %lf > value > %lf: ", lowerLimit, upperLimit);
			flag = 1;
		}
		else
			flag = 0;
	} while (flag == 1);
	return limit;
}
int yes(void)
{
	int flag = 0;
	char c = 'x';
	do
	{
		scanf("%c", &c);
		if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
		{
			flushKeyboard();
			if (c == 'y' || c == 'Y')
			{
				return 0;
				flag = 0;
			}
			
		}
		else
		{

			printf("Only (Y)es or (N)o are acceptable:\n");
			flag = 1;
			flushKeyboard();

		}



	} while (flag == 1);
	return flag;
}
int menu(void)
{
	
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf(">");
	return 0;

}
void GroceryInventorySystem(void)
{
	int iVal;
	welcome();
	menu();
	iVal = getIntLimited(0, 7);
	switch (iVal) 
	{
	case 1:
		printf("List Items under construction!\n");
		pause();
		menu();
		break;
	case 2:
		printf("Search Items under construction!\n");
		pause();
		menu();
		break;
	case 3:
		printf("Checkout Item under construction!\n");
		pause();
		menu();
		break;
	case 4:
		printf("Stock Item under construction!\n");
		pause();
		menu();
		break;
	case 5:
		printf("Add/Update Item under construction!\n");
		pause();
		menu();
		break;
	case 6:
		printf("Delete Item under construction!\n");
		pause();
		menu();
		break;
	case 7:
		printf("Search by name under construction!\n");
		pause();
		menu();
		break;
	case 0:
		printf("Exit the program? (Y)es/(N)o):");
		while (yes() == 0)
			break;
	}
}
// Function Implementations Milestone 2:
double totalAfterTax(struct Item item)
{
	double total;
	total = item.quantity*item.price;
	if (item.isTaxed == 1)
	{
		total = (item.quantity*item.price)*(1+TAX);
	}
	return total;
}
int isLowQuantity(struct Item item)
{
	int val;

	if (item.quantity < item.minQuantity)
	{
		val=1;
	}
	else
		val=0;
	return val;
}
struct Item itemEntry(int sku)
{
	
	struct Item item;
	item.sku = sku;
	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", item.name);
	flushKeyboard();
	printf("      Price: ");
	item.price = getDouble();
	printf("   Quantity: ");
	item.quantity = getInt();
	printf("Minimum Qty: ");
	item.minQuantity = getInt();
	printf("   Is Taxed: ");
	item.isTaxed = yes();
	return item;
}
void displayItem(struct Item item, int linear)
{
	
	double Total;
	
	
	if (linear == 1)
	{
		
		if (item.quantity < item.minQuantity && item.isTaxed ==1)

		{
			Total = item.price*item.quantity*(1 + TAX);
			printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price,  item.quantity, item.minQuantity, Total);
		}
		else
			
		{
			Total = item.price*item.quantity;
			printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price,  item.quantity, item.minQuantity, Total);
		}
	}
	else
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
	if (item.isTaxed == 1)
		{
			printf("   Is Taxed: Yes\n");
		}
		else
			printf("   Is Taxed: No\n");


		if (item.quantity < item.minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

	
void listItems(const struct Item item[], int NoOfItems)
{
	int i;
	double Total = 0, grand_Total = 0;

	printTitle();
   	for (i = 0; i < NoOfItems; i++)
	{

		char* ans[3];
		if (item[i].isTaxed == 1)
		{
			*ans = "Yes";
			Total = item[i].price*item[i].quantity*(1 + TAX);
		}
		else
		{
			*ans = "No";
			Total = item[i].price*item[i].quantity;
		}
	
		grand_Total= grand_Total + Total;
		if (item[i].quantity < item[i].minQuantity)
		{
			printf("%-4d|%3d|%-20s|%8.2lf| %4s| %3d | %3d |%12.2lf|***\n", i + 1, item[i].sku, item[i].name, item[i].price, *ans, item[i].quantity, item[i].minQuantity, Total);
		}
		else {
			printf("%-4d|%3d|%-20s|%8.2lf| %4s| %3d | %3d |%12.2lf|\n", i + 1, item[i].sku, item[i].name, item[i].price, *ans, item[i].quantity, item[i].minQuantity, Total);

			
		}
                  
	}	
      printFooter(grand_Total);
}
	int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i, flag = 0;
	for (i = 0; i < NoOfRecs; i++) 
	{ 
		if (sku == item[i].sku)
		{ 
			*index = i;
			flag = 1;
		} 
	}
	return flag;
}



