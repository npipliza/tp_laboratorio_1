#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}//fin funcion Employee_new

/* ****************************************************************************************************** */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado = employee_new();
    int  id;
    char nombre[128];
    int  horasTrabajadas;
    int  sueldo;

    id              = atoi(idStr);
    strcpy(nombre,nombreStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo          = atof(sueldoStr);

    if(pEmpleado != NULL)
    {
        if(employee_setId(pEmpleado,id))
        {
            if(employee_setNombre(pEmpleado,nombre))
            {
                if(employee_setHorasTrabajadas(pEmpleado,horasTrabajadas))
                {
                   employee_setSueldo(pEmpleado,sueldo);
                }//fin if employee_setHorasTrabajadas
            }//fin if employee_setNombre
        }//fin if employee_setId
    }//fin if NULL
    return pEmpleado;
}//fin funcion employee_newParametros

/* ********************************************************************************** */
int employee_setNombre(Employee* this, char* nombre)
{
    int setteo = 0;

    if(this != NULL && nombre != NULL)
    {
        if( validarNombre(nombre,50))
        {
           strcpy(this->nombre, nombre);
           setteo = 1;
        }//fin if validarNombre
    }//fin if NULL
    return setteo;
}//fin funcion employee_setNombre

/* ********************************************************************************** */
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion employee_getNombre

/* ********************************************************************************** */
int employee_setId(Employee* this, int id)
{
    int setteo = 0;

    if(this != NULL && id >= 0)
    {
        setteo = 1;
        this->id = id;
    }//fin if NULL
    return setteo;
}//fin funcion employee_setId

/* ********************************************************************************** */
int employee_getId(Employee* this, int* id)
{
    int retorno = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion employee_getId

/* ********************************************************************************** */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setteo = 0;

    if(this != NULL && horasTrabajadas >= 0 && horasTrabajadas < 400)
    {
        this->horasTrabajadas = horasTrabajadas;
        setteo = 1;
    }//fin if NULL
    return setteo;
}//fin funcion employee_setHorasTrabajadas

/* ********************************************************************************** */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion employee_getHorasTrabajadas

/* ********************************************************************************** */
int employee_setSueldo(Employee* this, int sueldo)
{
    int setteo = 0;

    if(this != NULL && sueldo < 100000)
    {
        this->sueldo = sueldo;
        setteo = 1;
    }//fin if NULL
    return setteo;
}//fin funcion employee_setSueldo

/* ********************************************************************************** */
int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion employee_getSueldo

/* ********************************************************************************** */
int employee_CompareBySueldo(void* e1, void* e2)
{
    Employee* empleado1;
    Employee* empleado2;
    int sueldo1;
    int sueldo2;
    int retorno = 0;

    empleado1 = (Employee*)e1;
    empleado2 = (Employee*)e2;

    employee_getSueldo(empleado1, &sueldo1);
    employee_getSueldo(empleado2, &sueldo2);

    if(sueldo1 > sueldo2)
    {
        retorno = 1;
    }
    else
    {
        if(sueldo1 < sueldo2)
        {
            retorno = -1;
        }
    }//fin if compara/ordena
    return retorno;
}//fin funcion employee_CompareBySueldo

/* ********************************************************************************** */
int employee_CompareByHoras(void* e1, void* e2)
{
    Employee* empleado1;
    Employee* empleado2;
    int horas1;
    int horas2;
    int retorno = 0;

    empleado1 = (Employee*)e1;
    empleado2 = (Employee*)e2;

    if(employee_getHorasTrabajadas(empleado1, &horas1) == 1 && employee_getHorasTrabajadas(empleado2, &horas2) == 1)
    {
        if(horas1 > horas2)
        {
            retorno = 1;
        }
        else
        {
            if(horas1 < horas2)
            {
                retorno = -1;
            }
        }
    }//fin if compara/ordena
    return retorno;
}//fin funcion employee_CompareByHoras

