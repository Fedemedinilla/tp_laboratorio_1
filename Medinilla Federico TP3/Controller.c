#include <stdio.h>
#include <stdlib.h>
#include "misFuncionesGet.h"
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee)
{
    int error=1;
    char sobreescribe;
    FILE* f;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            if(ll_len(pArrayListEmployee)>0)
            {
                if(!getDosChar("\nEl fichero ya tiene datos cargados. Desea sobreescribirlos?(S/N): ","\nERROR - Re-ingrese 's' o 'n'.",'n','s'))
                {
                    sobreescribe='n';
                }
                else
                {
                    sobreescribe='s';
                }
            }
            if(ll_len(pArrayListEmployee)==0 || sobreescribe=='s')
            {
                ll_clear(pArrayListEmployee);
                parser_EmployeeFromText(f,pArrayListEmployee);
                error=0;
            }
        }
    }
    fclose(f);

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path ,LinkedList* pArrayListEmployee)
{
    int error=1;
    char sobreescribe;
    FILE* f;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"rb");
        if(f!=NULL)
        {
            if(ll_len(pArrayListEmployee)>0)
            {
                if(!getDosChar("\nEl fichero ya tiene datos cargados. Desea sobreescribirlos?(S/N): ","\nERROR - Re-ingrese 's' o 'n'.",'n','s'))
                {
                    sobreescribe='n';
                }
                else
                {
                    sobreescribe='s';
                }
            }
            if(ll_len(pArrayListEmployee)==0 || sobreescribe=='s')
            {
                ll_clear(pArrayListEmployee);
                parser_EmployeeFromBinary(f,pArrayListEmployee);
                error=0;
            }
        }
    }
    fclose(f);

    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(char* msg,LinkedList* pArrayListEmployee,int* id)
{
    int error=1;
    int auxId;
    Employee* auxEmpleado=NULL;

    printf(msg);
    if(pArrayListEmployee!=NULL && employee_buscarUltimoId(pArrayListEmployee,&auxId)==0)
    {
        printf("El siguiente id es: %d",auxId);
        auxEmpleado=employee_new();
        if(auxEmpleado!=NULL)
        {
            if(!getNombre(auxEmpleado->nombre,"\nIngrese el NOMBRE: ","\nERROR - Re-ingrese el nombre.",128)
               &&!getNumero(&auxEmpleado->horasTrabajadas,"\nIngrese el numero de HORAS TRABAJADAS(10-1000): ","\nERROR - Re-ingrese un numero valido.",10,1000)
               &&!getNumero(&auxEmpleado->sueldo,"\nIngrese el SUELDO(1000-100000): ","\nERROR - Re-ingrese el sueldo.",1000,100000))
            {
                auxEmpleado->id=auxId;

                printf("\nEste es el empleado que desea agregar?\n");
                controller_ShowEmployee(auxEmpleado);
                if(!getDosChar("\nIngrese S para confirmar o N para negar: ","ERROR - Re-ingrese S o N.",'s','n'))
                {
                    if(!ll_add(pArrayListEmployee,auxEmpleado))
                    {
                        *id=auxId+1;
                        auxEmpleado=NULL;
                        error=0;
                    }
                }
            }
        }
    }

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* auxEmpleado=NULL;
    Employee* auxEmpleado2=NULL;
    int idParaModificar;
    int indiceParaModificar;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployees(pArrayListEmployee);
        if(!getNumero(&idParaModificar,"\nIngrese el ID que quiere modificar: ","\nERROR - Re-ingrese un ID valido.",1,1000))
        {
            auxEmpleado=employee_buscarXid(pArrayListEmployee,idParaModificar,&indiceParaModificar);
            controller_ShowEmployee(auxEmpleado);
            if(!getDosChar("\nEste es el empleado que desea modificar?(S/N): ","\nERROR - Re-ingrese S o N.",'s','n'))
            {
                auxEmpleado2=employee_menuModificion(auxEmpleado);
                if(auxEmpleado2->id>0)
                {
                    if(!ll_set(pArrayListEmployee,indiceParaModificar,auxEmpleado))
                    {
                        auxEmpleado=NULL;
                        auxEmpleado2=NULL;
                        error=0;
                    }
                }
            }
        }
    }

    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* auxEmpleado=NULL;
    int idParaBorrar;
    int indiceParaBorrar;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployees(pArrayListEmployee);
        if(!getNumero(&idParaBorrar,"\nIngrese el ID del empleado para borrar: ","\nERROR - Re-ingrese un ID valido.",1,1000))
        {
            auxEmpleado=employee_buscarXid(pArrayListEmployee,idParaBorrar,&indiceParaBorrar);
            controller_ShowEmployee(auxEmpleado);
            if(!getDosChar("\nEste es el empleado que desea eliminar de la faz de la tierra?(S/N): ","\nERROR - Re-ingrese s o n.",'s','n'))
            {
                if(ll_remove(pArrayListEmployee,indiceParaBorrar)==0)
                {
                    auxEmpleado=NULL;
                    error=0;
                }
                else
                {
                    error=1;
                }
            }
            else
            {
                error=1;
            }
        }
    }

    return error;
}
/** \brief Muestra un empleado
 *
 * \param emp Employee*
 * \return int
 *
 */
