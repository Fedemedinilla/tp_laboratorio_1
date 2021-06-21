#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
#include "ArrayEmployees.h"
#include "getFunctions.h"
#define TAM 1000


int main()
{
    setbuf(stdout,NULL);
    sEmployee list[TAM];
    int checkSalida;
    int nextId;
    char keepAdding;
    char miniMenu;
    checkSalida=0;
    nextId=100;

    if(initEmployees(list,TAM))
    {
        printf("\n*ERROR:\nFallo al inicializar...\n");
    }
    else
    {
        printf("\n*Base de datos inicializada correctamente.\n");
    }

    do
    {
        switch(mostrarMenu())
        {
        case 1:
            do
            {
                system("cls");
                if(addEmployee(list,TAM,nextId)==0)
                {
                    system("cls");
                    nextId++;
                    printf("\n*Alta realizada con exito.\n");
                    showEmployees(list,TAM);
                    printf("\nDesea agregar otro empleado?(Y/N)\n");
                    keepAdding=choiceFunction();
                }
                else
                {
                    printf("\n*ERROR:\nNo se pudo realizar el alta.\n");
                }
                system("cls");
            }while(keepAdding!='n');
            break;
        case 2:
            do
            {
                if(changeEmployee(list,TAM)==0)
                {
                    printf("Modificacion realizada con exito!\n");
                    printf("\nDesea modificar otro empleado?(Y/N)\n");
                    keepAdding=choiceFunction();
                }
                else
                {
                    printf("*ERROR:\nNo se pudo realizar la modificacion.\n");
                    printf("\nDesea modificar otro empleado?(Y/N)\n");
                    keepAdding=choiceFunction();
                }

                system("cls");
            }while(keepAdding!='n');

            break;
        case 3:
            do
            {
                system("cls");
                if(delEmployee(list,TAM)==0)
                {
                    system("cls");
                    printf("\n*Baja realizada con exito.\n");
                    printf("\nDesea dar de baja otro empleado?(Y/N)\n");
                    keepAdding=choiceFunction();
                }
                else
                {
                    printf("\n*ERROR:\nNo se pudo realizar la baja.\n");
                    printf("\nDesea dar de baja otro empleado?(Y/N)\n");
                    keepAdding=choiceFunction();
                }
                system("cls");
            }while(keepAdding!='n');
            break;
        case 4:
            do
            {
                system("cls");

                switch(showMiniMenu())
                {
                case 1:
                    do
                    {
                        tableHeaders();
                        sortFunctionValidation(list,TAM);
                        printf("Desea ordernarlos de otra manera?(Y/N)\n");
                        keepAdding=choiceFunction();
                        system("cls");
                    }while(keepAdding!='n');
                    break;
                case 2:
                    showEmployees(list,TAM);
                    avrSalary(list,TAM);
                    printf("Desea volver al menu principal?(Y/N)\n");
                    miniMenu=choiceFunction();
                    system("cls");
                    break;
                case 3:
                    printf("Desea volver al menu principal?(Y/N)\n");
                    miniMenu=choiceFunction();
                    system("cls");
                    break;
                default:
                    printf("holi");
                    break;
                }
            }while(miniMenu!='y');
            break;
        case 5:
            checkSalida=validarSalida();
            break;
        default:
            system("cls");
            printf("\n*ERROR:\nDebe ingresar una opcion correcta.\n");
            break;
        }
    }while(checkSalida!=1);
}



