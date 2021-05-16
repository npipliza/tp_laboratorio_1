#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

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
 * @brief recorre el array y pone en 0 (vacio)
 * para inicializar la estructura, evitando traer 'basura' y poder obtener las
 * posiciones libres reales.
 *
 * @param listaEmpleados
 * @param tamaño del array
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
 * @fn int informeSalarios(eEmpleados[], int)
 * @brief recorre el array, recolecta las salarios para sumar los totales y sacar promedio
 * de todos. luego innforma cuantos empleados superan el sueldo promedio.
 *
 * @param listaEmpleados
 * @param TAM
 * @return
 */
int informeSalarios(eEmpleados listaEmpleados[], int TAM);

/************************************************************************************/
/**
 * @fn int obtenerUltimoIDdeEmpleado(void)
 * @brief funcion que permite guardar el ultimo ID para poder mostrar los datos del empleado
 * que se esta ingresando
 *
 * @return
 */
int  obtenerUltimoIDdeEmpleado(void);

/************************************************************************************/
/**
 * @fn int obtenerIndexLibre(eEmpleados[], int)
 * @brief se recorre el array en busca de un lugar disponible
 *
 * @param listaEmpleados
 * @param TAM
 * @return retorna 0 si esta libre, -1 si esta ocupado
 */
int  obtenerIndexLibre(eEmpleados listaEmpleados[], int TAM);

/************************************************************************************/
/**
 * @fn int buscarEmpleadoPorID(eEmpleados[], int, int)
 * @brief
 *
 * @param listaEmpleados
 * @param TAM
 * @param ID
 * @return
 */
int  buscarEmpleadoPorID(eEmpleados listaEmpleados[], int TAM, int ID);

/************************************************************************************/
/**
 * @fn void mostrarUnEmpleado(eEmpleados)
 * @brief
 *
 * @param empleado
 */
void mostrarUnEmpleado(eEmpleados empleado);
int  mostrarTodosLosEmpleados(eEmpleados listaEmpleados[], int TAM);

/** SORT */
/************************************************************************************/
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ordenaEmpleadosPorApellido(eEmpleados listaEmpleados[], int TAM, int criterio);

/** ABM */
/************************************************************************************/
eEmpleados cargarDatosEmpleado(void);

/************************************************************************************/
/**
 * @fn eEmpleados modificarUnEmpleado(eEmpleados)
 * @brief
 *
 * @param empleado
 * @return
 */
eEmpleados modificarUnEmpleado(eEmpleados empleado);

/************************************************************************************/
/**
 * @fn int altaEmpleado(eEmpleados[], int)
 * @brief
 *
 * @param listaEmpleados
 * @param TAM
 * @return
 */
int altaEmpleado(eEmpleados listaEmpleados[], int TAM);

/************************************************************************************/
/**
 * @fn int bajaEmpleado(eEmpleados[], int)
 * @brief
 *
 * @param listaEmpleados
 * @param TAM
 * @return
 */
int bajaEmpleado(eEmpleados listaEmpleados[], int TAM);

/************************************************************************************/
/**
 * @fn int modificacionEmpleado(eEmpleados[], int)
 * @brief
 *
 * @param listaEmpleados
 * @param TAM
 * @return
 */
int modificacionEmpleado(eEmpleados listaEmpleados[], int TAM);

#endif /* ARRAYEMPLEADOS_H_ */
