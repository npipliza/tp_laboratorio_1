#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	char idAux[128];
	char nombreAux[128];
	char horasTrabajadasAux[128];
	char sueldoAux[128];
	int  retorno = 0;

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
			empleado = employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
			ll_add(pArrayListEmployee,empleado);
		}while(!feof(pFile));
		retorno = 1;
	}//fin if NULL
	return retorno;
}//fin funcion parser_EmployeeFromText

/* ********************************************************************************************** */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int retorno = 0;

	if(pFile != NULL)
	{
		ll_clear(pArrayListEmployee);

		do
		{
			empleado = employee_new();

			if((fread(empleado,sizeof(Employee),1,pFile)) == 1)
			{
				ll_add(pArrayListEmployee,empleado);
			}
		}while(!feof(pFile));
		retorno = 1;
	}//fin if NULL
	return retorno;
}//fin funcion parser_EmployeeFromBinary
