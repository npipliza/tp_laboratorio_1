#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idAux,char* nombreAux,char* horasTrabajadasAux,char* sueldoAux);

void employee_delete();//hacer funcion recibe puntero empleado y free (liberar memoria y array)

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/*****/
void employee_mostrarUnEmpleado(Employee* empleado);
int  employee_compararPorSueldo(void* , void* );
int  employee_compararPorHoras(void* , void*);
int  employee_compararPorId(void* , void*);
int  employee_compararPorNombre(void* e1, void* e2);

/** \brief Imprime todos los empleados que contiene el LinkedList*
 *
 * \param pListEmployee LinkedList*
 * \return void
 *
 */void employee_mostrarTodosLosEmpleados(LinkedList* );

/** \brief Pide el id que se desea eliminar, verifica que existe y retorna el index de ese id
 *
 * \param pListEmployee LinkedList*
 * \return int index del id a eliminar
 *
 */int employee_darIDdeBaja(LinkedList* );

/** \brief Pide un id al usuario, verifica que exista, muestra mensajes de error en caso de que no y devuelve el indice del ID buscado
 *
 * \param pListEmployee LinkedList*
 * \param msj[] char Mensaje solicitando el id
 * \param emsj1[] char Mensaje en caso de que se ingresen letras
 * \param emsj2[] char Mensaje en caso de que se ingrese un numero fuera del rango
 * \param int* Parametro de salida, puntero al indexID
 * \return void
 *
 */void employee_modificarDatos(LinkedList* , char [],char [],char [],int*);

int employee_buscarPorID(LinkedList* pListEmployee,int idIngresado, int*);

/** \brief Genera un nuevo empleado a partir de los datos ingresados por el asuario
 *
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna [1] si se pudo generar un nuevo empleado [0] en caso de que no
 *
 */
int employee_cargarEmpleado(LinkedList* pArrayListEmployee);


/** \brief Busca el valor del mayor id generado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int El valor de ese id
 *
 */int employee_ultimoID(LinkedList* pArrayListEmployee);


/** \brief Genera el valor de un nuevo id
 *
 * \param LinkedList* pArrayListEmployee
 * \param puntero a id, parametro de salida
 * \return
 *
 */void employee_calculaNuevoID(LinkedList* pArrayListEmployee,int* id);

/** \brief Modifica campos de una entidad de acuerdo a la opcion elegida por el usuario
 *
 * \param empleado Employee*
 * \param opcion int El numero de la opcion elegida por el usuario
 * \return int Retorna [1] si se pudo realizar la modificacion [0] en caso de que no
 *
 */int employee_modificaEmpleado(Employee* empleado, int opcion);

/** \brief Recorre la lista, obtiene los valores de sus campos y los imprime en un archivo
 *
 * \param pArrayListEmployee LinkedList*
 * \param pFile FILE*
 * \param len int la longitud de la lista
 * \return int Retorna [1] si se pudo escribir el archivo [0] en caso de que no
 *
 */
int guardarFormatoTexto(LinkedList* pArrayListEmployee, FILE* pFile, int len);

#endif // employee_H_INCLUDED
