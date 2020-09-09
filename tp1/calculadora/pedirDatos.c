#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"

float dato(char texto[])
{
    float datoIngresado;

    printf("%s", texto);
    scanf("%f", &datoIngresado);

    return datoIngresado;
}
