/*
Name          : Sahil Nimeshkumar Lapsiwala
Student number: 132584160
Email         : snlapsiwala@myseneca.ca
Workshop      : 10
Section       : M
Date          :4/07/2017*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) 
{
  char filename[31] = "jedi_master.txt";
  int isJedi = 0;
  FILE *fp = NULL;
  fp = fopen(filename,"r");
  if (fp != NULL)
  {
	  while (fscanf(fp, "%[^\n]\n", filename) == 1)
	  {
		  if (strcmp(name,filename) == 0)
		  {
			  isJedi = 1;
		  }
	  }fclose(fp);
  }
  return isJedi;
}
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[])
{
	int length = strlen(fullName),i,val;
	char name[17] = { '\0' };

	if (length <= 16)
	{
		
		for (i =0; i < (16-strlen(fullName)); i++)
		{
			strcat(name, " ");
		}
		strcpy(formattedRecord, fullName);
		strcat(formattedRecord, name);
		
	}
	else
	{
		strcpy(formattedRecord, fullName);
		formattedRecord[14] = '\0';
		strcat(formattedRecord, "..");
		
	}

	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);

	val = isJediMaster(fullName);

	if (val == 1)
	{
		strcat(formattedRecord, " Jedi Master");
	}





}


/* formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/