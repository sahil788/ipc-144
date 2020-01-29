
/* 
**********************************************
   Name :Sahil Nimeshkumar Lapsiwala
   ID:132584160
   Date:27/01/2017
   file:cashRegister.c* 
 **********************************************  
   */

#include<stdio.h>

int main(void)
{
	double  amount;  //variable declaration
	double  owe;
	int loonies ,quater;

	printf("Please enter the amount to be paid: $");
	scanf("%lf",&amount);
	
	loonies=amount/1;   //formula for calculating loonies
	owe=amount-loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n",loonies,owe);

	quater=owe/0.25 ;      //formula for calculating quater
	owe=owe-(quater*0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n",quater,owe);
       
	 return 0;
}
