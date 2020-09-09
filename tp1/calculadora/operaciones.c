#include <stdio.h>
#include <stdio.h>
#include "operaciones.h"

float resta(float a,float b){
     float totalResta;
     totalResta = a-b;
     return totalResta;
}


float suma(float a,float b){
    float totalSuma;
    totalSuma = a+b;
    return totalSuma;
}

float division(float numUno, float numDos){
        float totalDivision;
        totalDivision = numUno/numDos;
        return totalDivision;
}

int factorial(float num){
    int factorial;
    int i;
    factorial = 1;

        if (num<=0){
            return 1;
        }else{
                for(i=1; i <= num; i++){
                    factorial = factorial * i;
                }
                    return factorial;
        }
}
