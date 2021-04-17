#ifndef TP1_FUNCTIONS_H_INCLUDED
#define TP1_FUNCTIONS_H_INCLUDED
#endif // TP1_FUNCTIONS_H_INCLUDED

/** \brief Muestra el menu de opciones para el usuario.
 *
 * \param int primer numero.
 * \param int segundo numero.
 * \param int bandera de los calculos.
 * \param int bandera de los resultados.
 * \return int la opcion elegida por el usuario.
 *
 */
int mostrarMenu(int,int,int,int);

/** \brief permite el ingreso de un numero(int) por el usuario.
 *
 * \return int el numero elegido por el usuario.
 *
 */
int ingresarNumero();
/** \brief realiza la operacion SUMAR de dos numeros enteros.
 *
 * \param int un numero entero.
 * \param int un numero entero.
 * \return int el resultado de la RESTA de los dos numeros enteros que ingresaron.
 *
 */
int sumar(int,int);
/** \brief realiza la operacion RESTAR de dos numeros enteros.
 *
 * \param int un numero entero.
 * \param int un numero entero.
 * \return int el resultado de la RESTA de los dos numeros enteros que ingresaron.
 *
 */
int restar(int,int);
/** \brief realiza la operacion MULTIPLICAR de dos numeros enteros.
 *
 * \param int un numero entero.
 * \param int un numero entero.
 * \return int el resultado de la MULTIPLICACION de los dos numeros enteros que ingresaron.
 *
 */
int multiplicar(int,int);
/** \brief realiza la operacion DIVIDIR de dos numeros enteros
 *
 * \param int un numero entero.
 * \param int un numero entero.
 * \return double devuelve el resultado en DOUBLE de la DIVISION de los dos numeros enteros que ingresaron.
 *
 */
double dividir(int,int);
/** \brief realiza la operacion factorial del numero ingresado.
 *
 * \param int un numero entero.
 * \return long long el resultado factorial(en long long int) del numero ingresado.
 *
 */
long long factorial(int);
/** \brief sirve de bandera para iniciar las funciones matematicas.
 *
 * \param int la bandera del num1.
 * \param int la bandera del num2.
 * \return int bandera del paso 3, calcular.
 *
 */
int calcular(int,int);
/** \brief muestra los resultados de las funciones matematicas.
 *
 * \param int la bandera del num1.
 * \param int la bandera del num2.
 * \param int la bandera del paso 3, calcular.
 * \return int bandera del paso 4, mostrar resultados.
 *
 */
int mostrarResultados(int,int,int);
/** \brief controla el loop de la funcion mostrarMenu. Le pregunta al usuario si desea salir.
 *
 * \return int devuelve el bool de seguir o no en el programa.
 *
 */
int salir();
