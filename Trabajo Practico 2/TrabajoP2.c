/* ============================================================================
    Trabajo Practico : 2
    Division         : 1ro C
    Alumna           : Pipliza Nadia
   ============================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmpleados.h"
#include "utn.h"
#define  TamE 1000 // 1000 empleados
int mostrarOpciones;

int main(void)
{
	int mostrarOpciones;
	int criterioDeOrdenamiento;
	int indexUltimo;
	int opciones;

	setbuf(stdout, NULL);

	//creo e inicializo el array
	eEmpleados empleado[TamE];
	InicializarEmpleados(empleado, TamE);

	printf("INICIO PROGRAMA ADMINISTRADOR DE NÓMINA DE EMPLEADOS... \n");
	do//creo bucle del menu
	{
		mostrarOpciones = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
									  "1. ALTA Empleado.\n"
									  "2. BAJA Empleado.\n"
									  "3. MODIFICAR Empleado.\n"
				   	   	   	   	   	  "4. MOSTRAR TOTAL Empleados.\n"
			       	   	   	   	   	  "5. MOSTRAR Empleados ordenados por APELLIDO.\n"
									  "6. INFORME salarios.\n"
				   	   	   	   	   	  "0. SALIR\n"
				   	   	   	   	   	  "Elija una opción: ","\nError. Ingrese número de opción: ");

		switch(mostrarOpciones)
		{
			//ALTA EMPLEADOS
			case 1:

				indexUltimo = altaEmpleado(empleado, TamE);
				if(indexUltimo != -1)
				{
					printf("\n * EMPLEADO DADO DE ALTA EXITOSAMENTE\n");
					printf("\nID \t NOMBRE\t\t APELLIDO\t SUELDO\t \tSECTOR\n");
					mostrarUnEmpleado(empleado[indexUltimo]);
				}
				else
				{
					printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS EMPLEADOS\n");
				}
				system("pause");
			break;

			//BAJA EMPLEADOS
			case 2:
				if(bajaEmpleado(empleado, TamE) == 1)
				{
					printf("\n * BAJA DE EMPLEADO EXITOSA\n");
					mostrarTodosLosEmpleados(empleado, TamE);
				}
				else
				{
					printf("\n * BAJA DE EMPLEADO CANCELADA\n");
				}
				system("pause");
			break;

			//MODIFICACION EMPLEADOS
			case 3:
				if(modificacionEmpleado(empleado, TamE) == 1)
				{
					printf("\n * MODIFICACION DE EMPLEADO EXITOSA\n");
					mostrarTodosLosEmpleados(empleado, TamE);
				}
				else
				{
					printf("\n * MODIFICACION DE EMPLEADO CANCELADA\n");
				}
				system("pause");
			break;

			//MOSTRAR TOTAL EMPLEADOS
			case 4:
				mostrarTodosLosEmpleados(empleado, TamE);
				system("pause");
			break;

			//MOSTRAR EMPLEADOS ORDENADOS POR APELLIDO
			case 5://1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
				printf("\n * SELECCIONE: \n 1: A-Z \n 2: Z-A \n");
				scanf("%d", &opciones);

				criterioDeOrdenamiento = opciones;

				if(criterioDeOrdenamiento != 0)
				{
					ordenaEmpleadosPorApellido(empleado, TamE, criterioDeOrdenamiento);
					mostrarTodosLosEmpleados(empleado, TamE);
				}
				else
				{
					printf("\n * CANCELADO\n");
				}
				system("pause");
			break;

			//INFORMAR TOTAL Y PROMEDIO DE SALARIOS / CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO.
			case 6:
				//int retorno;

				if(criterioDeOrdenamiento != 0)
				{
					informeSalarios(empleado, TamE);
				}
				else
				{
					printf("\n * CANCELADO\n");
				}
				system("pause");
			break;
		}//fin switch mostrarOpciones
	}while(mostrarOpciones != 0);

	printf("\n...PROGRAMA FINALIZADO.");

	return EXIT_SUCCESS;
}//fin funcion main
