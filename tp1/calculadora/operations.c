#include <stdio.h>
#include <stdio.h>
#include "operations.h"

float resta(float numeroUno,float numeroDos)
{
     float totalResta;
     totalResta = numeroUno-numeroDos;
     return totalResta;
}


float suma(float numeroUno,float numeroDos)
{
    float totalSuma;
    totalSuma = numeroUno+numeroDos;
    return totalSuma;
}

float division(float numeroUno, float numeroDos)
{
        float totalDivision;
        totalDivision = numeroUno/numeroDos;
        return totalDivision;
}

float multiplicacion(float numeroUno,float numeroDos)
{
    float totalMultiplicacion;
    totalMultiplicacion = numeroUno*numeroDos;
    return totalMultiplicacion;
}


int factorial(float num){
    int factorial;
    int i;
    factorial = 1;

        if (num<0){
            return -1;
        }else{
                for(i=1; i <= num; i++){
                    factorial = factorial * i;
                }
                    return factorial;
        }
}
