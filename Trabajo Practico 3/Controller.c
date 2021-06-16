#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"r");

        if(pFile != NULL)
        {
            retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
            fclose(pFile);
        }
    }//fin if NULL
	controller_saveAsBinary("data.bin", pArrayListEmployee);
	return retorno;
}//fin funcion controller_loadFromText

/* *************************************************************************************************************** */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno = 0;
	int liberar;

	if(pArrayListEmployee != NULL)
	{
		get_ValidarInt(&liberar,"\nAl generar la carga del listado en modo BINARIO \nse borrarán los datos anteriores.\nIngresar: \n1- Continuar. \n2- Cancelar.","ERROR.Ingresar números:","\nError, las opciones del menú son 1 ó 2. \nIngresar: \n1- Continuar. \n2- Cancelar.",1,2);
		pFile = fopen(path,"rb");
		do
		{
			if(pFile != NULL && liberar == 1)
			{
				retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
				fclose(pFile);
			}

			if(pFile != NULL && liberar == 2)
			{
				retorno = 0;
			   printf("\nCarga cancelada.\n");
			}
		}while(liberar != 1 && liberar != 2);
	}//fin if NULL
	return retorno;
}//fin funcion controller_loadFromBinary

/* *************************************************************************************************************** */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int indiceEmpleadoAlta;
	int retorno = 0;

	indiceEmpleadoAlta = employee_cargarEmpleado(pArrayListEmployee);

	if(indiceEmpleadoAlta != 0)
	{
		ll_get(pArrayListEmployee,indiceEmpleadoAlta);

		printf("\n- ID GENERADO: %d\n", indiceEmpleadoAlta);
		retorno = 1;
	}
	return retorno;
}//fin funcion controller_addEmployee

/* *************************************************************************************************************** */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int opcion;
    int indiceEmpleadoModificar;
    int retorno = 0;

    employee_modificarDatos(pArrayListEmployee,"Ingrese ID a modificar: ","ERROR. Ingrese ID a modificar: ","Numero fuera del rango existente. Ingrese ID a modificar: ", &indiceEmpleadoModificar);

    do{
    	printf("\n ***** OPCIÓN MODIFICAR ***** \n");
        printf("\n1.Nombre \n2.Horas trabajadas \n3.Sueldo \n4.Salir\n");
        get_ValidarInt(&opcion,"\nIngrese opción: ","Error.Debe ingresar un número:","\nERROR, el menú va del 1 a 4:",1,4);

        if(indiceEmpleadoModificar != -1)
        {
            empleadoAux = ll_get(pArrayListEmployee,indiceEmpleadoModificar);

            if(employee_modificaEmpleado(empleadoAux,opcion) )
            {
                retorno = 1;
            }
        }//fin if indiceEmpleadoModificar
    }while(opcion != 4);

    printf("\n- - - - - CAMBIOS REALIZADOS - - - - -\n");
    employee_mostrarUnEmpleado(empleadoAux);

    return retorno;
}//fin funcion controller_editEmployee

/* *************************************************************************************************************** */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indexIdAEliminar;
    int retorno = 0;
    int confirmar;
    Employee* empleadoAux;
    //

    employee_darIDdeBaja(pArrayListEmployee, &indexIdAEliminar);

    if(indexIdAEliminar != -1)
    {
    	empleadoAux = ll_get(pArrayListEmployee,indexIdAEliminar);
         printf("\n\t- - - - - BAJA DEL EMPLEADO - - - - -\n");
         employee_mostrarUnEmpleado(empleadoAux);
        // printf("%d",indexIdAEliminar);
    	 get_ValidarInt(&confirmar,"\nIngrese \n 1- Confirmar. \n 2- Cancelar ","Error.Debe ingresar un número:","\nERROR, el menú va del 1 a 2:",1,2);

    			if(confirmar == 1)
    			{
					ll_remove(pArrayListEmployee,indexIdAEliminar);
					retorno = 1;
    			}
    			if(confirmar == 2)
    			{
    				retorno = 0;
    			}

    }//fin if indexIdAEliminar
    return retorno;
}//fin funcion controller_removeEmployee

/* *************************************************************************************************************** */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee != NULL)
    {
        employee_mostrarTodosLosEmpleados(pArrayListEmployee);
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion controller_ListEmployee

/* *************************************************************************************************************** */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int criterio;

	do
	{
		printf( "\n    ***** MENÚ ORDENAR *****\n"
		            		"\n1. Por nombre."
		            		"\n2. Por ID."
		            		"\n3. Por sueldo."
		            		"\n4. Por horas trabajadas."
		            		"\n5. Salir.\n");
		get_ValidarInt(&opcion,"\nIngrese opción: ","ERROR.Ingresar números:","\nError, las opciones del menú van del 1 al 5. \nIngrese opción:",1,5);

		printf("\n * Criterio de ordenamiento: \n 1: ASCENDENTE \n 2: DESCENDENTE \n");
		get_ValidarInt(&criterio,"\nIngrese opción: ","ERROR.Ingresar números:","\nError, las opciones son 1 y 2. \nIngrese opción:",1,2);

		if(criterio == 1)
		{
			criterio = 1;
		}
		else
		{
			criterio = 0;
		}

		switch(opcion)
		{
			case 1:
				if(ll_sort(pArrayListEmployee, employee_compararPorNombre,criterio) == 0)
				{
					retorno = 1;
				}
				else
				{
					printf("\nERROR, no fue posible ordenar la lista por NOMBRE.\n");
				}
				return retorno;
			break;

			case 2:
				if(ll_sort(pArrayListEmployee, employee_compararPorId,criterio) == 0)
				{
					retorno = 1;
				}
				else
				{
					printf("\nERROR, no fue posible ordenar la lista por ID.\n");
				}
				return retorno;
			break;

			case 3:
				if( ll_sort(pArrayListEmployee,employee_compararPorSueldo,criterio) == 0)
				{
					retorno = 1;
				}
				else
				{
					printf("\nERROR, no fue posible ordenar la lista por SUELDO.\n");
				}
				return retorno;
			break;

			case 4:
				if(ll_sort(pArrayListEmployee, employee_compararPorHoras,criterio) == 0)
				{
					retorno = 1;
				}
				else
				{
					printf("\nERROR, no fue posible ordenar la lista por HORAS TRABAJADAS.\n");
				}
				return retorno;
			break;

			case 5:
				retorno = -1;
				return retorno;
			break;
		}//fin del switch
	}while(opcion != 5);

	return retorno;
}//fin funcion controller_sortEmployee

/* *************************************************************************************************************** */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"w");
    int retorno;
    int len;
    //ordenar por ID antes de guardar
    ll_sort(pArrayListEmployee, employee_compararPorId,1);

    len = ll_len(pArrayListEmployee);

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = guardarFormatoTexto(pArrayListEmployee, pFile, len);
    }//fin if
    return retorno;
}//fin funcion controller_saveAsText

/* *************************************************************************************************************** */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"wb");
    Employee* empleado;
    int len;
    int retorno = 0;
    int i;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	//ordenar por ID antes de guardar
    	ll_sort(pArrayListEmployee, employee_compararPorId,1);

        len = ll_len(pArrayListEmployee);

        for(i = 0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fwrite(empleado, sizeof(Employee), 1, pFile);
        }
        fclose(pFile);
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion controller_saveAsBinary


