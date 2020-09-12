#include <stdio.h>
#include <stdlib.h>
#include "dataEntry.h"

float datos(char texto[]){

    float numeroIngresado;


    printf("%s",texto);
    while(!(scanf("%f",&numeroIngresado)== 1)){

        fflush(stdin);
        printf("\nError, el valor ingresado no es un numero. Ingrese un numero: \n");
    }

    return numeroIngresado;

}

