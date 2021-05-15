#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#endif // GETFUNCTIONS_H_INCLUDED
#include <string.h>


/** \brief ingresa y valida un dato del tipo INT.
 *
 * \param char*
 * \param char*
 * \return int
 *
 */
int checkInt(char*,char*);

/** \brief ingresa y valida un dato del tipo FLOAT.
 *
 * \param char*
 * \param char*
 * \return float
 *
 */
float checkFloat(char*,char*);

/** \brief ingresa y valida un dato del tipo STRING.
 *
 * \param char*
 * \param char*
 * \param char*
 * \param int
 * \return void
 *
 */
void checkString(char*,char*,char*,int);

/** \brief valida la opcion elegida por el usuario.
 *
 * \param char*
 * \return int
 *
 */
int menuOption(char*);




