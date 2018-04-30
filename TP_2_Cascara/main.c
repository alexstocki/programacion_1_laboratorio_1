#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 20


int main()
{
    char seguir='s';
    ePersona persona[CANT];

    do
    {
        system("cls");
        switch(menu())
        {
            case 1:
                {
                   system("cls");
                   fflush(stdin);
                   alta(persona,CANT);
                   system("pause");
                   break;
                }
            case 2:
                {
                    system("cls");
                    fflush(stdin);
                    baja(persona,CANT);
                    system("pause");
                    break;
                }
            case 3:
                {
                    system("cls");
                    fflush(stdin);
                    modificar(persona,CANT);
                    system("pause");
                    break;
                }
            case 4:
                {
                    system("cls");
                    fflush(stdin);
                    listar(persona,CANT);
                    system("pause");
                    break;
                }
            case 5:
                {
                    grafico(persona,CANT);
                    system("pause");
                    break;
                }
            case 6:
                {
                    seguir='n';
                    break;
                }
        }
    }while(seguir!='n');

    return 0;
}
