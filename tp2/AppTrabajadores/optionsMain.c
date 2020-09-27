#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "utn_functions.h"
#include "optionsMain.h"

int firtsMain()
{

    int options;


    printf("\n =====================================================================\n");
    printf("|                                                                     |\n");
    printf("|------------ BIENVENIDO AL REGISTRO Y CONTROL DE EMPLEADOS ----------|\n");
    printf("|                                                                     |\n");
    printf("|                  1-DAR DE ALTA EMPLEADO                             |\n");
    printf("|                  2-MODIFICAR EMPLEADO                               |\n");
    printf("|                  3-DAR DE BAJA EMPLEADO                             |\n");
    printf("|                  4-LISTADO DE EMPLEADOS EXISTENTES                  |\n");
    printf("|                  5-SALIR                                            |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                                                                     |\n");
    printf(" =====================================================================\n");

    utn_getNumeroInt(&options,"   -Elija una opcion : ","\n Error !! Reingrese opcion entre 1 y 5 . \n",1,5,10);

    printf("=======================================================================\n");

    return options;
}

void mainSector()
{
    printf("\n-Ingrese sector  \n");
    printf("\n 1-Administrador de bases de datos");
    printf("\n 2-Administrador de redes ");
    printf("\n 3-Administrador web");
    printf("\n 4-Administrador informatico");
    printf("\n 5-Diseniador web");
    printf("\n 6-Otro\n");
}

int mainModification()
{

 int options;


    printf("\n =====================================================================\n");
    printf("|                                                                     |\n");
    printf("|------------         MENU DE MODIFICACION                  ----------|\n");
    printf("|                                                                     |\n");
    printf("|                  1-MODIFICAR NOMBRE                                 |\n");
    printf("|                  2-MODIFICAR APELLIDO                               |\n");
    printf("|                  3-MODIFICAR SALARIO                                |\n");
    printf("|                  4-MODIFICAR SECTOR                                 |\n");
    printf("|                  5-VOLVER                                           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                                                                     |\n");
    printf(" =====================================================================\n");

    utn_getNumeroInt(&options,"   -Elija una opcion : ","\n Error !! Reingrese opcion entre 1 y 5 . \n",1,5,10);

    printf("=======================================================================\n");

    return options;

}

int mainAlertClean()
{
   int removeId;

    printf("\n =========================================================================\n");
    printf("| ATENCION!!Esta por borrar datos muy importante que no se podran recuperar.|\n");
    printf("| Recuerde que ademas tiene la opcion de modificar los datos de la Id.      |\n");
    printf("| -Desea borrar la Id y junto a todos sus datos ?                           |\n");
    printf(" ===========================================================================\n");
    utn_getNumeroInt(&removeId,"\n -Presione 1 para confirmar, 0 para cancelar: ","\n -Error, la opcion ingresada no existe.\n",0,1,3);

    return removeId;
}
