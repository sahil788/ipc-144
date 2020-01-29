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
#define STOCK   1
#define CHECKOUT   0 
#define MAX_ITEM_NO  21 
#define MAX_QTY   999
#define SKU_MAX   999 
#define SKU_MIN   100


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

// function prototypes milestone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);








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
				
				flag = 1;
			}
			else if (c == 'N' || c == 'n')
			{
				return 0;
			}

		}
		else
		{

			printf("Only (Y)es or (N)o are acceptable:\n");
			flag = 0;
			flushKeyboard();

		}



	} while (flag == 0);
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
		total = (item.quantity*item.price)*(1 + TAX);
	}
	return total;
}
int isLowQuantity(struct Item item)
{
	int val;

	if (item.quantity < item.minQuantity)
	{
		val = 1;
	}
	else
		val = 0;
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


	if (linear==1)
	{

		if (item.quantity < item.minQuantity && item.isTaxed == 1)

		{
			Total = item.price*item.quantity*(1 + TAX);
			printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price, item.quantity, item.minQuantity, Total);
		}
		else

		{
			Total = item.price*item.quantity;
			printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price, item.quantity, item.minQuantity, Total);
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


		if (item.quantity <= item.minQuantity)
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

		grand_Total = grand_Total + Total;
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

// functions implementations milestone 3
void search(const struct Item item[], int NoOfRecs)
{
	int sku, i,found; 
     found = 0; 
	 printf("Please enter the SKU: ");
	 sku = getIntLimited(SKU_MIN,SKU_MAX);
	 found = locateItem(item,NoOfRecs,sku,&i);

	if(found==1)
		displayItem(item[i],FORM);
	else
		printf("Item not found!\n");
}
void updateItem(struct Item* itemptr)
{
	int sku = itemptr->sku, ans;
	struct Item val ;

	printf("Enter new data:\n");
	
	

	val = itemEntry(sku);
	sku=val.sku;

	printf("Overwrite old data? (Y)es/(N)o: ");
	ans = yes();
	if (ans == 1)
	{
		*itemptr = val;
		printf("--== Updated! ==--\n");

	}

	else
	{
		printf("--== Aborted! ==--\n");
	}

}
void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	struct Item add;
	int ans;

	if (*NoOfRecs == MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}

	else
	{
		
		add = itemEntry(sku);

		printf("Add Item? (Y)es/(N)o: ");
		ans = yes();

		if (ans != 1)
		{
			printf("--== Aborted! ==--\n");
		}

		else
		{
			add.sku = sku;
			item[*NoOfRecs] = add;
			*NoOfRecs += 1;

			printf("--== Added! ==--\n");
			
		}
	}
}
void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int sku,found,i,ans;

	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	found = locateItem(item, *NoOfRecs, sku, &i);
	if (found == 1)
	{
		displayItem(item[i], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		ans = yes();
		if (ans != 1)
		{
			printf("--== Aborted! ==--\n");
		}
		else
			updateItem(&item[i]);
			
	}
	else
		addItem(item, NoOfRecs, sku);
}
void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int sku,found,i,val;
	char stocking[] = "to stock", check[] = "to checkout";

	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	found = locateItem(item, NoOfRecs, sku, &i);

	if (found != 1)
	{
		printf("SKU not found in storage!\n");
	}
	  else
	   {
		  displayItem(item[i], FORM);

		  if (stock == STOCK)
		  {
			  printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stocking, MAX_QTY - item[i].quantity);
			  val = getIntLimited(0, MAX_QTY - item[i].quantity);

			  if (val == 0)
			  {
				  printf("--== Aborted! ==--\n");
			  }
			  else
			  {
				  item[i].quantity += val;
				  printf("--== Stocked! ==--\n");
			  }
		  }
		  
		else
		  {
			  printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", check, item[i].quantity);
			  val = getIntLimited(0, item[i].quantity);

			  if (val == 0)
			  {
				  printf("--== Aborted! ==--\n");
			  }
			  else
			  {
				  item[i].quantity -= val;
				  printf("--== Checked out! ==--\n");

				  if (item[i].quantity < item[i].minQuantity)
				  {
					  printf("Quantity is low, please reorder ASAP!!!\n");
				  }
			  }
		  }
	 }
 }




