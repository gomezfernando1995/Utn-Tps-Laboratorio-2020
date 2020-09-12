#include <stdio.h>
#include <stdlib.h>
#include "dataEntry.h"
#include "operations.h"

int main()
{
    float numUno;
    float numDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int   resultadoFactorialUno;
    int   resultadoFactorialDos;
    int opcion;
    int flagOpcionUno;
    int flagOpcionDos;
    int flagOpcionTres;
    int flagUno;
    int flagDos;

    flagUno = 0;
    flagDos = 0;
    flagOpcionDos = 0;
    flagOpcionUno = 0;
    flagOpcionTres = 0;

    do{

            printf("\n============================================================\n");
            printf("------------------------CALCULADORA--------------------------\n");

                if(flagUno == 1 && flagDos == 1){
                        printf("\n1. Modificar primer operando, el existente es %.2f \n",numUno);
                        printf("2. Modificar segundo operando, el existente es %.2f \n",numDos);

                }else if(flagUno == 1 && flagDos == 0){
                        printf("\n1. Modificar primer operando, el existente es %.2f \n",numUno);
                        printf("2. Ingresar 2do operando: \n");

                }else if (flagDos == 1 && flagUno == 0){
                        printf("\n1. Ingresar 1er operando \n");
                        printf("2. Modificar segundo operando, el existente es %.2f \n",numDos);

                }else{
                        printf("\n1. Ingresar 1er operando \n");
                        printf("2. Ingresar 2do operando \n");
                }

                printf("3. Calcular todas las operaciones.\n");
                printf("     a) Calcular la suma (%.1f+%.1f).\n",numUno,numDos);
                printf("     b) Calcular la resta (%.1f-%.1f).\n",numUno,numDos);
                printf("     c) Calcular la division (%.2f / %.0f).\n",numUno,numDos);
                printf("     d) Calcular la multiplicacion (%.2f*%.2f).\n",numUno,numDos);
                printf("     e) Calcular el factorial del primer operando (%.0f!).\n",numUno);
                printf("     f) Calcular el factorial del segundo operando(%.0f!).\n",numDos);

                printf("4. Informar resultados.\n");
                printf("5. Salir\n");
                printf("\n============================================================\n");
                printf("-Elija una opcion :  ");
                scanf("%d",&opcion);

                while(opcion<1 || opcion>5 ){
                    printf("\nError, ingrese una opcion correcta: ");
                    fflush(stdin);
                    scanf("%d",&opcion);
                 }

            switch(opcion){
                case 1:
                    numUno = datos("\n-Ingrese primer operando: ");
                    flagUno = 1;
                    flagOpcionUno=1;

                break;
                case 2:
                    numDos = datos("\n-Ingrese segundo operando:");
                    flagDos = 1;
                    flagOpcionDos=1;
                break;
                case 3:
                    if(flagOpcionDos == 0 && flagOpcionUno==0){
                        printf("\n!!Primero ingrese los valores para calcular!!\n");
                    }else if(flagUno == 0 && flagDos==1){
                        printf("\n!!Falta ingresar el primer valor!!");
                    }else if(flagUno==1 && flagDos==0){
                        printf("\n!!Falto ingresar el segundo valor!!");
                    }else{
                        resultadoSuma = suma(numUno,numDos);
                        resultadoResta = resta(numUno,numDos);
                        if(numDos==0){
                            resultadoDivision = 0;
                        }else {
                            resultadoDivision = division(numUno,numDos);
                        }
                        resultadoMultiplicacion = multiplicacion(numUno,numDos);
                        resultadoFactorialUno = factorial(numUno);
                        resultadoFactorialDos = factorial(numDos);
                        }
                    flagOpcionTres =1;
                break;
                case 4:
                    if(flagOpcionDos == 0 && flagOpcionUno==0){
                        printf("\n!!Primero ingrese los valores para calcular!!\n");
                    }else if(flagUno == 0 && flagDos==1){
                        printf("\n!!Falta ingresar el primer valor!!");
                    }else if(flagUno==1 && flagDos==0){
                        printf("\n!!Falto ingresar el segundo valor!!");
                    }else if ( flagUno==1 && flagDos==1 && flagOpcionTres == 1){
                        printf("\n=============================== RESULTADOS ========================================\n");
                        printf("\n            a)El resultado de %.1f + %.1f es: %.1f\n",numUno,numDos,resultadoSuma);
                        printf("            b)El resultado de %.1f - %.1f es: %.1f\n",numUno,numDos,resultadoResta);
                            if(resultadoDivision == 0){
                                printf("            c)No es posible dividir por 0\n");
                            }else{
                                printf("            c)El resultado de %.2f / %.2f es: %.2f \n",numUno,numDos,resultadoDivision);
                            }
                                printf("            d)El resultado de %.2f * %.2f  es: %.2f \n",numUno,numDos,resultadoMultiplicacion);
                            if(resultadoFactorialUno == -1){
                                printf("            e)No se puede calcular el factorial de un numero negativo.\n");

                            }else{
                                printf("            e)El primer valor ingresado  es  %.0f!  y su factorial es: %d\n",numUno,resultadoFactorialUno);
                            }
                            if(resultadoFactorialDos == -1){
                                printf("            f)No se puede calcular el factorial de tal numero.\n");

                            }else {
                                printf("            f)El segundo valor ingresado  es  %.0f!  y su factorial es: %d\n",numDos,resultadoFactorialDos);
                            }

                        printf("\n===================================================================================\n");
                    }else {
                        printf("\nDebe de calcular los resultados para mostrarlos\n");
                    }

                break;
                case 5:
                    printf("\n---------------------------------------------\n");
                    printf("\nGRACIAS POR INGRESAR VUELVA PRONTO !!!\n");
                    printf("\n---------------------------------------------\n");
                    printf("Creador Gomez Fernando");
            }

    }while(opcion != 5);

    return 0;
}
