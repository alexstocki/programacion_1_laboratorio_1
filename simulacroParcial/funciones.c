#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void inicioEstados(eProducto variable[],int CANT)
{
    int i;

    for(i=0;i<CANT;i++)
    {
        variable[i].estado=0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("-----MENU PRODUCTOS-----\n\n");
    printf("1) Nuevo producto\n");
    printf("2) Modificar producto\n");
    printf("3) Borrar producto\n");
    printf("4) Ordenar productos\n");
    printf("5) Listar productos\n");
    printf("6) Listar proveedores con sus productos\n");
    printf("7) Listar productos con sus proveedores\n");
    printf("8) Salir\n");
    printf("Opcion: \n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int menuModificar()
{
    int opcion;

    //system("cls");
    printf("-----MENU MODIFICAR-----\n\n");
    printf("1) Modificar precio\n");
    printf("2) Modificar cantidad\n");
    printf("3) Modificar descripcion\n");
    printf("4) Modificar proveedor\n");
    printf("5) Salir\n");
    printf("Opcion: \n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void mostrarProducto(eProducto variable)
{
    printf("\n%d\t%s\t\t%.2f\t%d\n",variable.codigo,variable.descripcion,variable.importe,variable.cantidad);
}

void alta(eProducto variable[],int CANT)
{
    eProducto nuevoProducto;
    int esta;
    int indice;
    int codigo;

    system("cls");
    printf("---Alta producto---\n\n");

    indice=buscarEspacio(variable,CANT);

        if(indice==-1)
        {
            printf("\nNo hay mas espacio para cargar productos\n");
        }
        else
        {
            fflush(stdin);
            printf("Ingrese codigo: ");
            scanf("%d",&codigo);

            esta=buscarProducto(variable,CANT,codigo);

            if(esta!=-1)
            {
                printf("El codigo %d ya se ha ingresado\n",codigo);
                mostrarProducto(variable[esta]);
            }
            else
            {
                nuevoProducto.estado = 1;
                nuevoProducto.codigo = codigo;
                fflush(stdin);

                printf("\nDescripcion: ");
                scanf("%[^\n]",nuevoProducto.descripcion);
                while(strlen(nuevoProducto.descripcion)>50)
                {
                fflush(stdin);
                printf("\nError. Ingrese una descripcion mas breve: ");
                scanf("%[^\n]",nuevoProducto.descripcion);
                }

                fflush(stdin);
                printf("\nImporte: ");
                scanf("%f",&nuevoProducto.importe);
                while(nuevoProducto.importe<1 || nuevoProducto.importe>1000)
                {
                fflush(stdin);
                printf("\nError. Ingrese un importe valido: ");
                scanf("%f",&nuevoProducto.importe);
                }

                fflush(stdin);
                printf("\nCantidad: ");
                scanf("%d",&nuevoProducto.cantidad);
                while(nuevoProducto.cantidad<1)
                {
                fflush(stdin);
                printf("\nError. Ingrese una cantidad valida: ");
                scanf("%d",&nuevoProducto.cantidad);
                }

                fflush(stdin);
                printf("\ID proveedor: ");
                scanf("%d",&nuevoProducto.idProveedor);

                variable[indice]=nuevoProducto;
            }
        }
}
int buscarEspacio(eProducto variable[],int CANT)
{
    int indice=-1;
    int i;

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

int buscarProducto(eProducto variable[],int CANT,int id)
{
    int indice=-1;
    int i;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].codigo==id && variable[i].estado==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void modificar(eProducto variable[],int CANT)
{
    int codigo, esta, salir=0;

    fflush(stdin);
    printf("\nIngrese el codigo del producto: ");
    scanf("%d",&codigo);

    esta=buscarProducto(variable,CANT,codigo);

    if(esta!=-1)
    {
        do{
            system("cls");
            mostrarProducto(variable[esta]);
            switch(menuModificar())
            {
                case 1:
                {
                    fflush(stdin);
                    printf("\nNuevo precio: ");
                    scanf("%f",&variable[esta].importe);
                    break;
                }
                case 2:
                {
                    fflush(stdin);
                    printf("\nNueva cantidad: ");
                    scanf("%d",&variable[esta].cantidad);
                    break;
                }
                case 3:
                {
                    fflush(stdin);
                    printf("\nNueva descripcion: ");
                    scanf("%[^\n]",variable[esta].descripcion);
                    break;
                }
                case 4:
                {
                    fflush(stdin);
                    printf("\nNueva ID proveedor: ");
                    scanf("%d",&variable[esta].idProveedor);
                    break;
                }
                case 5:
                {
                    salir=1;
                    break;
                }
                default:
                {
                    printf("Error. Ingrese opcion correcta\n");
                    break;
                }
            }
        }while(salir!=1);
    }
    else
    {
        printf("\nError. No se encontro el producto\n");
    }
}

void baja(eProducto variable[],int CANT)
{
    int codigo,esta;
    char baja;

    fflush(stdin);
    printf("\nIngrese el codigo del producto a borrar: ");
    scanf("%d",&codigo);

    esta=buscarProducto(variable,CANT,codigo);

    if(esta==-1)
    {
        printf("No se encontro al empleado\n");
    }
    else
    {
        do{
            printf("\nCodigo\t\tImporte\tCantidad\tDescripcion\n");
            mostrarProducto(variable[esta]);
            fflush(stdin);
            printf("\nDesea confirmar la baja? [s|n]: ");
            scanf("%c",&baja);
            baja=tolower(baja);
           }while(baja!='s' && baja!='n');

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

void ordenar(eProducto variable[],int CANT)
{
    int i, j;
    eProducto auxiliarVariable;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(variable[i].importe<variable[i].importe)
            {
                auxiliarVariable=variable[i];
                variable[i]=variable[j];
                variable[j]=auxiliarVariable;
            }
            if(variable[i].importe==variable[j].importe)
            {
                if(strcmp(variable[i].descripcion,variable[j].descripcion)>0)
                {
                    auxiliarVariable=variable[i];
                    variable[i]=variable[j];
                    variable[j]=auxiliarVariable;
                }
            }
        }
    }
}

void listar(eProducto variable[],int CANT)
{
    int i,bandera=0;
    system("cls");

    ordenar(variable,CANT);

    printf("\nCodigo\t\tImporte\tCantidad\tDescripcion\n");

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            printf("%d\t\t%.2f\t%d\t\t\t%s\n",variable[i].codigo,variable[i].importe,variable[i].cantidad,variable[i].descripcion);
            bandera=1;
        }
    }
    if(bandera==0)
    {
        printf("\nNo hay productos para listar\n");
    }
}
