#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp1 functions.h"

int main()
{
    setbuf(stdout,NULL);

    int num1;
    int num2;
    int pasoNum1;
    int pasoNum2;
    int pasoResul;

    int calculado;
    int resultados;

    int menuBool;

    num1=0;
    num2=0;
    pasoNum1=0;
    pasoNum2=0;
    pasoResul=0;

    do
    {
        switch(mostrarMenu(num1,num2,resultados,calculado))
        {
        case 1:
            num1=ingresarNumero();
            pasoNum1=1;
            break;
        case 2:
            num2=ingresarNumero();
            pasoNum2=1;
            break;
        case 3:
            calculado=calcular(pasoNum1,pasoNum2);
            if(calculado>0)
            {
               pasoResul=1;
            }
            break;
        case 4:
            resultados=mostrarResultados(pasoNum1,pasoNum2,pasoResul);
            break;
        case 5:
            menuBool=salir();
            break;
        default:
            printf("ERROR. Debe de elegir una opcion del 1 al 5.\n");
            menuBool=salir();
            break;
        }
    }while(menuBool>0);
}

