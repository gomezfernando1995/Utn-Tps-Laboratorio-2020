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
 eEmployee arrayEmployee[QTY_EMPLOYEE];
 //eEmployee auxiliaryEmployees;

 char   auxiliaryNameStr[LONG_NAME];
 char   auxiliaryLastNameStr[LONG_NAME];
 int    auxiliaryId;
 int    auxiliaryIdForClear;
 int    auxiliarySector;
 float  auxiliarySalary;

 int removeId;
 int indexFree;
 int indexResultSearch;
 int indexIdForClear;
 int option;
 int optionTwo;

 //int i,j;

    if(initializeArrayEmployee(arrayEmployee,QTY_EMPLOYEE)== 0)      /**< Se indica con -1 que esa posicion esta vacia;**/
    {
      do{
            option = firtsMain();
            switch(option)
            {
                case 1:
                    indexFree = searchIsEmpty(arrayEmployee,QTY_EMPLOYEE);
                    if(indexFree == -1)
                    {
                        printf("NO HAY LUGARES DISPONIBLES!!");
                    }else{

                        idRandom(indexFree,arrayEmployee,QTY_EMPLOYEE);
                        utn_getTexto(auxiliaryNameStr,"\n-Ingrese nombre del empleado: ","\n-Error, ingrese el nombre correctamente\n",5);
                        utn_getTexto(auxiliaryLastNameStr,"\n-Ingrese apellido del empleado: ","\n-Error, reingrese apellido\n",5);
                        utn_getNumeroFloat(&auxiliarySalary,"\n-Ingrese salario mensual: ","\n-Error, ingrese un sueldo correcto\n",0,10000000,5);

                        mainSector();
                        utn_getNumeroInt(&auxiliarySector,"\n -Ingrese opcion de 1 a 6 : ","\nError,reingrese sector\n",1,6,5);

                            switch(auxiliarySector){
                                case 1:
                                    strncpy(arrayEmployee[indexFree].sector,"Administrador de bases de datos",LONG_NAME);
                                break;
                                case 2:
                                    strncpy(arrayEmployee[indexFree].sector,"Administrador de redes",LONG_NAME);
                                break;
                                case 3:
                                    strncpy(arrayEmployee[indexFree].sector,"Administrador web",LONG_NAME);
                                break;
                                case 4:
                                    strncpy(arrayEmployee[indexFree].sector,"Administrador informatico",LONG_NAME);
                                break;
                                case 5:
                                    strncpy(arrayEmployee[indexFree].sector,"Diseniador web",LONG_NAME);
                                break;
                                case 6:
                                    strncpy(arrayEmployee[indexFree].sector,"Otro",LONG_NAME);
                                break;
                            }
                        arrayEmployee[indexFree].isEmpty = FALSE ;
                        strncpy(arrayEmployee[indexFree].name,auxiliaryNameStr,LONG_NAME);
                        strncpy(arrayEmployee[indexFree].lastName,auxiliaryLastNameStr,LONG_NAME);
                        arrayEmployee[indexFree].salary = auxiliarySalary;

                        }
                break;
                case 2:

                    if(utn_getNumeroInt(&auxiliaryId ,"\n-Ingrese Legajo a modificar: ","\nError, ingrese un legajo valido\n",1000,2000,3)== -1)
                    {
                        break;
                    }else{
                        indexResultSearch = searchIdEmployee(arrayEmployee,QTY_EMPLOYEE,auxiliaryId);
                    }
                    if(indexResultSearch == -1){
                        printf("\n -La id ingresada no existe\n");
                        break;
                    }else {

                        printf("\n-Datos de la id ingresada:\n\n -Apellido y Nombre: %s %s\n -Salario: $%.2f\n -Sector: %s\n",arrayEmployee[indexResultSearch].lastName,arrayEmployee[indexResultSearch].name,arrayEmployee[indexResultSearch].salary,arrayEmployee[indexResultSearch].sector);

                        // COMIENZO DEL MENU DE MODIFICACION
                        do{
                           optionTwo = mainModification();
                           switch(optionTwo)
                           {
                                case 1:
                                    utn_getTexto(auxiliaryNameStr,"\n-Ingrese nombre del empleado: ","\n-Error, ingrese el nombre correctamente\n",5);
                                    strncpy(arrayEmployee[indexResultSearch].name,auxiliaryNameStr,LONG_NAME);
                                break;
                                case 2:
                                    utn_getTexto(auxiliaryLastNameStr,"\n-Ingrese apellido del empleado: ","\n-Error, reingrese apellido\n",5);
                                    strncpy(arrayEmployee[indexResultSearch].lastName,auxiliaryLastNameStr,LONG_NAME);
                                break;
                                case 3:
                                    utn_getNumeroFloat(&auxiliarySalary,"\n-Ingrese salario mensual: ","\n-Error, ingrese un sueldo correcto\n",0,10000000,5);
                                    arrayEmployee[indexResultSearch].salary = auxiliarySalary;
                                break;
                                case 4:
                                    mainSector();
                                    utn_getNumeroInt(&auxiliarySector,"\n -Ingrese opcion de 1 a 6 : ","\nError,reingrese sector\n",1,6,5);

                                        switch(auxiliarySector){
                                            case 1:
                                                strncpy(arrayEmployee[indexResultSearch].sector,"Administrador de bases de datos",LONG_NAME);
                                            break;
                                            case 2:
                                                strncpy(arrayEmployee[indexResultSearch].sector,"Administrador de redes",LONG_NAME);
                                            break;
                                            case 3:
                                                strncpy(arrayEmployee[indexResultSearch].sector,"Administrador web",LONG_NAME);
                                            break;
                                            case 4:
                                                strncpy(arrayEmployee[indexResultSearch].sector,"Administrador informatico",LONG_NAME);
                                            break;
                                            case 5:
                                                strncpy(arrayEmployee[indexResultSearch].sector,"Diseñador web",LONG_NAME);
                                            break;
                                            case 6:
                                                strncpy(arrayEmployee[indexResultSearch].sector,"Otro",LONG_NAME);
                                            break;
                                         }
                                break;  // BREAK DEL CASE 4 DEL MENU DE MODIFICACION
                           }
                         }while(optionTwo !=5); // FIN DEL MENU DE MODIFICACIONES
                     }
                break; //FIN DEL CASE 2 DEL MENU PRINCIPAL
                case 3:

                    if(utn_getNumeroInt(&auxiliaryIdForClear,"\n-Ingrese Legajo a borrar: ","\nError, ingrese un legajo valido\n",1000,2000,3)== -1)
                    {
                        break;
                    }else{
                        indexIdForClear = searchIdEmployee(arrayEmployee,QTY_EMPLOYEE,auxiliaryIdForClear);
                    }
                    if(indexIdForClear == -1){
                        printf("\n -La id ingresada no existe\n");
                        break;
                    }else {
                        printf("\n-Datos de la id ingresada:\n\n -Apellido y Nombre: %s %s\n -Salario: $%.2f\n -Sector: %s\n",arrayEmployee[indexIdForClear].lastName,arrayEmployee[indexIdForClear].name,arrayEmployee[indexIdForClear].salary,arrayEmployee[indexIdForClear].sector);

                        if(mainAlertClean() == 1){

                            removeId = removeEmployee(arrayEmployee,QTY_EMPLOYEE,auxiliaryIdForClear);
                            if(removeId == -1)
                            {
                               printf("\n ERROR,NO SE PUDO BORRAR LA ID.\n");
                            }else{
                                printf("\n -----------------------------------------------------------------------");
                                printf("\n|                  La id a sido borrada con exito!                      |   \n");
                                printf(" -----------------------------------------------------------------------\n");
                            }

                        }else{
                            break;
                        }
                    }
            }
        }while(option!=5);

    }else{
            printf("HUBO UN ERROR AL INICIALIZAR ARRAY DE EMPLEADOS");
    }

    return 0;
}
