#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "utn_functions.h"
#include "optionsMain.h"
#define TRUE 1
#define FALSE 0

#define QTY_EMPLOYEE 1000
#define LONG_NAME 50



static int sortEmployeesLowerToUp(eEmployee arrayEmployees[],int quantityEmployee);
static int sortEmployeesUpToLower(eEmployee arrayEmployees[],int quantityEmployee);
static int averageExceeds(eEmployee arrayEmployees[],int quantityEmployee,float average);

//_________________________________________________________________________________________________________________________________
                                            // FUCTION FOR DECLARATION  ALL SPACES ARE EMPTY.

/** \brief FUNCION PARA INICIALIZAR TODAS LAS POSCION  SON LIBRES Y QUE LOS SALARIOS COMIENZAN EN 0.
 *
 * \param   PASAMOS EL ARRAY DE EMPLEADOS PARA ASIGNARLE QUE TODAS LAS POSICIONES ESTAN VACIAS
 * \param   SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \return  SI RETORNA -1 SIGNIFICA QUE LA FUNCION DIO ERROR,  0 SI SE CUMPLIO CORRECTAMENTE LA FUNCION.
 *
 */
int initializeArrayEmployee(eEmployee arrayEmployee[],int quantityEmployee)
{
	int retorno = -1;
	int i;

	if(arrayEmployee != NULL && quantityEmployee > 0){

		for(i=0;i<quantityEmployee;i++)
		{
			arrayEmployee[i].isEmpty = TRUE;
			arrayEmployee[i].salary = 0;
		}
		retorno = 0;
	}
	return retorno;
}

//_________________________________________________________________________________________________________________________________
                                            // FUCTION FIND AN EMPTY POSITION

/** \brief BUSCA UNA POSCION LIBRE DENTRO DEL ARRAY
 *
 * \param   ARRAY DE EMPLEADO PARA COMPARAR SI LA POSICION DE INTERACION ESTA LIBRE
 * \param   SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \return  RETORNA -1 SI NO SE ENCONTRO NINGUNO O  SE RETORNA LA POSICION EN LA CUAL ESTA LIBRE , PARA LUEGO CARGARLA DE DATOS.
 *
 */
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
//_________________________________________________________________________________________________________________________________
                                            // FUCTION FIND AN EMPLOYEE

/** \brief BUSCA SI EXISTE LA ID QUE INGRESO EL USUARIO.
 *
 * \param   PASAMOS EL ARRAY DE EMPLEADOS PARA QUE LO BUSQUE Y COMPARE LA ID QUE INGRESO EL USUARIO
 * \param     SE LE PASA EL TAMAÑO DE EMPLEADOS
 *  \param  PASAMOS LA ID INGRESADA POR EL USUARIO Y LUEGO LA COMPARAMOS
 * \return  RETORNA -1 SI NO EXISTE LA ID, SI EXISTE SE LE DEVUELVE LA POSICION EN LA CUAL SE ENCUANTRA.
 */
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
//_________________________________________________________________________________________________________________________________
                               //   FUNTION FOR REMOVE EMPLOYEE



/** \brief FUNCION QUE REMUEVE EL LEGAJO DESEADO POR EL USUARIO.
 *
 * \param   SE LE PASA EL ARRAY DE EMPLEADOS PARA QUE PUEDA COMPARAR CON  EL ID DESEADO A BORRAR
 * \param   SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \param   SE LE PASA ID CONFIRMADA A BORRAR.
 * \return  RETORNA 0 SI TODO ESTUVO CORRECTO, -1 EN CASO DE QUE EL PROGRAMA TENGA UN ERROR.
 */
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
//___________________________________________________________________________________________________________________
//============================================ OPTION FOUR ===========================================================


/** \brief MUESTRA LOS DATOS INGRESADOS, ORDENAMIENTO SEGUN GUSTE EL USUARIO Y TABLA DE SALARIOS INGRESADOS.
 *
 * \param  Pasamos array de empleados para mostrar los datos en cada posicion de i , si es que hay dato cargado.
 * \param   SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \param  Pasamos el dato de los acumuladores de salarios, estos se acumulaban solo cuando se ingresan datos.
 * \param  Se le pasa el proemdio del los salarios ingresados
 *   \return Esta funcion retorna los datos ingresados.
 */
