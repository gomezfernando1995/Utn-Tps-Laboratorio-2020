#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/** \brief Esta funcion carga los valores ingresados por el usuario y los suma.
 *
 * \param numeroUno float Se carga a la funcion el primer valor ingresado.
 * \param numeroDos float Se carga a la funcion el segundo valor ingresado.
 * \return float Retorna la suma de los dos valores ingresados.
 *
 */

        float suma(float numeroUno,float numeroDos);

/** \brief Esta funcion carga los valores ingresados por el usuario y los resta.
 *
 * \param numeroUno float Se  carga a la funcion el primer valor ingresado.
 * \param numeroDos float Se  carga a la funcion el segundo valor ingresado.
 * \return float Retorna la resta de los dos valores ingresados.
 *
 */

        float resta(float numeroUno,float numeroDos);

/** \brief Esta funcion carga los valores ingresados por el usuario y los divide.
 *
 * \param numeroUno float Se  carga a la funcion el primer valor ingresado.
 * \param numeroDos float Se  carga a la funcion el segundo valor ingresado.
 * \return float    Retorna la division de los dos valores ingresados.
 *
 */
        float division(float numeroUno, float numeroDos);


/** \brief Esta funcion carga los valores ingresados por el usuario y los multiplica.
 *
 * \param numeroUno float Se  carga a la funcion el primer valor ingresado.
 * \param numeroDos float Se  carga a la funcion el segundo valor ingresado.
 * \return float  Retorna la multiplicacion de los dos valores ingresados.
 */
        float multiplicacion(float numeroUno,float numeroDos);

/** \brief Esta funcion carga el valor ingresado por el usuario y calcula el factorial.
 *
 * \param float Se carga a la funcion el valor ingresado por el usuario.
 * \return int Retorna el factorial del valor ingresado por el usuario.
 *
 */
        int factorial(float num);

#endif // OPERACIONES_H_INCLUDED
