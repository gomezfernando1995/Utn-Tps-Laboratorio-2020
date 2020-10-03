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


int main()
{
 eEmployee arrayEmployees[QTY_EMPLOYEE];
 //eEmployee auxiliaryEmployees;

 char   auxiliaryNameStr[LONG_NAME];
 char   auxiliaryLastNameStr[LONG_NAME];
 int    auxiliaryId;
 int    auxiliaryIdForClear;
 int    auxiliarySector;

 int    counterEmplooyes = 0;
 int    flagEnter = 0;
 int    newId = 0;

 int    indexResultSearch;
 int    indexFree;
 int    indexIdForClear;

 int    option;
 int    optionTwo;
 float  auxiliarySalary;
 float  accumulatorSalary = 0;
 float  average;


    if(initializeArrayEmployee(arrayEmployees,QTY_EMPLOYEE)== 0)
    {
      do{
            option = firstMain();          // MUESTRA MENU PRINCIPAL
            switch(option)
            {
                case 1:
                    indexFree = searchIsEmpty(arrayEmployees,QTY_EMPLOYEE);
                    if(indexFree == -1) //SI SEARCH IS EMPTY DEVUELVE -1 SIGNIFICA QUE NO HAY  LUGAR,  DE LO CONTRARIO MUESTRA MENSAJE PARA INGRESAR DATOS.
                    {
                        printf("NO HAY LUGARES DISPONIBLES!!");
                    }else
                    {
                        newId ++;
                        arrayEmployees[indexFree].id= newId;
                        printf("\n          -Se ha creado la id automaticamente!!\n           -Su es Id: %d  \n",arrayEmployees[indexFree].id);
                        utn_getTexto(auxiliaryNameStr,"\n          -Ingrese nombre del empleado: ","\n          -Error, ingrese el nombre correctamente\n",5);
                        utn_getTexto(auxiliaryLastNameStr,"\n          -Ingrese apellido del empleado: ","\n    -Error, reingrese apellido\n",5);
                        utn_getNumeroFloat(&auxiliarySalary,"\n          -Ingrese salario mensual: ","\n        -Error, ingrese un sueldo correcto\n",0,10000000,5);

                        counterEmplooyes++;
                        accumulatorSalary = accumulatorSalary +auxiliarySalary;

                        utn_getNumeroInt(&auxiliarySector,"\n          -Ingrese Sector del 1 al 10 : ","\nError,reingrese sector\n",1,10,5);
                        arrayEmployees[indexFree].sector = auxiliarySector;
                        arrayEmployees[indexFree].isEmpty = FALSE ;
                        strncpy(arrayEmployees[indexFree].name,auxiliaryNameStr,LONG_NAME);
                        strncpy(arrayEmployees[indexFree].lastName,auxiliaryLastNameStr,LONG_NAME);
                        arrayEmployees[indexFree].salary = auxiliarySalary;


                        flagEnter = 1;
                    }
                    average = accumulatorSalary/counterEmplooyes;
                break;
                case 2:
                    // VERIFICA QUE SE HALLA INGRESADO DATOS. DE LO CONTRARIO MUESTRA MENSAJE QUE SE DEBEN INGRESAR DATOS
                    if(flagEnter == 1){
                    // PIDE QUE SE INGRESE LEGAJO PARA BUSCAR Y SE PUEDE MODIFICAR, SI ENCUENTRA EL LEGAJO MUESTRA MENU DE MODIFICACION
                    //   SINO MARCA ERROR QUE NO EXITE TAL LEGAJO INGRESADO

                        if(utn_getNumeroInt(&auxiliaryId ,"\n         -Ingrese Legajo a modificar: ","\n         -Error, ingrese un legajo valido\n",1,1000,3)== -1)
                        {
                            break;
                        }else
                        {
                            indexResultSearch = searchIdEmployee(arrayEmployees,QTY_EMPLOYEE,auxiliaryId);
                        }
                        if(indexResultSearch == -1)
                        {
                            printf("\n       -La id ingresada no existe\n");
                            break;
                        }else
                        {
                            printf("\n          -Datos de la id ingresada:\n\n          -Apellido y Nombre: %s %s\n          -Salario: $%.2f\n          -Sector: %d\n",arrayEmployees[indexResultSearch].lastName,arrayEmployees[indexResultSearch].name,arrayEmployees[indexResultSearch].salary,arrayEmployees[indexResultSearch].sector);

                        // COMIENZO DEL MENU DE MODIFICACION
                            do{
                                optionTwo = mainModification();
                                switch(optionTwo)
                                {
                                    case 1:
                                        utn_getTexto(auxiliaryNameStr,"\n               -Ingrese nombre del empleado: ","\n             -Error, ingrese el nombre correctamente\n",3);
                                        strncpy(arrayEmployees[indexResultSearch].name,auxiliaryNameStr,LONG_NAME);
                                    break;
                                    case 2:
                                        utn_getTexto(auxiliaryLastNameStr,"\n           -Ingrese apellido del empleado: ","\n           -Error, reingrese apellido\n",3);
                                        strncpy(arrayEmployees[indexResultSearch].lastName,auxiliaryLastNameStr,LONG_NAME);
                                    break;
                                    case 3:
                                        utn_getNumeroFloat(&auxiliarySalary,"\n         -Ingrese salario mensual: ","\n                 -Error, ingrese un sueldo correcto\n",0,10000000,3);
                                        arrayEmployees[indexResultSearch].salary = auxiliarySalary;
                                    break;
                                    case 4:
                                        utn_getNumeroInt(&auxiliarySector,"\n           -Ingrese el sector del 1 al 10: ","\n           -Error,reingrese sector\n",1,10,3);
                                        arrayEmployees[indexResultSearch].sector=auxiliarySector;
                                    break;  // BREAK DEL CASE 4 DEL MENU DE MODIFICACION
                                 }
                            }while(optionTwo !=5); // FIN DEL MENU DE MODIFICACIONES
                        }
                        }else{
                            printf("\n        NO EXISTEN DATOS PARA MODIFICAR, PRIMERO DEBE DE INGRESAR ALGUNONO \n");
                        }
                        break; //FIN DEL CASE 2 DEL MENU PRINCIPAL
                case 3:
                        if(flagEnter == 1){
                          // SE VERIFICA QUE PRIMERO SE HALLAN INGRESADOS DATOS, DE LO CONTRARIO DA ERROR
                            if(utn_getNumeroInt(&auxiliaryIdForClear,"\n          -Ingrese Legajo a borrar: ","\n       Error, ingrese un legajo valido\n",1,1000,3)== -1)
                            {
                                break;
                            }else{
                                // SI SE INGRESAN DATOS, PIDE QUE SE INGRESE EL LEGAJO PARA BUSCARLO.
                                indexIdForClear = searchIdEmployee(arrayEmployees,QTY_EMPLOYEE,auxiliaryIdForClear);
                            }

                            if(indexIdForClear == -1){
                                printf("\n -La id ingresada no existe\n");
                                break;
                            }else
                            {
                                //SI ENCUENTRA EL LEGAJO MUESTRA LOS DATOS QUE CONTIENE ESA ID , LUEGO MUESTRA ADVERTENCIA Y SI ESTA
                                // SEGURO QUE SE QUIERE BORRAR.
                                printf("\n          -Datos de la id ingresada:\n\n          -Apellido y Nombre: %s %s\n          -Salario: $%.2f\n          -Sector: %d\n",arrayEmployees[indexIdForClear].lastName,arrayEmployees[indexIdForClear].name,arrayEmployees[indexIdForClear].salary,arrayEmployees[indexIdForClear].sector);
                                if(mainAlertClean() == 1)
                                {
                                    if(removeEmployee(arrayEmployees,QTY_EMPLOYEE,auxiliaryIdForClear)== -1)
                                        //SI DEVUELVE -1 SIGNIFICA QUE HUBO EN ERROR EN EL PROGRAMA.
                                    {
                                        printf("\n       ERROR,NO SE PUDO BORRAR LA ID.\n");
                                    }else
                                    {   // SI SE CONFIRMO , MUESTRA EL MENSAJE QUE HA SIDO ELIMINADA CON EXITO.
                                        printf("\n          -----------------------------------------------------------------------");
                                        printf("\n         |                  La id a sido borrada con exito!                      |\n");
                                        printf("         -----------------------------------------------------------------------\n");
                                    }
                                    }else
                                    {
                                        break;
                                    }
                            }
                        }else
                        {
                            printf("\n           PRIMERO DEBE DE INGRESAR DATOS PARA BORRAR\n");
                        }
                        break;
                case 4:
                        //OPCION 4 SOLO MUESTRA LOS DATOS SOLO SI SE INGRESARON.
                        if(flagEnter == 1){
                           toShowInformation(arrayEmployees,QTY_EMPLOYEE,accumulatorSalary,average);
                        }else{
                            printf("\n           PARA VER DATOS DEBE DE INGRESAR ALGUNO\n");
                        }
                break;
            }
        }while(option!=5);

    }else{
            printf("\n  HUBO UN ERROR AL INICIALIZAR ARRAY DE EMPLEADOS \n");
    }
        messageThanks();


    return 0;
}
