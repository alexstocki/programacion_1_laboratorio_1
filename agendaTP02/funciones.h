#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
        char nombre[51];
        char dni[9];
        int edad;
        int estado;
}ePersona;

int suma (int, int);
int resta (int, int);
int multiplicacion (int, int);
float division (int, int);
long int factorial (int);

int menu();
int menuModificar();
void inicioEstados(ePersona variable[],int CANT);
int buscarEspacio(ePersona variable[],int CANT);
int buscarDni(ePersona variable[],char codigo[],int CANT);
char tomarDni();
void mostrarPersona(ePersona variable);
void ordenar(ePersona variable[],int CANT);
void alta(ePersona variable[],int CANT);
void baja(ePersona variable[],int CANT);
void modificar(ePersona variable[],int CANT);
void listar(ePersona variable[],int CANT);
void grafico(ePersona variable[],int CANT);




#endif // FUNCIONES_H_INCLUDED

