#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);

    printf("\n*********************************************************************************"
           "\n\t\t\tINICIO DEL PROGRAMA"
           "\n*********************************************************************************\n");

    int option       = 0;
    int option1      = 0;
    int noGuardoT    = 0;
    int noGuardoB    = 0;
    int cargoAMB     = 0;
    int cargoTexto   = 0;
    int cargoBinario = 0;
    int contains;

    LinkedList* listaEmpleados                = ll_newLinkedList();
    LinkedList* listaEmpleadosBackUp          = ll_newLinkedList();
    LinkedList* listaEmpleadossueldosMasAltos = ll_newLinkedList();
	LinkedList* listaEmpleadosTop             = ll_newLinkedList();

    if(listaEmpleados != NULL)
    {
        do
        {
            printf( "\n    ***** MENÚ PRINCIPAL *****\n"
            		"\n1.  Cargar datos (modo texto)."
            		"\n2.  Cargar datos (modo binario)."
            		"\n3.  Alta."
            		"\n4.  Modificar datos."
            		"\n5.  Baja."
            		"\n6.  Listar."
            		"\n7.  Ordenar."
            		"\n8.  Guardar datos (modo texto)."
            		"\n9.  Guardar datos (modo binario)."
            		"\n10. Clonar lista."
            		"\n11. Informes."
            		"\n12. Salir.\n");

            get_ValidarInt(&option,"\nIngrese opción: ","ERROR.Ingresar números:","\nError, las opciones del menú van del 0 al 10. \nIngrese opción:",1,12);

            switch(option)
            {
            	//CARGAR ARCHIVO MODO TEXTO
                case 1:
                    if(controller_loadFromText("data.csv", listaEmpleados))
                    {
                    	cargoTexto = 1;
                        printf("\nDatos cargados en MODO TEXTO exitosamente.\n");
                    }
                    else
                    {
                    	printf("\nNo fue posible cargar los datos en MODO TEXTO.\n");
                    }
                    system("pause");
                break;

                //CARGAR ARCHIVO MODO BINARIO
                case 2:
                	if(ll_isEmpty(listaEmpleados) == 0)
					{

						if(controller_loadFromBinary("data.bin",listaEmpleados) == 1)
						{
							cargoBinario = 1;
							printf("\nDatos cargados en MODO BINARIO exitosamente.\n");
						}
						else
						{
							printf("\nNo fue posible cargar los datos en MODO BINARIO.\n");
						}
					}
                	else
					{
						 printf("\nPrimero debe cargar la base de empleados (Opción 1).\n");
					}
					system("pause");
                break;

                //ALTA EMPLEADOS
                case 3:
                	if(ll_isEmpty(listaEmpleados) == 0)
                	{
						if(controller_addEmployee(listaEmpleados))
						{
							printf("\nEmpleado cargado exitosamente.\n");
							cargoAMB = 1;
						}
						else
						{
							 printf("\nNo fue posible cargar empleado.\n");
						}
                	}
					else
					{
						 printf("\nPrimero debe cargar la base de empleados (Opción 1 ó 2).\n");
					}
					system("pause");
                break;

                //MODIFICAR EMPLEADOS
                case 4:
                    if(ll_isEmpty(listaEmpleados) == 0)
                    {
                        controller_ListEmployee(listaEmpleados);

                        if(controller_editEmployee(listaEmpleados) == 1)
                        {
                            printf("\nEmpleado modificado exitosamente.\n");
                            cargoAMB = 1;
                        }
                        else
                        {
                            printf("\nNo fue posible modificar empleado.\n");
                        }
                    }
                    else
                    {
                         printf("\nNo hay empleados cargados.\n");
                    }
                    system("pause");
                break;

                //BAJA EMPLEADOS
                case 5:
                     if(ll_isEmpty(listaEmpleados) == 0)
                     {
                        controller_ListEmployee(listaEmpleados);

                        if(controller_removeEmployee(listaEmpleados))
                        {
                            printf("\nEmpleado eliminado exitosamente.\n");
                            cargoAMB = 1;
                        }
                        else
                        {
                            printf("\nNo fue posible eliminar empleado.\n");
                        }
                     }
                     else
                     {
                         printf("\nNo hay empleados cargados.\n");
                     }
                     system("pause");
                break;

                //LISTAR EMPLEADOS
                case 6:
                    if(ll_isEmpty(listaEmpleados) == 0)
                    {
                        if(controller_ListEmployee(listaEmpleados) != 1)
                        {
                            printf("\nNo fue posible cargar la lista.\n");
                        }
                    }
                    else
                    {
                        printf("\nNo hay empleados cargados.\n");
                    }
                    system("pause");
                break;

                //ORDENAR EMPLEADOS(NOMBRE/ID/HORAS/SUELDO)
                case 7:
                    if(ll_isEmpty(listaEmpleados) == 0)
                    {
                        if(controller_sortEmployee(listaEmpleados) == 1)//ll_sort llama a ll_set
                        {
                            printf("\nLista ordenada exitosamente.\n");
                    		controller_ListEmployee(listaEmpleados);
                        }
                        else
                        {
                             printf("\nNo fue posible ordenar la lista.\n");
                        }
                    }
                    else
                    {
                         printf("\nNo hay empleados cargados.\n");
                    }
                    system("pause");
                break;

                //GUARDAR MODO TEXTO
                case 8:
                	noGuardoT = 1;
                    if(ll_isEmpty(listaEmpleados) == 0)
                    {
                        if(controller_saveAsText("data.csv",listaEmpleados))
                        {
                            printf("\nDatos guardados exitosamente en MODO TEXTO.\n");
                        }
                        else
                        {
                            printf("\nNo fue posible cargar los datos en MODO TEXTO.\n");
                        }
                    }
                    else
                    {
                         printf("\nNo hay empleados cargados.\n");
                    }
                    system("pause");
                break;

                //GUARDAR MODO BINARIO
                case 9:
                	noGuardoB = 1;
                    if(ll_isEmpty(listaEmpleados) == 0)
                    {
                        if(controller_saveAsBinary("data.bin",listaEmpleados))
                        {
                        	printf("\nDatos guardados exitosamente en MODO BINARIO.\n");
                        }
                        else
                        {
                        	printf("\nNo fue posible cargar los datos en MODO BINARIO.\n");
                        }
                    }
                    else
                    {
                         printf("\nNo hay empleados cargados.\n");
                    }
                    system("pause");
                break;

                //CLONAR LISTA
                case 10:
                    if(ll_isEmpty(listaEmpleados) == 0)
                    {
                    	listaEmpleadosBackUp = ll_clone(listaEmpleados);//ll_clone llama a ll_sublist
                        if(controller_saveAsText("DataBackUp.csv",listaEmpleadosBackUp))
                        {
                        	printf("\nLista CLONADA exitosamente.\n");
                        }
                        else
                        {
                        	printf("\nNo fue posible CLONAR la lista.\n");
                        }
                    }
                    else
                    {
                         printf("\nNo hay empleados cargados.\n");
                    }
                    system("pause");
                break;

                //CONTAINS
                case 11:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						printf("\t ***** TOP 10 SUELDOS MAS ALTOS *****\n");

						listaEmpleadossueldosMasAltos = sueldosMasAltos(listaEmpleados);
						employee_mostrarTodosLosEmpleados(listaEmpleadossueldosMasAltos);
						contains = ll_containsAll(listaEmpleadosTop,listaEmpleadossueldosMasAltos);

						if(contains == -1)
						{
							printf("No fue posible comprobar el ranking.\n");
						}
						else
						{
							if(!contains)
							{
								printf("ATENCIÓN! Existen más empleados por fuera el TOP 10 con estos sueldos.\n");
							}
							else
							{
								printf("Se muestran todos los empleados con mayor sueldo.\n");
							}
						}
					}
					else
					{
						printf("\nNo hay empleados cargados.\n");
					}
				break;
                //REVISAR CAMBIOS Y SALIR
                case 12:
                	if(cargoAMB == 1 && (noGuardoT == 0 || noGuardoB == 0))
                	{
						get_ValidarInt(&option1,"\nATENCIÓN, se va a finalizar el programa sin haber guardado los cambios. \nIngrese:\n1- Guardar y salir.\n2- Salir sin guardar. ","ERROR.Ingresar números:","\nError, las opciones del menú son 1 y 2. \nIngrese:\n1- Guardar y salir.\n2- Salir sin guardar.",1,2);
						switch(option1)
						{
						     case 1:
						    	 if(noGuardoT == 0 && cargoTexto == 1)
						    	 {
									 controller_saveAsText("data.csv",listaEmpleados);
									 printf("Datos guardados exitosamente en MODO TEXTO.\n");
						    	 }

						    	 if(noGuardoB == 0 && cargoBinario == 1)
						    	 {
									 printf("Datos guardados exitosamente en MODO BINARIO.\n");
									 controller_saveAsBinary("data.bin",listaEmpleados);
						    	 }
								 option = 0;
							 break;

							 case 2:
								 option = 0;
							 break;
						}
                	}
                	else
                	{
                		option = 0;
                	}
                break;
			}//fin switch option
        }while(option != 12);

        printf("\n*********************************************************************************"
               "\n\t\t\tPROGRAMA FINALIZADO"
               "\n*********************************************************************************\n");
    }//fin if NULL (listaEmpleados)
    else
    {
        printf("ERROR. No ha sido posible cargar la lista en memoria.");
    }
    return 0;
}//fin funcion main
