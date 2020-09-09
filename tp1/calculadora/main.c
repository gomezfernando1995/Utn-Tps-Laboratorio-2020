#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"
#include "operaciones.h"


int main()
{
    float numUno;
    float numDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    int   resultadoFactorialUno;
    int   resultadoFactorialDos;
    int   opcion;
    int   flagOpcion;
    flagOpcion = 0;


    do{
         switch(opcion){
            case 1 :
                numUno= dato("-Ingrese primer numero :");

            break;
            case 2:
                numDos= dato("-Ingrese segundo numero:");
                flagOpcion = 1;
            break;
            case 3:
                if(flagOpcion == 0){
                    printf("Porfavor primero ingrese los valores para calcular");
                }else{
                        resultadoSuma = suma(numUno,numDos);
                }
            break;
            case 4:
                 if(flagOpcion == 0){
                    printf("Porfavor primero ingrese los valores para calcular");
                }else{
                    resultadoResta = resta(numUno,numDos);
                }
            break;
            case 5:
                 if(flagOpcion == 0){
                    printf("Porfavor primero ingrese los valores para calcular");
                }else{
                   resultadoFactorialUno = factorial(numUno);
                    resultadoFactorialDos = factorial(numDos);
                }
            break;
            case 6:
                 if(flagOpcion == 0){
                    printf("Porfavor primero ingrese los valores para calcular");
                }else{
                        if(numDos== 0){
                                resultadoDivision = 0;
                        }else {
                                resultadoDivision = division(numUno,numDos);
                        }
                }
            break;
            case 7:
                    printf("Gracias Por usar nuestra app!!");
            break;
         }

    }while(opcion != 7)

    printf("\n-Total suma: %.1f \n",resultadoSuma);
    printf("-Total resta: %.1f \n",resultadoResta);
     if(resultadoDivision == 0){
        printf("-No es posible dividir por el numero ingresado");
    }else{
        printf("-El resultado de la division es %.2f\n",resultadoDivision);
    }
    printf("-El factorial de %.1f es %d .\n-El factorial de %.1f es %d .",numUno,resultadoFactorialUno,numDos,resultadoFactorialDos);
}