/* ********************************************************************************** */
int employee_CompareByNombre(void* e1, void* e2)
{
    int compara;
    Employee* empleado1;
    Employee* empleado2;
    char nombre1[128];
    char nombre2[128];

    empleado1 = (Employee*)e1;
    empleado2 = (Employee*)e2;

    employee_getNombre(empleado1, nombre1);
    employee_getNombre(empleado2, nombre2);

    compara = strcmp(empleado1->nombre, empleado2->nombre);

    return compara;
}//fin funcion employee_CompareByNombre

/* ********************************************************************************** */
int employee_CompareById(void* e1, void* e2)
{
    Employee* empleado1;
    Employee* empleado2;
    int id1;
    int id2;
    int retorno = 0;

    empleado1 = (Employee*)e1;
    empleado2 = (Employee*)e2;
    employee_getId(empleado1, &id1);
    employee_getId(empleado2, &id2);

    if(id1 > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id1 < id2)
        {
            retorno = -1;
        }
    }//fin if compara/ordena
    return retorno;
}//fin funcion employee_CompareById

/* ********************************************************************************** */
void employee_mostrarUnEmpleado(Employee* empleado)
{
    int  id;
    char nombre[128];
    int  horasTrabajadas;
    int  sueldo;

    employee_getId(empleado, &id);
    employee_getNombre(empleado, nombre);
    employee_getHorasTrabajadas(empleado, &horasTrabajadas);
    employee_getSueldo(empleado, &sueldo);

    if(empleado != NULL)
    {
        printf("\t%d   %-11s %5d hs   $%2d\n", id, nombre, horasTrabajadas, sueldo);
    }//fin if NULL
}//fin funcion employee_mostrarUnEmpleado

/* ********************************************************************************** */
void employee_mostrarTodosLosEmpleados(LinkedList* pListEmployee)
{
    Employee* empleado;
    int lengthListEmployee = ll_len(pListEmployee);

    printf("\tID\tNOMBRE\tHORAS\tSALARIO\n");

    for(int i = 0; i < lengthListEmployee; i++)
    {
        empleado = (Employee*) ll_get(pListEmployee,i);
        employee_mostrarUnEmpleado(empleado);
    }//fin for len
}//fin funcion employee_mostrarTodosLosEmpleados

/* ********************************************************************************** */
int employee_darIDdeBaja(LinkedList* pListEmployee)
{
    int retorno = -1;
    int idIngresado;
    int indexIdAEliminar;
    int lengthListEmployee = ll_len(pListEmployee);

    get_ValidarInt(&idIngresado,"\nIngrese ID del empleado a dar de baja: ","\nERROR Ingrese un número: ","\ERROR.Ingrese un ID existente:",0,lengthListEmployee);
    employee_buscarPorID(pListEmployee,idIngresado,&indexIdAEliminar );
    if(indexIdAEliminar != -1)
    {
       retorno = indexIdAEliminar;
    }
    return retorno;
}//fin funcion employee_darIDdeBaja

/* ********************************************************************************** */
void employee_modificarDatos(LinkedList* pListEmployee, char msj[],char emsj1[],char emsj2[],int* indexId)
{
    int idIngresado;
    int lengthListEmployee = ll_len(pListEmployee);

    get_ValidarInt(&idIngresado,msj,emsj1,emsj2,0,lengthListEmployee);
    employee_buscarPorID(pListEmployee,idIngresado,indexId);
}//fin funcion employee_modificarDatos

/* ********************************************************************************** */
int employee_buscarPorID(LinkedList* pListEmployee,int idIngresado, int* indexIdBuscado)
{
    Employee* AuxEmpleado;
    int idAux;

    int retorno = 0;
    int lengthListEmployee = ll_len(pListEmployee);
    *indexIdBuscado = -1;

    for(int i = 0; i < lengthListEmployee; i++)
    {
        AuxEmpleado = (Employee*)ll_get(pListEmployee,i);
        employee_getId(AuxEmpleado,&idAux);
        if(idAux == idIngresado)
        {
            *indexIdBuscado = i;
            retorno = 1;
            break;
        }
    }//fin for len
    return retorno;
}//fin funcion employee_buscarPorID

