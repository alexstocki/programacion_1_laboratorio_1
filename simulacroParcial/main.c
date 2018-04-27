#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define CANT 3

int main()
{
    eProducto producto[CANT];
    inicioEstados(producto,CANT);
    int salir=0;

    do{
        switch(menu())
        {
        case 1:
            {
                fflush(stdin);
                alta(producto,CANT);
                break;
            }
        case 2:
            {
                fflush(stdin);
                modificar(producto,CANT);
                system("pause");
                break;
            }
        case 3:
            {
                fflush(stdin);
                baja(producto,CANT);
                system("pause");
                break;
            }
        case 4:
            {
                fflush(stdin);
                ordenar(producto,CANT);
                system("pause");
                break;
            }
        case 5:
            {
                fflush(stdin);
                listar(producto,CANT);
                system("pause");
                break;
            }
        case 6:
            {
                //listarPoveProd(producto,CANT); //MODIFICAR
                break;
            }
        case 7:
            {
               //listarProdProve(producto,CANT); //MODIFICAR
            }
        case 8:
            {
                salir=1;
                break;
            }
        }

    }while(salir!=1);


    return 0;
}
