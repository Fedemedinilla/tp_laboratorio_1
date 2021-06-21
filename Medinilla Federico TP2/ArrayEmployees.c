#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Menu.h"
#include "ArrayEmployees.h"
#include "getFunctions.h"

#define OCUPADO 0
#define VACIO 1
#define MAXTAM 15

int initEmployees(sEmployee list[], int tam)
{
    int error=1;

    if(list!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            list[i].isEmpty=VACIO;
        }
        error=0;
    }

    return error;
}
int searchEmpty(sEmployee list[],int tam)
{
    int freeIndex=-1;

    for(int i=0;i<tam;i++)
    {
        if(list[i].isEmpty==VACIO)
        {
            freeIndex=i;
            break;
        }
    }

    return freeIndex;
}
void showEmployee(sEmployee auxEmployee)
{
    printf("  %4d %10s %10s                  %.2f        %2d\n",auxEmployee.id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector);
}
int showEmployees(sEmployee list[], int tam)
{
    int error=1;
    int flag=0;

    if(list!=NULL&&tam>0)
    {
        printf("\n   ID          Name            Last Name           Salary       Sector\n");
        printf("  -----------------------------------------------------------------  \n");
        for(int i=0;i<tam;i++)
        {
            if(list[i].isEmpty==0)
            {
                showEmployee(list[i]);
                flag = 1;
            }
        }

        printf("\n");

        if(flag ==0)
        {
            printf("*ERROR:\nNo hay empleados cargados para mostrar.\n");

        }
        error = 0;
    }

    return error;
}
int addEmployee(sEmployee list[],int tam, int id)
{
    int error=-1;
    int index;

    sEmployee auxEmployee;

        if(list!=NULL&&tam>0&&id>0)
        {
            index=searchEmpty(list,tam);

            if(index==-1)
            {
                system("cls");
                printf("\n*ERROR:\nNo hay lugar libre.\n");
            }
            else
            {
                printf("\n*Complete la siguiente informacion del empleado a ingresar: \n");
                auxEmployee.id=id;

                checkString(auxEmployee.name,"\nIngrese el NOMBRE(Max: 15 chars): ","\n*Error:\nNombre muy largo.\nRe-ingrese el NOMBRE: ",MAXTAM);
                checkString(auxEmployee.lastName,"\nIngrese el APELLIDO(Max: 15 chars): ","\n*Error:\nApellido muy largo.\nRe-ingrese el APELLIDO: ",MAXTAM);
                auxEmployee.salary=checkFloat("\nIngrese el SALARIO(Max: 999,999): ","\n*Error:\nSALARIO invalido.\nRe-ingrese el SALARIO: ");
                auxEmployee.sector=checkInt("\nIngrese el SECTOR(Max: 99): ","\n*Error:\nSECTOR invalido.\nRe-ingrese el SECTOR: ");

                auxEmployee.isEmpty=OCUPADO;
                list[index] = auxEmployee;

                error=0;
            }
        }

    return error;
}
char choiceFunction()
{
    char choice;

    fflush(stdin);
    scanf("%c",&choice);
    choice=tolower(choice);
    while(choice!='y'&&choice!='n')
    {
        printf("\nERROR:\nDebe elegir entre 'y'(yes) o 'n'(no)\n");
        fflush(stdin);
        scanf("%c",&choice);
        choice=tolower(choice);
    }

    return choice;
}
int delEmployee(sEmployee list[],int tam)
{
    int error=1;
    int id;
    int index;
    char choice;

    if(list!=NULL&&tam>0)
    {
        showEmployees(list,tam);
        printf("Ingrese el ID del empleado a dar de BAJA: ");
        scanf("%d",&id);

        index=searchById(list,tam,id);

        if(index==-1)
        {
            printf("\nNo hay ningun empleado con ese ID.\n");
        }
        else
        {
            showEmployee(list[index]);
            printf("Desea realizar la BAJA de este empleado?(Y/N)\n");
            choice=choiceFunction();
            if(choice=='y')
            {
                list[index].isEmpty=VACIO;
                error=0;
            }
        }
    }

    return error;
}
int searchById(sEmployee list[],int tam, int id)
{
    int index=-1;

    for(int i=0;i<tam;i++)
    {
        if(list[i].id==id&&list[i].isEmpty==OCUPADO)
        {
            index=i;
            break;
        }
    }
    return index;
}

