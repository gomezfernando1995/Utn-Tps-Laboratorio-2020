#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "utn_functions.h"
#include "optionsMain.h"


/** \brief MENU PRINCIPAL.
 * \return RETORNA LA OPCION INGRESADA POR EL USUARIO.
 *
 */
int firstMain()
{
    int options;


    printf("\n           =====================================================================\n");
    printf("          |                                                                     |\n");
    printf("          |------------ BIENVENIDO AL REGISTRO Y CONTROL DE EMPLEADOS ----------|\n");
    printf("          |                                                                     |\n");
    printf("          |                  1-DAR DE ALTA EMPLEADO                             |\n");
    printf("          |                  2-MODIFICAR EMPLEADO                               |\n");
    printf("          |                  3-DAR DE BAJA EMPLEADO                             |\n");
    printf("          |                  4-LISTADO DE EMPLEADOS EXISTENTES                  |\n");
    printf("          |                  5-SALIR                                            |\n");
    printf("          |---------------------------------------------------------------------|\n");
    printf("          |                                                                     |\n");
    printf("           =====================================================================\n");

    utn_getNumeroInt(&options,"             -Elija una opcion : ","\n Error !! Reingrese opcion entre 1 y 5 . \n",1,5,10);

    printf("           ===================================================================== \n");

    return options;
}



/** \brief MENU DE MODIFICACIONES.
 * \return RETORNA LA OPCION INGRESADA POR EL USUARIO.
 *
 */
int mainModification()
{

 int options;


    printf("\n           =====================================================================\n");
    printf("          |                                                                     |\n");
    printf("          |---------------------    MENU DE MODIFICACION  ----------------------|\n");
    printf("          |                                                                     |\n");
    printf("          |                  1-MODIFICAR NOMBRE                                 |\n");
    printf("          |                  2-MODIFICAR APELLIDO                               |\n");
    printf("          |                  3-MODIFICAR SALARIO                                |\n");
    printf("          |                  4-MODIFICAR SECTOR                                 |\n");
    printf("          |                  5-VOLVER                                           |\n");
    printf("          |---------------------------------------------------------------------|\n");
    printf("          |                                                                     |\n");
    printf("           =====================================================================\n");

    utn_getNumeroInt(&options,"          -Elija una opcion : ","\n       Error !! Reingrese opcion entre 1 y 5 . \n",1,5,10);

    printf("           =======================================================================\n");

    return options;

}



/** \brief DA UN ALERTA AL USUARIO.
 * \return RETORNA LA OPCION INGRESADA POR EL USUARIO, SI CONFIRMA O CANCELA BORRAR EL DATO.
 *
 */
int mainAlertClean()
{
   int removeId;

    printf("\n         ===========================================================================\n");
    printf("        | ATENCION!!Esta por borrar datos muy importante que no se podran recuperar.|\n");
    printf("        | Recuerde que ademas tiene la opcion de modificar los datos de la Id.      |\n");
    printf("        | -Desea borrar la Id junto a todos sus datos ?                             |\n");
    printf("         ===========================================================================\n");
    utn_getNumeroInt(&removeId,"\n           -Presione 1 para confirmar, 0 para cancelar: ","\n       -Error, la opcion ingresada no existe.\n",0,1,3);

    return removeId;
}

/** \brief MENU DE ORDENAMIENTO.
 * \return RETORNA LA OPCION INGRESADA PARA SU ORDENAMIENTO.
 *
 */
int mainSort(void)
{
    int option;
    printf("\n\n       ============================ OPCION DE ORDEN ===================================\n");
    printf("      |          1-Ordenar por apellido y sector de manera ascendente                  |\n");
    printf("      |          2-Ordenar por apellido y sector de manera descendente                 |\n");
    printf("      |          3-Volver                                                              |\n");
    printf("       ================================================================================\n");

    utn_getNumeroInt(&option,"\n    -Elija una opcion: ","\n        Error, la opcion que eligio no existe",1,3,5);

    return option;
}

/** \brief MENSAJE DE AGRADECIMIENTO
 * \return  RETORNA EL MENSAJE DE AGRADECIMENTO AL FINALIZAR EL PROGRAMA.
 *
 */
void messageThanks()
{
    printf("         ===========================================================================\n");
    printf("        |             GRACIAS POR USAR NUESTRO SISTEMA, VUELVA PRONTO !!            |\n");
    printf("         ===========================================================================\n");
}

