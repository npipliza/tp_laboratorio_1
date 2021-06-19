#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

#define MAX_CHARS_CADENAS 30
#define T 2
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int   idEmpleado;
	char  nombre[51];
	char  apellido[51];
	float salario;
	int   sector;
	int   isEmpty;
}eEmpleados;

/************************************************************************************/
/**
 * @fn void InicializarEmpleados(eEmpleados[], int)
 * @brief Si listaEmpleados es != de de nulo y 0, recorre el array y pone en 0 (vacio)
 * para inicializar la estructura, evitando traer 'basura' y poder obtener las
 * posiciones libres reales.
 *
 * @param listaEmpleados
 * @param TAM
 */
void InicializarEmpleados(eEmpleados listaEmpleados[], int TAM);

/************************************************************************************/
/**
 * @fn int obtenerIDdeEmpleado()
 * @brief contador que autoincrementa su valor cada vez q se llama a la funcion desde
 * el menu de altas, otorgando un nuevo ID para el empleado que se ingresará.
 *
 * @return numero de ID asignado.
 */
int  obtenerIDdeEmpleado(void);

/************************************************************************************/
/**
 * @fn int obtenerUltimoIDdeEmpleado(void)
 * @brief
 *
 * @return
 */
int  obtenerUltimoIDdeEmpleado(void);

int  obtenerIndexLibre(eEmpleados listaEmpleados[], int TAM);
int  buscarEmpleadoPorID(eEmpleados listaEmpleados[], int TAM, int ID);
void mostrarUnEmpleado(eEmpleados empleado);
int  mostrarTodosLosEmpleados(eEmpleados listaEmpleados[], int TAM);
//int  mostrarEmpleadosDadosDeBaja(eEmpleados listaEmpleados[], int TAM);

/** SORT */
/************************************************************************************/
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ordenaEmpleadosPorApellido(eEmpleados listaEmpleados[], int TAM, int criterio);

//ABM
/************************************************************************************/
eEmpleados cargarDatosEmpleado(void);
eEmpleados modificarUnEmpleado(eEmpleados empleado);
int altaEmpleado(eEmpleados listaEmpleados[], int TAM);
int bajaEmpleado(eEmpleados listaEmpleados[], int TAM);
int modificacionEmpleado(eEmpleados listaEmpleados[], int TAM);

#endif /* ARRAYEMPLEADOS_H_ */