int changeEmployee(sEmployee list[],int tam)
{
    int error=1;
    int id;
    int index;
    char choice;

    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;


    if(list!=NULL&&tam>0)
    {
        system("cls");
        showEmployees(list,tam);
        printf("\nIngrese el ID del empleado a MODIFICAR: ");
        scanf("%d",&id);

        index=searchById(list,tam,id);

        if(index==-1)
        {
            printf("\nNo hay ningun empleado con ese ID.\n\n");
        }
        else
        {
            system("cls");
            do
            {
                tableHeaders();
                showEmployee(list[index]);

                switch(changeEmployeeMenu(list,tam))
                {
                case 1:
                    checkString(newName,"\n\nIngrese el (NUEVO) NOMBRE(Max: 15 chars): ","\n*Error:\nNombre muy largo.\nRe-ingrese el NOMBRE: ",MAXTAM);
                    strcpy(list[index].name,newName);
                    system("cls");
                    printf("*Nombre modificado:\n");
                    break;
                case 2:
                    checkString(newLastName,"\nIngrese el (NUEVO) APELLIDO(Max: 15 chars): ","\n*Error:\nApellido muy largo.\nRe-ingrese el APELLIDO: ",MAXTAM);
                    strcpy(list[index].lastName,newLastName);
                    printf("Ingrese el NUEVO APELLIDO:");
                    system("cls");
                    printf("*Apellido modificado:\n");
                    break;
                case 3:
                    newSalary=checkFloat("\nIngrese el (NUEVO) SALARIO(Max: 999,999): ","\n*Error:\nSALARIO invalido.\nRe-ingrese el SALARIO: ");
                    list[index].salary=newSalary;
                    system("cls");
                    printf("*Salario modificado:\n");
                    break;
                case 4:
                    newSector=checkInt("\nIngrese el (NUEVO) SECTOR(Max: 99): ","\n*Error:\nSECTOR invalido.\nRe-ingrese el SECTOR: ");
                    list[index].sector=newSector;
                    system("cls");
                    printf("*Sector modificado:\n");
                    break;
                case 5:
                    printf("Desea volver al menu principal?(Y/N)\n");
                    choice=choiceFunction();
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("*ERROR:\nOpcion no valida.\n\n");
                    break;
                }
            }while(choice!='y');
            error=0;
        }

    }

    return error;
}
int changeEmployeeMenu(sEmployee list[],int tam)
{
    int choice;

    printf("\n1- Cambiar el nombre.\n");
    printf("2- Cambiar el apellido.\n");
    printf("3- Cambiar el salario.\n");
    printf("4- Cambiar el sector.\n");
    printf("5- Volver al menu principal.\n");

    choice=menuOption("\nIngrese una opcion: ");

    return choice;
}
void tableHeaders()
{
    printf("\n   ID          Name            Last Name           Salary       Sector\n");
    printf("  -----------------------------------------------------------------  \n");
}
void sortFunctionValidation(sEmployee list[],int tam)
{
    int sort;
    int flag;
    flag=0;

    for(int i=0;i<tam;i++)
    {
        if(list[i].isEmpty==0)
        {
            showEmployee(list[i]);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("\nERROR No hay empleados cargados.\n");
    }
    else
    {
        printf("\n1- Ascendente\n");
        printf("2- Descendente\n");
        printf("3- Volver al menu principal\n\n");
        scanf("%d",&sort);

        if(employeeSorting(list,tam,sort)==0)
        {
            system("cls");
            printf("Ordenamiento Realizado \n");
        }
        else
        {
            printf("Fallo \n");
        }
        showEmployees(list, tam);
    }
}
int employeeSorting(sEmployee list[], int tam, int sort)
{
    int error=-1;

        if(list==NULL&&tam<0)
        {
            error=1;
        }
        else
        {
            for(int i=0;i<tam-1;i++)
            {
                for(int x=i+1;x<tam;x++)
                {
                   ascending(list,i,x,sort);
                   descending(list,i,x,sort);
                }
                error=0;
            }
        }

     return error;
}
void ascending(sEmployee list[],int i, int x, int sort)
{
    sEmployee auxEmployee;
    if(strcmp(list[i].lastName,list[x].lastName)>0 &&sort==1)
    {
        auxEmployee=list[i];
        list[i]=list[x];
        list[x]=auxEmployee;
    }
    else
    {
        if(strcmp(list[i].lastName,list[x].lastName)==0 &&sort==1)
        {
            if(list[i].sector>list[x].sector)
            {
                auxEmployee=list[i];
                list[i]=list[x];
                list[x]=auxEmployee;
            }
        }
    }
}
void descending(sEmployee list[],int i, int x, int sort)
{
    sEmployee auxEmployee;
    if(strcmp(list[i].lastName,list[x].lastName)<0 &&sort==2)
    {
        auxEmployee=list[i];
        list[i]=list[x];
        list[x]=auxEmployee;
    }
    else
    {
        if(strcmp(list[i].lastName,list[x].lastName)==0 &&sort==2)
        {
            if(list[i].sector<list[x].sector)
            {
                auxEmployee=list[i];
                list[i]=list[x];
                list[x]=auxEmployee;
            }
        }
    }
}
void avrSalary(sEmployee list[],int tam)
{
    float promedy;
    float totalSalary=0;
    int employeesCounter=0;
    int employeesSupCounter=0;

    for(int i=0;i<tam;i++)
    {
        if(list[i].isEmpty==0)
        {
            totalSalary+=list[i].salary;
            employeesCounter++;
        }
    }
    promedy=totalSalary/employeesCounter;

    for(int i=0;i<tam;i++)
    {
        if(list[i].salary>promedy&&list[i].isEmpty==0)
        {
            employeesSupCounter++;
        }
    }
    printf("El promedio de los salarios es: %.2f \n\n",promedy);
    printf("%d empleado/s superan el promedio\n",employeesSupCounter);
}


