#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
#include "ArrayEmployees.h"


int mostrarMenu()
{
    int choice;

    printf("\n            *** Bienvenido! *** \n\n");
    printf("    1- ALTAS.\n");
    printf("    2- MODIFICAR.\n");
    printf("    3- BAJAS.\n");
    printf("    4- INFORMAR >>\n");
    printf("    5- SALIR.\n");

    choice=menuOption("\nIngrese una opcion: ");

    return choice;
}
int validarSalida()
{
    char salir;
    int retorno;
    retorno=0;
    printf("    Desea salir?(Y/N)\n");
    fflush(stdin);
    printf("    ");
    scanf("%c",&salir);
    salir=tolower(salir);
    while(salir!='y'&&salir!='n')
    {
        printf("    ERROR. Opcion invalida, debe elegir entre Y/N\n");
        fflush(stdin);
        scanf("%c",&salir);
        salir=tolower(salir);
    }
    if(salir=='y')
    {
        system("cls");
        printf("\n          *** Nos vemos! *** \n");
        retorno=1;
    }
    else
    {
        system("cls");
    }
    return retorno;
}
int showMiniMenu()
{
    system("cls");
    int choice;
    printf("\n       *** INFORMAR ***      \n");
    printf("\n1- Mostrar empleados ordenados alfabeticamente por apellido y sector.");
    printf("\n2- Mostrar el total y el promedio de los salarios y cuantos empleados superan ese promedio.");
    printf("\n3- Volver al menu principal.\n");

    choice=menuOption("\nIngrese una opcion: ");

    return choice;
}

