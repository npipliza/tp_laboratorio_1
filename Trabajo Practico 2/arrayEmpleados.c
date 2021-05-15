#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmpleados.h"
#include "utn.h"

//ID AUTOINCREMENTAL
int idIncremental = 999;

void InicializarEmpleados(eEmpleados listaEmpleados[], int TAM)
{
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaEmpleados != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//SET ESTADO DE "LIBRE"
			listaEmpleados[i].isEmpty = LIBRE;
		}
	}
}

/************************************************************************************/
int obtenerIDdeEmpleado()
{
	return idIncremental+=1;
}

/************************************************************************************/
int obtenerUltimoIDdeEmpleado()
{
	return idIncremental;
}

/************************************************************************************/
int obtenerIndexLibre(eEmpleados listaEmpleados[], int TAM)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaEmpleados != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listaEmpleados[i].isEmpty == LIBRE)
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int altaEmpleado(eEmpleados listaEmpleados[], int TAM)
{
	int rtn = 0;
	eEmpleados auxEmpleado;
	//BUSCO ESPACIO EN ARRAY
	int index = obtenerIndexLibre(listaEmpleados, TAM);

	if(index != -1)// == -1 array lleno, != -1 hay lugar.
	{
		auxEmpleado           = cargarDatosEmpleado();
		listaEmpleados[index] = auxEmpleado;
		rtn                   = index;//case1//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

/************************************************************************************/
int buscarEmpleadoPorID(eEmpleados listaEmpleados[], int TAM, int ID)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaEmpleados != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (listaEmpleados[i].idEmpleado == ID && listaEmpleados[i].isEmpty == OCUPADO)
			{//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
void mostrarUnEmpleado(eEmpleados empleado)
{
	//int idActual = obtenerUltimoIDdeEmpleado();
	if(empleado.isEmpty == OCUPADO)
	{
		printf("\nID empleado: %d | "
			   "Nombre: %s | "
			   "Apellido: %s | "
			   "Salario: %.2f | "
			   "Sector: %d \n ", empleado.idEmpleado,
			   	   	   	   	   	 empleado.nombre,
							     empleado.apellido,
			   	   	   	   	     empleado.salario,
								 empleado.sector);
	}
}

/************************************************************************************/
int mostrarTodosLosEmpleados(eEmpleados listaEmpleados[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\t -----> LISTA DE EMPLEADOS <----- \n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaEmpleados != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//PREGUNTO POR SU ESTADO "OCUPADO"
			if (listaEmpleados[i].isEmpty == OCUPADO)
			{//MUESTRO UN SOLO EMPLEADO
				mostrarUnEmpleado(listaEmpleados[i]);
				//CONTADOR DE EMPLEADO
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO EMPLEADOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if(cantidad > 0)
	{
		rtn = 1;
	}
	return rtn;
}

/************************************************************************************/
eEmpleados cargarDatosEmpleado(void)
{
	eEmpleados auxiliar;

	auxiliar.idEmpleado = obtenerIDdeEmpleado();

	utn_getPalabra(auxiliar.nombre ,sizeof(auxiliar.nombre), "\nIngrese el nombre: \n", "\nERROR: Ingrese sólo letras. \n", 10);
	utn_getPalabra(auxiliar.apellido ,sizeof(auxiliar.apellido ), "\nIngrese el apellido: \n", "\nERROR: Ingrese sólo letras. \n", 10);
	utn_getNumeroFlotante(&auxiliar.salario,"\nIngrese salario: \n","\nERROR: Ingrese salario válido.\n",100,999999,10);
	utn_getNumero(&auxiliar.sector,"\nIngrese sector: \n","\nERROR: Ingrese sector válido.\n",1,100,10);

    auxiliar.isEmpty = OCUPADO;

	return auxiliar;
}

/************************************************************************************/
eEmpleados modificarUnEmpleado(eEmpleados empleado)
{
	int mostrarOpciones;

	eEmpleados auxiliar = empleado;

	do//creo bucle del menu
	{
		printf("\nINGRESE OPCIÓN A MODIFICAR: ************************************\n"
			   "1. Nombre.\n"
			   "2. Apellido.\n"
			   "3. Salario.\n"
			   "4. Sector.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				utn_getPalabra(auxiliar.nombre ,sizeof(auxiliar.nombre), "\nIngrese el nombre: \n", "\nERROR: Ingrese sólo letras. \n", 10);
			break;

			case 2:
				utn_getPalabra(auxiliar.apellido ,sizeof(auxiliar.apellido ), "\nIngrese el apellido: \n", "\nERROR: Ingrese sólo letras. \n", 10);
			break;

			case 3:
				utn_getNumeroFlotante(&auxiliar.salario,"\nIngrese salario: \n","\nERROR: Ingrese salario válido.\n",100,999999,10);
			break;

			case 4:
				utn_getNumero(&auxiliar.sector,"\nIngrese sector: \n","\nERROR: Ingrese sector válido.\n",1,100,10);
			break;
		}


	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}

/************************************************************************************/
int modificacionEmpleado(eEmpleados listaEmpleados[], int TAM)
{
	int rtn = 0;
	int idEmpleado;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eEmpleados auxiliar;

	//LISTO TODOS LOS EMPLEADOS
	if(mostrarTodosLosEmpleados(listaEmpleados, TAM) != 0)
	{//BANDERA EN 1 SI HAY EMPLEADOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN EMPLEADOS DADOS DE ALTA.\n");
	}

	//SI HAY EMPLEADOS PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idEmpleado);

		//OBTENGO INDEX DEL ARRAY DE EMPLEADOS A MODIFICAR
		index = buscarEmpleadoPorID(listaEmpleados, TAM, idEmpleado);

			//BUSCO INDEX POR ID EN ARRAY
			if(index == -1)
			{
				printf("NO EXISTE ID.\n");

			printf("¿INGRESAR OTRO ID? \n SI: 1\n NO: 2\n");
			scanf("%d", &opcion);

				if(opcion == 2)
				{
					return rtn;
				}
			}
		}while(opcion == 1);



		if(index != -1)
		{
			//LLAMO A FUNCION QUE MODIFICA EMPLEADOS
		auxiliar = modificarUnEmpleado(listaEmpleados[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DEL EMPLEADO? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listaEmpleados[index] = auxiliar;
				rtn = 1;//1 modificó ok
			}
			if(opcion1 == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int bajaEmpleado(eEmpleados listaEmpleados[], int TAM)
{
	int rtn = 0;
	int idEmpleado;
	int index;
	int bandera = 0;
	int opcion;
	int opcion1;

	//LISTO TODOS LOS EMPLEADOS
	if(mostrarTodosLosEmpleados(listaEmpleados, TAM) != 0)
	{//BANDERA EN 1 SI HAY EMPLEADOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXITEN EMPLEADOS DADOS DE ALTA.\n");
	}
	//SI HAY EMPLEADOS PARA DAR DE BAJA
	if(bandera == 1)
	{//PIDO ID A DAR DE BAJA
		printf("\n***** OPCIÓN BAJA ***** \n");
		do
		{
			opcion1 = 0;
			printf("ingrese el ID.\n");
			scanf("%d", &idEmpleado);

			//OBTENGO INDEX DEL ARRAY DE EMPLEADOS A DAR DE BAJA
			index = buscarEmpleadoPorID(listaEmpleados, TAM, idEmpleado);

			//BUSCO INDEX POR ID EN ARRAY
			if(index == -1)
			{
				printf("NO EXISTE ID.\n");
				printf("¿Ingresar otro ID? \n SI: 1\n NO: 2\n");
				scanf("%d", &opcion1);

				if(opcion1 == 2)
				{
					return rtn;
				}
			}
		}while(opcion1 == 1);

		if(index != -1)
		{
			mostrarUnEmpleado(listaEmpleados[index]);

			printf("\n¿Confirma la baja del empleado? \n  Confirmar: 1\n  Cancelar: 2\n");
			scanf("%d", &opcion);

			if(opcion == 1)
			{
				listaEmpleados[index].isEmpty = BAJA;
				rtn = 1;//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			}
			if(opcion == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int ordenaEmpleadosPorApellido(eEmpleados listaEmpleados[], int TAM, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eEmpleados aux;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listaEmpleados != NULL && TAM > 0)
	{
		switch(criterio)
		{
			case 1:
				for(i = 0; i < TAM - 1; i++)
				{
					for (j = i + 1; j < TAM; j++)
					{//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if(listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO)
						{//CRITERIO DE ORDENAMIENTO
							if(strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido) == 1)
							{//INTERCAMBIO POSICIONES EN ARRAY
								aux               = listaEmpleados[i];
								listaEmpleados[i] = listaEmpleados[j];
								listaEmpleados[j] = aux;
							}
						}
					}
				}
				rtn = 1;
			break;

			case 2:
				for(i = 0; i < TAM - 1; i++)
				{
					for(j = i + 1; j < TAM; j++)
					{//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if(listaEmpleados[i].isEmpty == OCUPADO && listaEmpleados[j].isEmpty == OCUPADO)
						{//CRITERIO DE ORDENAMIENTO
							if(strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido) == -1)
							{//INTERCAMBIO POSICIONES EN ARRAY
								aux = listaEmpleados[i];
								listaEmpleados[i] = listaEmpleados[j];
								listaEmpleados[j] = aux;
							}
						}
					}
				}
				rtn = 1;
			break;

			default:
				//CRITERIO DE ORDENAMIENTO MAL INGRESADO
				rtn = 0;
			break;
		}//fin funcion switch
	}
	return rtn;
}



/************************************************************************************/
void informesSalarios(eEmpleados listaEmpleados[], int len)
{
	int   i;
	float acumuladorS    = 0;
	int   contadorE      = 0;
	int   superaPromedio = 0;
	float promedio;

	if(listaEmpleados != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(listaEmpleados[i].isEmpty == OCUPADO)
			{
				acumuladorS = acumuladorS + listaEmpleados[i].salario;
				contadorE ++;
			}
		}
	}

	promedio = acumuladorS / contadorE;

	printf("PROMEDIO DE SUELDOS: %.2f\n", promedio);
	printf("SUMA TOTAL DE SALARIOS: %.2f\n", acumuladorS);

	for(i = 0; i < len; i++)
	{
		if(listaEmpleados[i].salario > promedio)
		{
			superaPromedio ++;
		}
	}
	printf("Empleados con sueldo por encima del promedio: %d \n", superaPromedio);
}



