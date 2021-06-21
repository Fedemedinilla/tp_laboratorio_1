#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#endif // ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}sEmployee;

/** \brief inicializa la estructura de sEmployee. Cambiandole el campo isEmpty a 1/VACIO.
 *
 * \param sEmployee*
 * \param int
 * \return int error
 *
 */
int initEmployees(sEmployee*,int);

/** \brief imprime el encabezado de la tabla.
 *
 * \return void
 *
 */
void tableHeaders();

/** \brief imprime UN empleado.
 *
 * \param sEmployee
 * \return void
 *
 */
void showEmployee(sEmployee);

/** \brief imprime TODOS los empleados
 *
 * \param sEmployee*
 * \param int
 * \return int
 *
 */
int showEmployees(sEmployee*,int);

/** \brief busca los empleados con el campo isEmpty VACIO.
 *
 * \param sEmployee*
 * \param int
 * \return int
 *
 */
int searchEmpty(sEmployee*,int);

/** \brief busca los empleados con el .id especificado.
 *
 * \param sEmployee*
 * \param int
 * \param int
 * \return int
 *
 */
int searchById(sEmployee*,int,int);

/** \brief agrega un empleado (sEmployee) al array de empleados.
 *
 * \param sEmployee*
 * \param int
 * \param int
 * \return int error
 *
 */
int addEmployee(sEmployee*,int,int);

/** \brief valida entre y o n.
 *
 * \return char
 *
 */
char choiceFunction();

/** \brief elimina un empleado del array.
 *
 * \param sEmployee*
 * \param int
 * \return int
 *
 */
int delEmployee(sEmployee*,int);

/** \brief modifica los campos de un empleado(.name,.lastName,etc)
 *
 * \param sEmployee*
 * \param int
 * \return int error
 *
 */
int changeEmployee(sEmployee*,int);

/** \brief muestra el menu de opciones para modificar un empleado
 *
 * \param sEmployee*
 * \param int
 * \return int
 *
 */
int changeEmployeeMenu(sEmployee*,int);

/** \brief valida y pregunta de que modo el usuario desea ordenar la lista.
 *
 * \param sEmployee*
 * \param int
 * \return void
 *
 */
void sortFunctionValidation(sEmployee*,int);

/** \brief compara los strings de lastname.
 *
 * \param sEmployee*
 * \param int
 * \param int
 * \return int
 *
 */
int employeeSorting(sEmployee*,int,int);

/** \brief ordena la lista de forma ascendente dependiendo del .lastname.
 *
 * \param sEmployee*
 * \param int
 * \param int
 * \param int
 * \return void
 *
 */
void ascending(sEmployee*,int,int,int);

/** \brief ordena la lista de forma ascendente dependiendo del .lastname.
 *
 * \param sEmployee*
 * \param int
 * \param int
 * \param int
 * \return void
 *
 */
void descending(sEmployee*,int,int,int);

/** \brief calcula el promedio e imprime
 *
 * \param sEmployee*
 * \param int
 * \return void
 *
 */
void avrSalary(sEmployee*,int);

