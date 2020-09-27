
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployee.h"
#include "utn_functions.h"
#define TRUE 1
#define FALSE 0
#define LONG_NAME 50




int initializeArrayEmployee(eEmployee arrayEmployee[],int quantityEmployee)
{
	int retorno = -1;
	int i;

	if(arrayEmployee != NULL && quantityEmployee > 0){

		for(i=0;i<quantityEmployee;i++)
		{
			arrayEmployee[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int searchIsEmpty(eEmployee arrayEmployee[],int quantityEmployee)
{
	int retorno = -1;
	int i;
		for(i=0;i<quantityEmployee;i++)
		{
		   if(arrayEmployee[i].isEmpty == TRUE)
		   {
				retorno = i;
		   }
		}
	return retorno;
}

int searchIdEmployee(eEmployee arrayEmployee[],int quantityEmployee,int auxiliaryId)
{
	int retorno = -1;
	int i;
		for(i=0;i<quantityEmployee;i++)
		{
		   if(arrayEmployee[i].id == auxiliaryId)
		   {
				retorno = i;

		   }
		}
	return retorno;
}




int idRandom(int indexFree,eEmployee arrayEmployee[],int quantityEmployee)
{
int numberRandom;
int retorno = -1;
int i;

   if(arrayEmployee != NULL){

		srand(time(NULL));
		numberRandom = 1000+rand()%(2000-1000+1);

		for(i=0;i<quantityEmployee;i++){

	     	if(numberRandom != arrayEmployee[i].id)
	     	{
		        srand(time(NULL));
				numberRandom = 1000+rand()%(2000-1000+1);
	     	}
		}
		arrayEmployee[indexFree].id = numberRandom;
		retorno = 0;
   }
	printf("\n -Se ha creado automaticamente su legajo!! \n");
	printf("\n -Su legajo es: %d \n", numberRandom);
	printf("-----------------------------------------------------------------------\n");

	return retorno;
}


 int removeEmployee(eEmployee arrayEmployee[], int quantityEmployee, int idForClear)
{
		int retorno = -1;
		int i;
		if( arrayEmployee != NULL && quantityEmployee>0)
		{
			for (i=0; i<quantityEmployee; i++) {
				if(arrayEmployee[i].id ==idForClear && arrayEmployee[i].isEmpty==FALSE)
				{
					arrayEmployee[i].isEmpty=TRUE;
					retorno = 0;
				}
			}

		}
	return retorno;
}