void toShowInformation(eEmployee arrayEmployees[],int quantityEmployee,float accumualteSalary, float average)
{
    int i;
    int option;
    int employeeExceedsAverage;

    do{

            printf("\n    ====================================================================================\n");
            printf("   |                           TABLA DE EMPLEADOS EXISTENTES                            |\n");
			printf("    ====================================================================================\n");
            printf("   |     ID    |     APELLIDO     |     NOMBRE      |   SALARIO        |  SECTOR    |\n");
			for (i=0;i<quantityEmployee; i++)
			{
				if(arrayEmployees[i].isEmpty == FALSE ){
					printf("   |     %d     |     %2s       %10s             %5.2f           %d   \n",arrayEmployees[i].id,arrayEmployees[i].lastName,arrayEmployees[i].name,arrayEmployees[i].salary, arrayEmployees[i].sector);
				}
			}
			printf("    =================================================================================");

            employeeExceedsAverage  = averageExceeds(arrayEmployees,quantityEmployee,average);
            if(employeeExceedsAverage == -1)
            {
            printf("\n      ====================================================================================\n");
            printf("    | TOTAL DE LOS SALARIOS INGRESADOS    : %10.2f                                   |\n",accumualteSalary);
            printf("    | PROMEDIO DE LOS SALARIOS INGRESADOS : %10.2f                                   |\n",average);
            printf("    | NINGUN SALARIO SUPERA EL TOTAL DEL PROMEDIO                                        |\n");
            printf("     ====================================================================================\n");

            }else
            {
            printf("\n      ====================================================================================\n");
            printf("    | TOTAL DE LOS SALARIOS INGRESADOS   : %2.2f                                      |\n",accumualteSalary);
            printf("    | PROMEDIO DE LOS SALARIOS INGRESADOS: %2.2f                                      |\n",average);
            printf("    | EMPLEADOS QUE SUPERAN EL PROMEDIO: %d                                              |\n",employeeExceedsAverage);
            printf("     ====================================================================================\n");

            }

            option = mainSort();
			switch(option)
            {
            case 1:
                sortEmployeesLowerToUp(arrayEmployees,quantityEmployee);
            break;
            case 2:
                sortEmployeesUpToLower(arrayEmployees,quantityEmployee);
            break;
            }

    }while(option!= 3);

}
//--------------------------------------------------------------------------------------------------------------------------------
                                        //  FUCTION .WHO EXCEEDS THE AVERAGE?

//
/** \brief Esta funcion  estatica cuenta los salarios que superan al promedio
 *
 * \param arrayEmployees[] eEmployee Pasamos el array de empleados para que busque si hay un empleado existente que supere el promedio
 * \param quantityEmployee int SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \param average float  Este parametro le  brinda la informacion del promedio total de los salarios ingresados
 * \return int retorna, -1 si no hay algun sueldo que supere el promedio, si lo hay  pasamos la cantidad empleados que lo superaron.
 *
 */
static int averageExceeds(eEmployee arrayEmployees[],int quantityEmployee, float average)
{
int i;
int retorno = -1;
int employeeExceedsAverage  = 0;
        for(i=0;i<quantityEmployee;i++){

                if(arrayEmployees[i].salary > average)
                {
                       employeeExceedsAverage++;
                       retorno = employeeExceedsAverage;
                }
        }
    return  retorno;
}

//___________________________________________________________________________________________________________________
//============================================FUCTION SORT ===========================================================

/** \brief Funcion para ordenar de menor a mayor  por nombre y sector .
 *
 * \param   se le pasa el array para que haga el acomodamiento correspondiente
 * \param     SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \return  retorna 0 si pudo hacer el ordenamiento o -1 no pudo hacerlo.
 *
 */
static int sortEmployeesLowerToUp(eEmployee arrayEmployees[],int quantityEmployee)
{
	int i;
    int j;
    int retorno = -1;
    eEmployee auxEmployee;

	for(i=0; i<quantityEmployee-1; i++)
    {
        for(j=i+1; j<quantityEmployee; j++)
        {
            if((strcmp(arrayEmployees[i].lastName ,arrayEmployees[j].lastName)>0) ||
               (strcmp(arrayEmployees[i].lastName ,arrayEmployees[j].lastName)== 0 && (arrayEmployees[i].sector < arrayEmployees[j].sector)))
            {
                auxEmployee = arrayEmployees [i];
                arrayEmployees[i] = arrayEmployees[j];
                arrayEmployees[j] = auxEmployee;
                retorno = 0;
            }
        }
    }
return retorno;

/** \brief Funcion para ordenar de mayor a menor  por nombre y sector .
 *
 * \param   se le pasa el array para que haga el acomodamiento correspondiente
 * \param   SE LE PASA EL TAMAÑO DE EMPLEADOS
 * \return  retorna 0 si pudo hacer el ordenamiento o -1 no pudo hacerlo.
 *
 */
}
static int sortEmployeesUpToLower(eEmployee arrayEmployees[],int quantityEmployee)
{
	int i;
    int j;
    int retorno = -1;
    eEmployee auxEmployee;

	for(i=0; i<quantityEmployee-1; i++)
    {
        for(j=i+1; j<quantityEmployee; j++)
        {
            if((strcmp(arrayEmployees[i].lastName ,arrayEmployees[j].lastName)>0) ||
               (strcmp(arrayEmployees[i].lastName ,arrayEmployees[j].lastName)== 0 ))
            {
                auxEmployee = arrayEmployees [i];
                arrayEmployees[i] = arrayEmployees[j];
                arrayEmployees[j] = auxEmployee;
                retorno = 0;

                if((arrayEmployees[i].sector > arrayEmployees[j].sector))
                {
                    auxEmployee.sector = arrayEmployees [i].sector;
                    arrayEmployees[i].sector = arrayEmployees[j].sector;
                    arrayEmployees[j].sector = auxEmployee.sector;
                    retorno  = 0;
                }
            }
        }
    }
return retorno;
}

