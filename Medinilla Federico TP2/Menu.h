#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#endif // MENU_H_INCLUDED


/** \brief imprime el menu principal de opciones
 *
 * \return int
 *
 */
int mostrarMenu();

/** \brief valida si el usuario desea salir del menu o no.
 *
 * \return int
 *
 */
int validarSalida();

/** \brief imprime el menu de la opcion 4(INFORMAR)
 *
 * \return int
 *
 */
int showMiniMenu();

/** \brief valida la opcion elegida por el usuario.
 *
 * \param char*
 * \return int
 *
 */
int menuOption(char*);
