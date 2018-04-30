#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    char dni[9];

}ePersona;

int menu();
int menuModificar();
void inicioEstado(ePersona variable[],int CANT);
int buscarEspacio(ePersona variable[],int CANT);
int buscarPorDni(ePersona lista[],char codigo[],int CANT);
void alta(ePersona variable[],int CANT);
void mostrarPersona(ePersona variable);
void modificar(ePersona variable[],int CANT);
void baja(ePersona variable[],int CANT);
void ordenar(ePersona variable[],int CANT);
void listar(ePersona variable[],int CANT);
void grafico(ePersona variable[],int CANT);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */



#endif // FUNCIONES_H_INCLUDED
