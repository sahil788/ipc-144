#include <stdio.h>
// tools
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


// code your functions here:
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
		if (c!= '\n')
		{
			flushKeyboard();
			printf("Invalid integer, please try again: ");
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
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
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
		if (c!= '\n')
		{
			flushKeyboard();
			printf("Invalid number, please try again: ");
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
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
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
	char c='x';
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
			else
			{
				menu();
				flag = 0;
			}
			
		}
		else
		{
			
			printf("Only (Y)es or (N)o are acceptable: ");
			flag = 1;
			flushKeyboard();
			
		}
		
		

	} while (flag == 1);
	return flag;
}
int menu(void)
{
	int iVal;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	iVal = getIntLimited(0, 7);

	switch (iVal) {
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
		printf("Exit the program? (Y)es/(N)o: ");
		while (yes()==0)
		break;
	}
return 0;
}
void GroceryInventorySystem(void)
{
	welcome();
	menu();
	
}