/* ********************************************************************************************** */
int employee_cargarEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    char nombreIngresado[128] ;
    int horasIngresadas;
    int sueldoIngresado;
    int retorno = 0;
    int id;

    nuevoEmpleado = employee_new();

    pedirNombre("Ingrese nombre: ","Nombre inválido. Ingrese nombre: ",128,nombreIngresado);
    get_ValidarInt(&horasIngresadas,"Ingrese horas trabajadas: ","ERROR, no se admiten letras. Ingrese horas trabajadas: ","ERROR. Rango entre 0 y 400hs. Ingrese horas trabajadas: ",0,400);
    get_ValidarInt(&sueldoIngresado,"Ingrese sueldo: ","ERROR, no se admiten letras. Ingrese sueldo: ","ERROR. Rango entre 0 y 100000. Ingrese sueldo: ",0,100000);
    employee_calculaNuevoID(pArrayListEmployee, &id);

    if(nuevoEmpleado != NULL)
    {
        employee_setNombre(nuevoEmpleado,nombreIngresado);
        employee_setHorasTrabajadas(nuevoEmpleado,horasIngresadas);
        employee_setSueldo(nuevoEmpleado,sueldoIngresado);
        employee_setId(nuevoEmpleado,id);

        ll_add(pArrayListEmployee,nuevoEmpleado);
        retorno = 1;
    }//fin if NULL
    return retorno;
}//fin funcion employee_cargarEmpleado

/* ********************************************************************************** */
int employee_ultimoID(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int IdAux;
    int IdMax = 0;
    int lengthListEmployee = ll_len(pArrayListEmployee);

    for(int i = 0 ; i < lengthListEmployee; i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        if(pEmployee != NULL)
        {
            employee_getId(pEmployee, &IdAux);
            if(IdAux > IdMax)
            {
                IdMax = IdAux;
            }//fin if compara id
        }//fin if NULL
    }//fin for len
    return IdMax;
}//fin funcion employee_ultimoID

/* ********************************************************************************** */
void employee_calculaNuevoID(LinkedList* pArrayListEmployee,int* id)
{
    *id = employee_ultimoID(pArrayListEmployee)+1;
}//fin funcion employee_calculaNuevoID

/* ********************************************************************************** */
int employee_modificaEmpleado(Employee* empleado, int opcion)
{
    char nombreModificado[128];
    int horasModificadas;
    int sueldoModificado;
    int retorno = 0;

	switch(opcion)
	{
		case 1:
			pedirNombre("\nIngrese nombre a modificar: ","Nombre inválido. Ingrese nombre a modificar: ",128,nombreModificado);

			if(employee_setNombre(empleado, nombreModificado))
			{
				retorno = 1;
			}
		break;

		case 2:
			get_ValidarInt(&horasModificadas,"\nIngrese horas trabajadas a modificar: ","ERROR, no se admiten letras. Ingrese horas trabajadas a modificar: ","ERROR. Rango entre 0 y 400hs. Ingrese horas trabajadas a modificar: ",0,400);

			if(employee_setHorasTrabajadas(empleado, horasModificadas))
			{
				retorno = 1;
			}
		break;

		case 3:
			get_ValidarInt(&sueldoModificado,"\nIngrese sueldo a modificar: ","ERROR, no se admiten letras. Ingrese sueldo a modificar: ","ERROR. Rango entre 0 y 100000. Ingrese sueldo a modificar: ",0,100000);

			if(employee_setSueldo(empleado, sueldoModificado))
			{
				retorno = 1;
			}
		break;
	 }//fin switch opcion
     return retorno;
}//fin cuncion employee_modificaEmpleado

/* ********************************************************************************** */
int guardarFormatoTexto(LinkedList* pArrayListEmployee, FILE* pFile, int len)
{
    Employee* empleado;
    int  retorno = 0;
    int  id;
    char nombre[128];
    int  horasTrabajadas;
    int  sueldo;
    int i;

    fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

    for(i = 0; i < len; i++)
    {
        empleado = ll_get(pArrayListEmployee,i);
        employee_getId(empleado,&id);
        employee_getNombre(empleado,nombre);
        employee_getHorasTrabajadas(empleado,&horasTrabajadas);
        employee_getSueldo(empleado,&sueldo);
        fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        retorno = 1;
    }//fin for len
    fclose(pFile);

    return retorno;
}//fin funcion guardarFormatoTexto
