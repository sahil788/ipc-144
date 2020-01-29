/*
== Vehicle Rentals ==

name    : Sahil Nimeshkumar Lapsiwala
id      : 132584160
mail    : snlapsiwala@myseneca.ca
section : M 

*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
};

/* prototype functions addPositive Here*/
double addpositive (double amount, double newamount)
{
	if (newamount > -1)
	{
		double total = amount + newamount;
		return total;
	}
	else
		return amount;
}


/* Implement Function addPositive Here*/




/* main program */
int main()
{
   const int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters

   // Initialize the struct Vehicle Rental
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };

   /*Declare Your Variables Here*/
   int ndays, km;
   double charge, cost,baseprice,cost1,cost2;



   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");
      scanf("%d", &option);
      printf("\n");

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");
		 for (i = 0; i < noVehicles; i++)
		 {
			 printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
			  }
		       printf("\n");

         // Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
         // using a loop construct

         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);

         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }

         if (flag != -1) {

            // Capture #days for the rental from user input
			 printf("Enter Rental Period (in Days): ");
			 scanf("%d", &ndays);
			 printf("Enter kilometers driven: ");
			 scanf("%d", &km);


            // Calculate the base price (baseDay * Days)
			  baseprice = vRent[flag].baseDay*(double)ndays;
            // Calculate cost for Kilometers driven using "distRate1 & 2 above"

			  if (km > 100)
			  {
				  cost1 = 100 * distRate1;
				  cost2 = (km - 100)*distRate2;
				  cost = cost1 + cost2;
			  }
			  else
				  cost = km*distRate1;

            // Add base Price and cost for kilometer driven in to a new variable 
            // "charge"
			  charge = cost + baseprice;

            /* Call addPositive function with current earnings for the rental and
               charge(calculated above) as arguments and assign the returned
               result back to earnings
            */
			  vRent[flag].earnings = addpositive(vRent[flag].earnings, charge);

            // Display Base Charge, cost for km and the Total 
            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");
            // Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement
			printf("%6.2lf %6.2lf %6.2lf\n", baseprice, cost, charge);
                        printf("\n");
         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}

/* SAMPLE INPUT/OUTPUT EXPECTED */

/*

***** Rental Vehicle Management App *****

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 123
Enter Rental Period (in Days): 2
Enter kilometers driven: 125

Base   kmCost Total
====== ====== ======
 19.90  81.25 101.15

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 124
Enter Rental Period (in Days): 3
Enter kilometers driven: 79

Base   kmCost Total
====== ====== ======
 59.85  54.51 114.36

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 2

-- Rental Charges --

Enter vehicle ID: 125
ERROR: Vehicle ID does not exist.

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 1

-- Rental Vehicle Status --

ID#      Earnings
-------- ----------
     123     101.15
     124     114.36

1.) Rental Status
2.) Apply Charges
0.) Log out

Please enter an option to continue: 0

*/