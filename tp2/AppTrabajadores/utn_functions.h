#ifndef UTN_FUNCTIONS_H_INCLUDED
#define UTN_FUNCTIONS_H_INCLUDED

int utn_getNumeroIntSinReintentos(int* pResultado, char* mensaje, char* mensajeError);
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloatSinReintentos(float* pResultado, char* mensaje, char* mensajeError);
int utn_getTexto(char pResultado[], char* mensaje, char* mensajeError, int reintentos);

#endif // UTN_FUNCTIONS_H_INCLUDED