int controller_ShowEmployee(Employee* emp)
{
    int error=1;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(emp!=NULL)
    {
        if(!employee_getId(emp,&id)
        &&!employee_getNombre(emp,nombre)
        &&!employee_getHorasTrabajadas(emp,&horasTrabajadas)
        &&!employee_getSueldo(emp,&sueldo))
        {
            printf("\n%3d %s %4d %4d\n",id,nombre,horasTrabajadas,sueldo);
            error=0;
        }
    }

    return error;
}
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* auxEmpleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("\n|ID|  |Nombre|  |Horas|  |Sueldo|\n");
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmpleado=(Employee*) ll_get(pArrayListEmployee,i);
            controller_ShowEmployee(auxEmpleado);
            error=0;
        }
    }

    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int menuOpcion;

    if(pArrayListEmployee!=NULL)
    {
        if(!getNumero(&menuOpcion,
                      "\n*** Menu de Ordenamiento ***\n\n"
                      "\n1) Ordenar por NOMBRE ASCENDENTE++"
                      "\n2) Ordenar por NOMBRE DESCENDENTE--"
                      "\n\n3) Ordenar por HORAS TRABAJADAS ASCENDENTE++"
                      "\n4) Ordenar por HORAS TRABAJADAS DESCENDENTE--"
                      "\n\n5) Ordenar por SUELDO ASCENDENTE++"
                      "\n6) Ordenar por SUELDO DESCENDENTE--"
                      "\n\nIngrese una opcion: ",
                      "\nERROR - Ingrese una opcion valida entre el 1 y el 6.",1,6))
        {
            switch(menuOpcion)
            {
            case 1:
                printf("\n*** Ordenando empleados por nombre ASCENDENTE ***\n");
                if(!ll_sort(pArrayListEmployee,employee_sortByName,1))
                {
                    printf("\nEmpleados ordenados por nombre ASCENDENTE.");
                }
                else
                {
                    printf("\nERROR al ordenar los empleados correctamente.");
                }
                break;
            case 2:
                printf("\n*** Ordenando empleados por nombre DESCENDENTE ***\n");
                if(!ll_sort(pArrayListEmployee,employee_sortByName,0))
                {
                    printf("\nEmpleados ordenados por nombre DESCENDENTE.");
                }
                else
                {
                    printf("\nERROR al ordenar los empleados correctamente.");
                }
                break;
            case 3:
                printf("\n*** Ordenando empleados por horas trabajadas ASCENDENTE***\n");
                if(!ll_sort(pArrayListEmployee,employee_sortByHoras,1))
                {
                    printf("\nEmpleados ordenados por horas trabajadas ASCENDENTE.");
                }
                else
                {
                    printf("\nERROR al ordenar los empleados correctamente.");
                }
                break;
            case 4:
                printf("\n*** Ordenando empleados por horas trabajadas DESCENDENTE ***\n");
                if(!ll_sort(pArrayListEmployee,employee_sortByHoras,0))
                {
                    printf("\nEmpleados ordenados por horas trabajadas DESCENDENTE.");
                }
                else
                {
                    printf("\nERROR al ordenar los empleados correctamente.");
                }
                break;
            case 5:
                printf("\n*** Ordenando empleados por el sueldo ASCENDENTE ***\n");
                if(!ll_sort(pArrayListEmployee,employee_sortBySueldo,1))
                {
                    printf("\nEmpleados ordenados por el sueldo ASCENDENTE.");
                }
                else
                {
                    printf("\nERROR al ordenar los empleados correctamente.");
                }
                break;
            case 6:
                printf("\n*** Ordenando empleados por el sueldo DESCENDENTE ***\n");
                if(!ll_sort(pArrayListEmployee,employee_sortBySueldo,0))
                {
                    printf("\nEmpleados ordenados por el sueldo DESCENDENTE.");
                }
                else
                {
                    printf("\nERROR al ordenar los empleados correctamente.");
                }
                break;
            }
        }
        error=0;
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path ,LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f;
    Employee* auxEmpleado=NULL;
    char confirma = 's';

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL)
        {
            if(!getDosChar("\nEl archivo ya tiene datos cargados, desea sobreescribirlos?(S/N): ","\nERROR - Ingrese S o N.",'s','n'))
            {
                confirma='s';
            }
            else
            {
                confirma='n';
            }
        }
        fclose(f);

        if(confirma=='s')
        {
            f=fopen(path,"w");
            if(f!=NULL)
            {
                fprintf(f,"Id,Nombre,HorasTrabajadas,Sueldo\n");
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                    if(auxEmpleado!=NULL)
                    {
                        fprintf(f,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
                        auxEmpleado=NULL;
                        error=0;
                    }
                    else
                    {
                        printf("\nERROR con el FPRINTF");
                        error=1;
                        break;
                    }
                }
            }
        }
    }
    fclose(f);

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* auxEmpleado=NULL;
    FILE* f;
    char confirma='s';

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"rb");
        if(f!=NULL)
        {
            if(!getDosChar("\nEl archivo ya tiene datos cargados, desea sobreescribirlos?(S/N): ","\nERROR - Ingrese S o N.",'s','n'))
            {
                confirma='s';
            }
            else
            {
                confirma='n';
            }
        }
        fclose(f);

        if(confirma=='s')
        {
            f=fopen(path,"wb");
            if(f!=NULL)
            {
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
                    if(auxEmpleado!=NULL)
                    {
                        if(fwrite(auxEmpleado,sizeof(Employee),1,f)<1)
                        {
                            break;
                        }
                        else
                        {
                            error=0;
                        }
                    }
                }
            }
        }
    }
    fclose(f);

    return error;
}

