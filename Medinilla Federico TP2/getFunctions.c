#include <string.h>
#include <ctype.h>
#include<stdio.h>
#include "getFunctions.h"

int checkInt(char inputMsg[],char errorMsg[])
{
    int intInput;

    printf("%s",inputMsg);
    scanf("%d",&intInput);

    while(intInput<0||intInput>99)
    {
        printf("%s",errorMsg);
        scanf("%d",&intInput);
    }

    return intInput;
}
float checkFloat(char inputMsg[],char errorMsg[])
{
    float fInput;

    printf("%s",inputMsg);
    scanf("%f",&fInput);

    while(fInput<0||fInput>999999)
    {
        printf("%s",errorMsg);
        scanf("%f",&fInput);
    }

    return fInput;
}
void checkString(char string[], char inputMsg[],char errorMsg[], int tam)
{
    char aux[51];
    int len;

    printf("%s",inputMsg);
    fflush(stdin);
    scanf("%[^\n]",aux);
    strlwr(aux);
    len=strlen(aux);

    aux[0]=toupper(aux[0]);

    while(strlen(aux)>tam-1)
    {
        printf("%s",errorMsg);
        fflush(stdin);
        scanf("%[^\n]",aux);
        strlwr(aux);
        len=strlen(aux);

        aux[0]=toupper(aux[0]);

        for(int i=0;i<len;i++)
        {
            if(isspace(aux[i]))
            {
                aux[i+1]=toupper(aux[i+1]);
            }
        }
    }

    for(int i=0;i<tam;i++)
    {
        if(isspace(aux[i]))
        {
            aux[i+1]=toupper(aux[i+1]);
        }
    }
    strcpy(string, aux);
}
int menuOption(char inputMsg[])
{
    int choice;

    printf("%s",inputMsg);
    scanf("%d",&choice);

    return choice;
}

