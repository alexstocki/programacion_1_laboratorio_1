#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int menu()
{
    int opcion;

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Modificar datos de persona\n");
        printf("4- Imprimir lista ordenada por  nombre\n");
        printf("5- Imprimir grafico de edades\n");
        printf("6- Salir\n");

        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        while(opcion<1 && opcion>6)
        {
            printf("\nError. Ingrese una opcion valida: ");
            fflush(stdin);
            scanf("%d",&opcion);
        }

    return opcion;
}

int menuModificar()
{
    int opcion;

        printf("\n1- Modificar nombre\n");
        printf("2- Modificar edad\n");
        printf("3- Modificar DNI\n");
        printf("4- Salir\n");

        printf("Opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        while(opcion<1 && opcion>4)
        {
            fflush(stdin);
            printf("\nError. Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }
        return opcion;
}

void inicioEstado(ePersona variable[],int CANT)
{
    int i;

    for(i=0;i<CANT;i++)
    {
        variable[i].estado=0;
    }
}

int buscarEspacio(ePersona variable[],int CANT)
{
    int i;
    int indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void alta(ePersona variable[],int CANT)
{
    int indice;
    int esta;
    char codigo[9];

    indice=buscarEspacio(variable,CANT);

    if(indice==-1)
    {
        printf("\nNo hay mas espacios dispobiles.\n");
        printf("=========================================\n");
    }
    else
    {
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%s",codigo);
        esta=buscarPorDni(variable,codigo,CANT);
        if(esta!=-1)
        {
            printf("\nYa se ingreso una persona con ese DNI\n");
        }
        else
        {
            fflush(stdin);
            printf("\nNombre: ");
            scanf("%[^\n]",variable[indice].nombre);
            fflush(stdin);
            printf("\nEdad: ");
            scanf("%d",&variable[indice].edad);
            fflush(stdin);
            variable[indice].estado=1;
            strcpy(variable[indice].dni,codigo);
        }
    }
}

void mostrarPersona(ePersona variable)
{
    printf("%s\t\t%s\t\t%d\n",variable.nombre,variable.dni,variable.edad);
}

void modificar(ePersona variable[],int CANT)
{
    int seguir=0;
    char auxiliarDNI[9];
    int esta;

    printf("\nIngrese DNI: ");
    fflush(stdin);
    scanf("%s",auxiliarDNI);

    esta=buscarPorDni(variable,auxiliarDNI,CANT);

    if(esta==-1)
    {
        printf("\nNo hay niguna persona con ese DNI");
    }
    else
    {
        printf("---MENU MODIFICAR---\n\n");
        printf("NOMBRE\t\tDNI\t\tEDAD\n\n");
        mostrarPersona(variable[esta]);
        do{
        switch(menuModificar())
        {
        case 1:
            {
                printf("\nNombre: ");
                fflush(stdin);
                scanf("%[^\n]",variable[esta].nombre);
                break;
            }
        case 2:
            {
                printf("\nEdad: ");
                fflush(stdin);
                scanf("%d",&variable[esta].edad);
                break;
            }
        case 3:
            {
                printf("\nDNI: ");
                fflush(stdin);
                scanf("%s",variable[esta].dni);
                break;
            }
        case 4:
            {
                seguir=1;
                break;
            }
        }
    }while(seguir!=1);
}
}

int buscarPorDni(ePersona variable[],char codigo[], int CANT)
{
    int i,indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && strcmp(variable[i].dni,codigo)==0)
        {
            indice=i;
        }
    }
    return indice;
}

void baja(ePersona variable[],int CANT)
{
    char auxiliarDni[9];
    int esta, bandera=0;
    char baja;
    fflush(stdin);
    printf("\nIngrese DNI: ");
    fflush(stdin);
    scanf("%s",auxiliarDni);
    fflush(stdin);

    esta=buscarPorDni(variable,auxiliarDni,CANT);

    if(bandera==-1)
    {
        printf("\nError.Persona no encontrada.\n");
        printf("=========================================\n");
    }
    else
    {
        system("cls");
        printf("---MENU BAJA---\n\n");
        printf("NOMBRE\t\tDNI\t\tEDAD\n\n");
        mostrarPersona(variable[esta]);
        fflush(stdin);
        printf("\n\nDesea eliminar a esta persona?[s|n]: ");
        scanf("%c",&baja);
        while(baja!='s' && baja!='n')
        {
            fflush(stdin);
            printf("\nError. Ingrese una opcion valida [s|n]: ");
            scanf("%c",&baja);
        }
        if(baja=='s')
        {
            variable[esta].estado=0;
            printf("\nBAJA EXITOSA\n");
        }
        else
        {
            printf("\nBAJA CANCELADA\n");
        }
    }
}

void ordenar(ePersona variable[],int CANT)
{
    int i,j;
    ePersona auxiliarPersona;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(strcmp(variable[i].nombre,variable[j].nombre)>0)
            {
                auxiliarPersona=variable[i];
                variable[i]=variable[j];
                variable[j]=auxiliarPersona;
            }
        }
    }
}

void listar(ePersona variable[],int CANT)
{
    int i;
    ordenar(variable,CANT);

    printf("NOMBRE\t\tEDAD\tDNI\n\n");

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            mostrarPersona(variable[i]);
        }

        /*if(variable[i].estado==1)
        {
            printf("%s\t%d\t%s\n",variable[i].nombre,variable[i].edad,variable[i].dni);
        }*/
    }
}


void grafico(ePersona variable[], int CANT) {
    int flag=0;
    int i;
    int menor18=0;
    int entre19y35=0;
    int mayor35=0;
    int conteoTotal;
    for(i=0; i<CANT; i++)
    {
        if(variable[i].estado==1)
        {
            if(variable[i].edad<18) {
                menor18++;
            }
            else {
                if(variable[i].edad>=18 && variable[i].edad<=35) {
                    entre19y35++;
                }
                if(variable[i].edad>=36) {
                    mayor35++;
                }
            }
        }
    }

    conteoTotal=menor18+entre19y35+mayor35;
    for(i=conteoTotal; i>0; i--) {
        if(menor18 == i) {
            printf("*");
            menor18--;
        }

        printf("\t");

        if(entre19y35 == i)
        {
            printf("*");
            entre19y35--;
        }
        printf("\t");

        if(mayor35==i)
        {
            printf("*");
            mayor35 --;
        }

        printf("\n");
        flag=1;
    }

    if(!flag) {

        printf("ERROR: no existen personas para intentar mostrar el grafico.\n");
    }
    printf("-----------------\n");
    printf("<=18\t19-35\t>=35\n");
    system("pause");
    system("cls");

}

