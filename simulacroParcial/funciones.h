#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
        int codigo;
        char descripcion[248];
        float importe;
        int cantidad;
        int estado;
        int idProveedor;
}eProducto;

typedef struct{
        int codigo;
        char descripcion[248];
        int estado;
}eProveedor;

void inicioEstados(eProducto variable[],int CANT);
int menu();
int menuModificar();
int buscarEstado(eProducto variable[],int CANT);
int buscarProducto(eProducto variable[],int CANT,int id);
void alta(eProducto variable[],int CANT);
void mostrarProducto(eProducto variable);
//void mostrarProductos();//completar
void modificar(eProducto variable[],int CANT);
void baja(eProducto variable[],int CANT);
void ordenar(eProducto variable[],int CANT);
void listar(eProducto variable[],int CANT);

#endif // FUNCIONES_H_INCLUDED
