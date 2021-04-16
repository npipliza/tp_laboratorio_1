/*
 ============================================================================
 Trabajo Practico : 1
 Division         : 1ro C
 Alumna           : Pipliza Nadia
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
 4. Informar resultados
	a) El resultado de A+B es: r
	b) El resultado de A-B es: r
	c) El resultado de A/B es: r o No es posible dividir por cero
	d) El resultado de A*B es: r
	e) El factorial de A es: r1 y El factorial de B es: r2
 5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BibliotecaTP1.h"

 /**
 * @fn int main(void)
 * @brief esta funcion es un menu que solicita los numeros al usuario, para hacer las operaciones matematicas.
 * pasa los parametros a biblioteca.c donde estan las funciones correspondientes.
 *
 * @return 0
 */
int main(void)
{
	setbuf(stdout, NULL);
	int   case3   = 0;
	float numero1 = 0;
	float numero2 = 0;
	int   numerosIngresados = 1;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int   factorizado1;
	int   factorizado2;

	do
	{
		printf("\n         - CALCULADORA - \nElija una opción del menú para continuar: ");
	    printf("\nOprima 1: Ingresar 1er operando.\nOprima 2: Ingresar 2do operando.\nOprima 3: Calcular todas las operaciones.\nOprima 4: Informar resultados.\nOprima 5: Salir.\n");
		scanf("%d", &numerosIngresados);

		while(numerosIngresados != 1 && numerosIngresados != 2 && numerosIngresados != 3 && numerosIngresados != 4 && numerosIngresados != 5)
		{
			printf("\nERROR: \nOprima 1: Ingresar 1er operando.\nOprima 2: Ingresar 2do operando.\nOprima 3: Calcular todas las operaciones.\nOprima 4: Informar resultados.\nOprima 5: Salir.\n");
			scanf("%d", &numerosIngresados);
		}

		switch(numerosIngresados)
		{
			case 1:
				printf("\nIngresar 1er operando: \n");
				scanf("%f", &numero1);
			break;

			case 2:
				if(isnan(numero1) == 0)
				{
					printf("\nIngresar 2do operando: \n");
					scanf("%f", &numero2);
				}
				else
				{
					printf("\nERROR, primero ingresar 1er operando. Presione una tecla para continuar. \n");
					scanf("%f", &numero1);
				}
			break;

			case 3:
				if(isnan(numero1) == 0 && isnan(numero2) == 0)
				{
					printf("\nCalculando todas las operaciones..... \n");

					suma           = sumar(numero1, numero2);
					resta          = restar(numero1, numero2);
					division       = dividir(numero1, numero2);
					multiplicacion = multiplicar(numero1, numero2);
					factorizado1   = factorial1(numero1);
					factorizado2   = factorial2(numero2);

					printf("\nPresione 4 para ver los resultados. \n");

					case3 = 1;
				}
				else
				{
					printf("\nPrimero ingrese los operando para continuar. \n");
				}

			break;

			case 4:
				if(case3 == 1)
				{
					printf("El resultado de %f + %f es: %f\n",numero1, numero2, suma);
					printf("El resultado de %f - %f es: %f\n",numero1, numero2, resta);
					if(numero2 != 0)
					{
						printf("El resultado de %f / %f es: %f\n",numero1, numero2, division);
					}
					else
					{
						printf("No es posible dividir por cero\n");
					}
					printf("El resultado de %f * %f es: %f\n",numero1, numero2, multiplicacion);
					printf("El factorial de %f es: %d y El factorial de %f es: %d \n",numero1, factorizado1, numero2, factorizado2);
				}
				else
				{
					printf("\nPrimero debe ingresar opción 3 para continuar. \n");
				}
			break;

			case 5:
				printf("\n ¡GRACIAS POR USAR NUESTRO PROGRAMA!\n");
			break;
		}

	}while(numerosIngresados != 5);

	return 0;

}
