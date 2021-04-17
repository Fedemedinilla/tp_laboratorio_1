#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp1 functions.h"

int mostrarMenu(int n1, int n2, int resultados, int calculado)
{
    int opcion;

    int resultadoSuma;
    int resultadoResta;
    int resultadoMulti;
    double resultadoDivi;
    long long resultadoFact1;
    long long resultadoFact2;

    printf("\n\n      *** BIENVENIDO ***\n\n");
    printf("1) Ingrese el primer numero: %d\n",n1);
    printf("2) Ingrese el segundo numero: %d\n\n",n2);
    printf("3) Calcular estas operaciones: \n");
    printf("  a- La suma (%d + %d)\n",n1,n2);
    printf("  b- La resta (%d - %d)\n",n1,n2);
    printf("  c- La multiplicacion (%d * %d)\n",n1,n2);
    printf("  d- La division (%d / %d)\n",n1,n2);
    printf("  e- El factorial de %d y de %d\n\n",n1,n2);
    printf("4) Mostrar los resultados: \n");
    if(calculado==1)
    {
        resultadoSuma=sumar(n1,n2);
        resultadoResta=restar(n1,n2);
        resultadoMulti=multiplicar(n1,n2);
        resultadoDivi=dividir(n1,n2);
        resultadoFact1=factorial(n1);
        resultadoFact2=factorial(n2);

        if(resultados==1)
        {
            printf("  a- La suma (%d + %d) = %d\n",n1,n2,resultadoSuma);
            printf("  b- La resta (%d - %d) = %d\n",n1,n2,resultadoResta);
            printf("  c- La multiplicacion (%d * %d) = %d\n",n1,n2,resultadoMulti);
            if(resultadoDivi<0.1)
            {
                printf("  d- La division (%d / %d) NO se puede realizar, porque no se puede dividir por 0.\n",n1,n2);
            }
            else
            {
                printf("  d- La division (%d / %d) = %.2lf\n",n1,n2, resultadoDivi);
            }
            printf("  e- El factorial de %d es %lld y de %d es %lld\n\n",n1,resultadoFact1,n2,resultadoFact2);
        }
        else
        {
            printf("  a- La suma (%d + %d) = \n",n1,n2);
            printf("  b- La resta (%d - %d) = \n",n1,n2);
            printf("  c- La multiplicacion (%d * %d) = \n",n1,n2);
            printf("  d- La division (%d / %d) = \n",n1,n2);
            printf("  e- El factorial de %d y de %d\n\n",n1,n2);
        }
    }
    else
    {
        printf("  a- La suma (%d + %d) = \n",n1,n2);
        printf("  b- La resta (%d - %d) = \n",n1,n2);
        printf("  c- La multiplicacion (%d * %d) = \n",n1,n2);
        printf("  d- La division (%d / %d) = \n",n1,n2);
        printf("  e- El factorial de %d y de %d\n\n",n1,n2);
    }
    printf("5) Salir del programa.\n\n");


    printf("\nElija una opcion: ");
    scanf("%d",&opcion);
    system("cls");
    return opcion;

}
int ingresarNumero()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    system("cls");

    printf("*El numero ingresado fue: %d",numero);

    return numero;
}
int sumar(int n1, int n2)
{
    return n1+n2;
}
int restar(int n1, int n2)
{
    return n1-n2;
}
int multiplicar(int n1, int n2)
{
    return n1*n2;
}
double dividir(int n1, int n2)
{
    double error=1;
    error=(double) n1/n2;
    if(n2==0)
    {
        error=0;
        printf("\n***  No se puede dividir por 0 ***\n\n");
    }
    return error;
}
long long factorial(int n1)
{
    int num;
    long long factorial;

    factorial=1;
    for(num=1;num<=n1;num++)
    {
        factorial=factorial*num;
    }
    return factorial;
}
int calcular(int paso1, int paso2)
{
    int calculado=0;
    if(paso1>0&&paso2>0)
    {
        printf("Operaciones realizadas con exito!");
        calculado=1;
    }
    else
    {
        printf("Tiene que ingresar almenos 2 numeros!");
    }
    return calculado;
}
int mostrarResultados(int paso1, int paso2, int paso3)
{
    int resultados=0;
    if(paso1>0&&paso2>0&&paso3>0)
    {
        printf("Resultados mostrados. Que los disfrute!");
        resultados=1;
    }
    else
    {
        printf("Debe completar los 3 puntos anteriores.");
    }
    return resultados;
}
int salir()
{
    char sale;
    int retorno;
    retorno=1;

    printf("Seguro que desea salir?(Y/N) ");
    fflush(stdin);
    scanf("%c",&sale);
    sale=tolower(sale);
    while(sale!='y'&&sale!='n')
    {
        printf("Error. Ingrese Y o N ");
        fflush(stdin);
        scanf("%c",&sale);
        sale=tolower(sale);
    }
    system("cls");
    if(sale=='y')
    {
        printf("Vuelva pronto!");
        retorno=0;
    }
    return retorno;
}
